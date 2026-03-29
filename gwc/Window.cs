//
// :.:.:.
// GWC
// v0.2.0
// :.:.:.
//
// https://github.com/reallukee/gwc
//
// Window.cs
//  Licenza MIT
//

using System;
using System.Collections;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.ComponentModel;
using System.Diagnostics;
using System.Globalization;
using System.Reflection;
using System.Resources;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading;

using System.Drawing;
using System.Windows.Forms;

namespace Reallukee.GWC
{
    public sealed class Window : IDisposable
    {
        public Window(int width, int height)
        {
            if (width <= 0)
            {
                throw new ArgumentOutOfRangeException(nameof(width), "");
            }

            if (height <= 0)
            {
                throw new ArgumentOutOfRangeException(nameof(height), "");
            }

            InitWindow(width, height);

            InitRender(width, height);
        }

        public Window() : this(800, 600) {}

        ~Window()
        {
            Dispose();
        }

        public void Dispose()
        {
            if (canvas != null)
            {
                canvas.Dispose();
            }
        }



        private WindowForm    window;
        private Canvas        canvas;

        private Thread        windowThread;
        private volatile bool windowThreadFlag;
        object                windowLock;

        private Thread        renderThread;
        private volatile bool renderThreadFlag;
        object                renderLock;

        private void InitWindow(int width, int height)
        {
            window = new WindowForm();

            window.Text        = $"{Application.ProductName} {Application.ProductVersion}";
            window.Icon        = Properties.Resources.AppIcon;
            window.MinimumSize = new Size(0, 0);
            window.MaximumSize = new Size(0, 0);
            window.Size        = new Size(width, height);
            window.ClientSize  = new Size(width, height);

            window.Paint  += WindowForm_Paint;
            window.Resize += WindowForm_Resize;

            window.KeyDown   += WindowForm_KeyDown;
            window.KeyUp     += WindowForm_KeyUp;
            window.MouseDown += WindowForm_MouseDown;
            window.MouseUp   += WindowForm_MouseUp;

            keyDownEvent   = new AutoResetEvent(false);
            keyUpEvent     = new AutoResetEvent(false);
            mouseDownEvent = new AutoResetEvent(false);
            mouseUpEvent   = new AutoResetEvent(false);

            windowThread = new Thread(WindowThreadLoop);

            windowLock = new object();
        }

        private void InitRender(int width, int height)
        {
            canvas = new Canvas(width, height);

            canvas.BorderColor = Color.Black;
            canvas.FillColor   = Color.Red;

            renderThread = new Thread(RenderThreadLoop)
            {
                IsBackground = true
            };

            renderLock = new object();
        }



        private void WindowThreadLoop()
        {
            Application.EnableVisualStyles();

            Application.SetCompatibleTextRenderingDefault(false);

            while (window == null)
            {
                Thread.Sleep(100);
            }

            Application.Run(window);
        }

        private void RenderThreadLoop()
        {
            Stopwatch renderStopwatch = new Stopwatch();

            while (renderThreadFlag)
            {
                double renderElapsedTime = 0;

                double renderRemainingTime = 0;

                if (window.IsHandleCreated && !canvas.Buffer.IsEmpty)
                {
                    lock (renderLock)
                    {
                        try
                        {
                            renderStopwatch.Restart();

                            using (Graphics g = Graphics.FromImage(canvas.Bitmap))
                            {
                                while (canvas.Buffer.TryDequeue(out IFigure figure))
                                {
                                    figure.Render(g);

                                    if (renderStopwatch.Elapsed.TotalMilliseconds > Render.UtilFrameTime)
                                    {
                                        break;
                                    }
                                }
                            }

                            renderStopwatch.Stop();

                            renderElapsedTime = renderStopwatch.Elapsed.TotalMilliseconds;
                        }
                        catch (Exception ex)
                        {
                            MessageBox.Show(
                                ex.Message,
                                $"{Application.ProductName} {Application.ProductVersion}",
                                MessageBoxButtons.OK,
                                MessageBoxIcon.Error
                            );
                        }
                    }

                    window.BeginInvoke((Action)(() => {
                        window.Invalidate();

                        window.Update();
                    }));
                }

                renderRemainingTime = Render.FrameTime - renderElapsedTime;

                if (renderRemainingTime > 0)
                {
                    Thread.Sleep((int)renderRemainingTime);
                }
            }
        }



        private void WindowForm_Paint(object sender, PaintEventArgs e)
        {
            if (window.ClientSize.Width <= 0 || window.ClientSize.Height <= 0)
            {
                return;
            }

            lock (renderLock)
            {
                try
                {
                    e.Graphics.DrawImage(canvas.Bitmap, 0, 0);
                }
                catch (Exception ex)
                {
                    MessageBox.Show(
                        ex.Message,
                        $"{Application.ProductName} {Application.ProductVersion}",
                        MessageBoxButtons.OK,
                        MessageBoxIcon.Error
                    );
                }
            }
        }

        private void WindowForm_Resize(object sender, EventArgs e)
        {
            if (window.ClientSize.Width <= 0 || window.ClientSize.Height <= 0)
            {
                return;
            }

            lock (renderLock)
            {
                try
                {
                    if (canvas.Bitmap.Width < window.ClientSize.Width || canvas.Bitmap.Height < window.ClientSize.Height)
                    {
                        Canvas oldCanvas = canvas;

                        Canvas newCanvas = new Canvas(window.ClientSize.Width, window.ClientSize.Height);

                        using (Graphics g = Graphics.FromImage(newCanvas.Bitmap))
                        {
                            g.DrawImage(oldCanvas.Bitmap, 0, 0);
                        }

                        canvas = newCanvas;

                        oldCanvas.Dispose();
                    }
                }
                catch (Exception ex)
                {
                    MessageBox.Show(
                        ex.Message,
                        $"{Application.ProductName} {Application.ProductVersion}",
                        MessageBoxButtons.OK,
                        MessageBoxIcon.Error
                    );
                }
            }
        }



        public void Wait(int milliseconds)
        {
            Thread.Sleep(milliseconds);
        }



        public bool Open()
        {
            if (windowThread.IsAlive || renderThread.IsAlive)
            {
                return false;
            }

            windowThreadFlag = true;
            renderThreadFlag = true;

            windowThread.Start();
            renderThread.Start();

            while (!window.IsHandleCreated)
            {
                Thread.Sleep(100);
            }

            return true;
        }

        public bool Shutdown()
        {
            if (!windowThread.IsAlive || !renderThread.IsAlive)
            {
                return false;
            }

            if (!window.IsHandleCreated)
            {
                return false;
            }

            windowThreadFlag = false;
            renderThreadFlag = false;

            windowThread.Join(100);
            renderThread.Join(100);

            Application.Exit();

            return true;
        }

        public bool IsOpen
        {
           get => window.IsHandleCreated;
        }

        public bool IsShutdown
        {
            get => !window.IsHandleCreated;
        }



        private AutoResetEvent keyDownEvent;
        private AutoResetEvent keyUpEvent;

        private int hasKeyDown = 0;
        private int hasKeyUp   = 0;

        private void WindowForm_KeyDown(object sender, KeyEventArgs e)
        {
            LastKeyDown = e.KeyValue;

            Interlocked.Exchange(ref hasKeyDown, 1);

            keyDownEvent.Set();
        }

        private void WindowForm_KeyUp(object sender, KeyEventArgs e)
        {
            LastKeyUp = e.KeyValue;

            Interlocked.Exchange(ref hasKeyUp, 1);

            keyUpEvent.Set();
        }

        private int lastKeyDown = -1;

        public int LastKeyDown
        {
            get         => lastKeyDown;
            private set => lastKeyDown = value;
        }

        private int lastKeyUp = -1;

        public int LastKeyUp
        {
            get         => lastKeyUp;
            private set => lastKeyUp = value;
        }

        public bool IsKeyDownAvailable => hasKeyDown == 1;
        public bool IsKeyUpAvailable   => hasKeyUp   == 1;

        public void ResetKeyDown() => LastKeyDown = -1;
        public void ResetKeyUp  () => LastKeyUp   = -1;

        public bool ConsumeKeyDown(out int key)
        {
            if (Interlocked.Exchange(ref hasKeyDown, 0) == 1)
            {
                key = lastKeyDown;

                return true;
            }

            key = -1;

            return false;
        }

        public bool ConsumeKeyUp(out int key)
        {
            if (Interlocked.Exchange(ref hasKeyUp, 0) == 1)
            {
                key = LastKeyUp;

                return true;
            }

            key = -1;

            return false;
        }

        public bool DiscardKeyDown() => ConsumeKeyDown(out int keys);
        public bool DiscardKeyUp  () => ConsumeKeyUp  (out int keys);

        public void WaitKeyDown() => keyDownEvent.WaitOne();
        public void WaitKeyUp  () => keyUpEvent  .WaitOne();



        private AutoResetEvent mouseDownEvent;
        private AutoResetEvent mouseUpEvent;

        private int hasMouseDown = 0;
        private int hasMouseUp   = 0;

        private void WindowForm_MouseDown(object sender, MouseEventArgs e)
        {
            LastMouseDownLocation = new Point(e.X, e.Y);
            LastMouseDownButton   = (int)e.Button;

            Interlocked.Exchange(ref hasMouseDown, 1);

            mouseDownEvent.Set();
        }

        private void WindowForm_MouseUp(object sender, MouseEventArgs e)
        {
            LastMouseUpLocation = new Point(e.X, e.Y);
            LastMouseUpButton   = (int)e.Button;

            Interlocked.Exchange(ref hasMouseUp, 1);

            mouseUpEvent.Set();
        }

        private Point lastMouseDownLocation;

        public Point LastMouseDownLocation
        {
            get         => lastMouseDownLocation;
            private set => lastMouseDownLocation = value;
        }

        private int lastMouseDownButton = -1;

        public int LastMouseDownButton
        {
            get         => lastMouseDownButton;
            private set => lastMouseDownButton = value;
        }

        private Point lastMouseUpLocation;

        public Point LastMouseUpLocation
        {
            get         => lastMouseUpLocation;
            private set => lastMouseUpLocation = value;
        }

        private int lastMouseUpButton = -1;

        public int LastMouseUpButton
        {
            get         => lastMouseUpButton;
            private set => lastMouseUpButton = value;
        }

        public bool IsMouseDownAvailable => lastMouseDownButton != -1;
        public bool IsMouseUpAvailable   => lastMouseUpButton   != -1;

        public void ResetMouseDown()
        {
            LastMouseDownLocation = new Point(-1, -1);
            LastMouseDownButton   = -1;
        }

        public void ResetMouseUp()
        {
            LastMouseUpLocation = new Point(-1, -1);
            LastMouseUpButton   = -1;
        }

        public bool ConsumeMouseDown(out Point location, out int button)
        {
            if (Interlocked.Exchange(ref hasMouseDown, 0) == 1)
            {
                location = LastMouseDownLocation;
                button   = LastMouseDownButton;

                return true;
            }

            location = new Point(-1, -1);
            button   = -1;

            return false;
        }

        public bool ConsumeMouseUp(out Point location, out int button)
        {
            if (Interlocked.Exchange(ref hasMouseUp, 0) == 1)
            {
                location = LastMouseUpLocation;
                button   = LastMouseUpButton;

                return true;
            }

            location = new Point(-1, -1);
            button   = -1;

            return false;
        }

        public void WaitMouseDown() => mouseDownEvent.WaitOne();
        public void WaitMouseUp()   => mouseUpEvent.  WaitOne();



        public Color BorderColor
        {
            get => canvas.BorderColor;
            set => canvas.BorderColor = value;
        }

        public Color FillColor
        {
            get => canvas.FillColor;
            set => canvas.FillColor = value;
        }

        public bool DrawFigure(IFigure figure) => canvas.DrawFigure(figure);

        public bool DrawBorderSquare(int x, int y, int side) => canvas.DrawBorderSquare(x, y, side);
        public bool DrawFillSquare  (int x, int y, int side) => canvas.DrawFillSquare  (x, y, side);
        public bool DrawBorderRectangle(int x, int y, int width, int height) => canvas.DrawBorderRectangle(x, y, width, height);
        public bool DrawFillRectangle  (int x, int y, int width, int height) => canvas.DrawFillRectangle  (x, y, width, height);
    }
}
