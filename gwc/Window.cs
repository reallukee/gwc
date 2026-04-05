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
                throw new ArgumentOutOfRangeException(nameof(width), "Width cannot be negative.");
            }

            if (height <= 0)
            {
                throw new ArgumentOutOfRangeException(nameof(height), "Height cannot be negative.");
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
            canvas?.Dispose();
        }



        private WindowForm    window;

        private Thread        windowThread;
        private volatile bool windowThreadFlag;
        private object        windowLock;

        private Canvas        canvas;

        private Thread        renderThread;
        private volatile bool renderThreadFlag;
        private object        renderLock;

        private void InitWindow(int width, int height)
        {
            window = new WindowForm();

            window.Text        = $"{Application.ProductName} {Application.ProductVersion}";
            window.Icon        = Properties.Resources.AppIcon;
            window.ForeColor   = Color.Black;
            window.BackColor   = Color.White;
            window.MinimumSize = new Size(0, 0);
            window.MaximumSize = new Size(0, 0);
            window.Size        = new Size(width, height);
            window.ClientSize  = new Size(width, height);

            window.Paint       += WindowForm_Paint;
            window.ResizeBegin += WindowForm_ResizeBegin;
            window.Resize      += WindowForm_Resize;
            window.ResizeEnd   += WindowForm_ResizeEnd;

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

            Application.Run(window);
        }

        private void RenderThreadLoop()
        {
            Stopwatch renderStopwatch = new Stopwatch();

            while (renderThreadFlag)
            {
                double renderElapsedTime = 0;

                double renderRemainingTime = 0;

                if (window.IsHandleCreated)
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
            if (RenderWidth <= 0 || RenderHeight <= 0)
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

        private void WindowForm_ResizeBegin(object sender, EventArgs e) {}

        private void WindowForm_Resize(object sender, EventArgs e)
        {
            if (CanvasWidth >= RenderWidth || CanvasHeight >= RenderHeight)
            {
                return;
            }

            lock (renderLock)
            {
                try
                {
                    Canvas oldCanvas = canvas;

                    Canvas newCanvas = new Canvas(RenderWidth, RenderHeight);

                    using (Graphics g = Graphics.FromImage(newCanvas.Bitmap))
                    {
                        g.DrawImage(oldCanvas.Bitmap, 0, 0);
                    }

                    canvas = newCanvas;

                    oldCanvas.Dispose();
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

        private void WindowForm_ResizeEnd(object sender, EventArgs e) {}



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

            window.WaitHandleCreated();

            if (!window.IsHandleCreated)
            {
                return false;
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

            window.WaitHandleDestroyed();

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



        public void Wait(int milliseconds)
        {
            if (milliseconds < 0)
            {
                return;
            }

            Thread.Sleep(milliseconds);
        }



        public int WindowWidth
        {
            get
            {
                if (window.InvokeRequired)
                {
                    return (int)window.Invoke(new Func<int>(() =>
                        window.Width
                    ));
                }

                return window.Width;
            }
        }

        public int WindowHeight
        {
            get
            {
                if (window.InvokeRequired)
                {
                    return (int)window.Invoke(new Func<int>(() =>
                        window.Height
                    ));
                }

                return window.Height;
            }
        }

        public int RenderWidth
        {
            get
            {
                if (window.InvokeRequired)
                {
                    return (int)window.Invoke(new Func<int>(() =>
                        window.ClientSize.Width
                    ));
                }

                return window.ClientSize.Width;
            }
        }

        public int RenderHeight
        {
            get
            {
                if (window.InvokeRequired)
                {
                    return (int)window.Invoke(new Func<int>(() =>
                        window.ClientSize.Height
                    ));
                }

                return window.ClientSize.Height;
            }
        }



        private AutoResetEvent keyDownEvent;
        private AutoResetEvent keyUpEvent;

        private int lastKeyDown = -1;
        private int lastKeyUp   = -1;

        private int hasKeyDown = 0;
        private int hasKeyUp   = 0;

        private void WindowForm_KeyDown(object sender, KeyEventArgs e)
        {
            lastKeyDown = e.KeyValue;

            Interlocked.Exchange(ref hasKeyDown, 1);

            keyDownEvent.Set();
        }

        private void WindowForm_KeyUp(object sender, KeyEventArgs e)
        {
            lastKeyUp = e.KeyValue;

            Interlocked.Exchange(ref hasKeyUp, 1);

            keyUpEvent.Set();
        }

        public bool IsKeyDownAvailable => hasKeyDown == 1;
        public bool IsKeyUpAvailable   => hasKeyUp   == 1;

        public void ResetKeyDown() => lastKeyDown = -1;
        public void ResetKeyUp  () => lastKeyUp   = -1;

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
                key = lastKeyUp;

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

        private Point lastMouseDownLocation = new Point(-1, -1);
        private int   lastMouseDownButton   = -1;
        private Point lastMouseUpLocation   = new Point(-1, -1);
        private int   lastMouseUpButton     = -1;

        private int hasMouseDown = 0;
        private int hasMouseUp   = 0;

        private void WindowForm_MouseDown(object sender, MouseEventArgs e)
        {
            lastMouseDownLocation = new Point(e.X, e.Y);
            lastMouseDownButton   = (int)e.Button;

            Interlocked.Exchange(ref hasMouseDown, 1);

            mouseDownEvent.Set();
        }

        private void WindowForm_MouseUp(object sender, MouseEventArgs e)
        {
            lastMouseUpLocation = new Point(e.X, e.Y);
            lastMouseUpButton   = (int)e.Button;

            Interlocked.Exchange(ref hasMouseUp, 1);

            mouseUpEvent.Set();
        }

        public bool IsMouseDownAvailable => lastMouseDownButton != -1;
        public bool IsMouseUpAvailable   => lastMouseUpButton   != -1;

        public void ResetMouseDown()
        {
            lastMouseDownLocation = new Point(-1, -1);
            lastMouseDownButton   = -1;
        }

        public void ResetMouseUp()
        {
            lastMouseUpLocation = new Point(-1, -1);
            lastMouseUpButton   = -1;
        }

        public bool ConsumeMouseDown(out Point location, out int button)
        {
            if (Interlocked.Exchange(ref hasMouseDown, 0) == 1)
            {
                location = lastMouseDownLocation;
                button   = lastMouseDownButton;

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
                location = lastMouseUpLocation;
                button   = lastMouseUpButton;

                return true;
            }

            location = new Point(-1, -1);
            button   = -1;

            return false;
        }

        public bool DiscardMouseDown() => ConsumeMouseDown(out Point location, out int button);
        public bool DiscardMouseUp()   => ConsumeMouseUp  (out Point location, out int button);

        public void WaitMouseDown() => mouseDownEvent.WaitOne();
        public void WaitMouseUp()   => mouseUpEvent.  WaitOne();



        public int CanvasWidth  => canvas.Width;
        public int CanvasHeight => canvas.Height;

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
