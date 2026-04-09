//
// :.:.:.
// GWC
// v0.2.1
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
        private const int MaxKeyDownBufferLength   = 100;
        private const int MaxKeyUpBufferLength     = 100;
        private const int MaxMouseDownBufferLength = 100;
        private const int MaxMouseUpBufferLength   = 100;

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

            keyDownBuffer   = new ConcurrentQueue<Keys>();
            keyUpBuffer     = new ConcurrentQueue<Keys>();
            mouseDownBuffer = new ConcurrentQueue<(Point, MouseButtons)>();
            mouseUpBuffer   = new ConcurrentQueue<(Point, MouseButtons)>();

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

        private ConcurrentQueue<Keys> keyDownBuffer;
        private ConcurrentQueue<Keys> keyUpBuffer;

        private int hasKeyDown = 0;
        private int hasKeyUp   = 0;

        private void WindowForm_KeyDown(object sender, KeyEventArgs e)
        {
            if (keyDownBuffer.Count <= MaxKeyDownBufferLength)
            {
                keyDownBuffer.Enqueue(e.KeyData);

                IsKeyDownLost = false;
            }
            else
            {
                IsKeyDownLost = true;
            }

            Interlocked.Exchange(ref hasKeyDown, 1);

            keyDownEvent.Set();
        }

        private void WindowForm_KeyUp(object sender, KeyEventArgs e)
        {
            if (keyUpBuffer.Count <= MaxKeyUpBufferLength)
            {
                keyUpBuffer.Enqueue(e.KeyData);

                IsKeyUpLost = false;
            }
            else
            {
                IsKeyUpLost = true;
            }

            Interlocked.Exchange(ref hasKeyUp, 1);

            keyUpEvent.Set();
        }

        public bool IsKeyDownAvailable => hasKeyDown == 1;
        public bool IsKeyUpAvailable   => hasKeyUp   == 1;

        public void FlushKeyDown() => Interlocked.Exchange(ref keyDownBuffer, new ConcurrentQueue<Keys>());
        public void FlushKeyUp  () => Interlocked.Exchange(ref keyUpBuffer,   new ConcurrentQueue<Keys>());

        public bool ConsumeKeyDown(out Keys modifiers, out Keys key)
        {
            if (Interlocked.Exchange(ref hasKeyDown, 0) == 1)
            {
                if (keyDownBuffer.TryDequeue(out Keys keyData))
                {
                    modifiers = keyData & Keys.Modifiers;
                    key       = keyData & Keys.KeyCode;

                    return true;
                }
            }

            modifiers = Keys.None;
            key       = Keys.None;

            return false;
        }

        public bool ConsumeKeyUp(out Keys modifiers, out Keys key)
        {
            if (Interlocked.Exchange(ref hasKeyUp, 0) == 1)
            {
                if (keyUpBuffer.TryDequeue(out Keys keyData))
                {
                    modifiers = keyData & Keys.Modifiers;
                    key       = keyData & Keys.KeyCode;

                    return true;
                }
            }

            modifiers = Keys.None;
            key       = Keys.None;

            return false;
        }

        public bool DiscardKeyDown() => ConsumeKeyDown(out Keys _, out Keys _);
        public bool DiscardKeyUp  () => ConsumeKeyUp  (out Keys _, out Keys _);

        public void WaitKeyDown() => keyDownEvent.WaitOne();
        public void WaitKeyUp  () => keyUpEvent  .WaitOne();

        public bool IsKeyDownLost
        {
            get;
            private set;
        }

        public bool IsKeyUpLost
        {
            get;
            private set;
        }

        public bool IsKeyDownBufferFull => keyDownBuffer.Count == MaxKeyDownBufferLength;
        public bool IsKeyUpBufferFull   => keyUpBuffer  .Count == MaxKeyUpBufferLength;



        private AutoResetEvent mouseDownEvent;
        private AutoResetEvent mouseUpEvent;

        private ConcurrentQueue<(Point, MouseButtons)> mouseDownBuffer;
        private ConcurrentQueue<(Point, MouseButtons)> mouseUpBuffer;

        private int hasMouseDown = 0;
        private int hasMouseUp   = 0;

        private void WindowForm_MouseDown(object sender, MouseEventArgs e)
        {
            if (mouseDownBuffer.Count <= MaxMouseDownBufferLength)
            {
                mouseDownBuffer.Enqueue((new Point(e.X, e.Y), e.Button));

                IsMouseDownLost = false;
            }
            else
            {
                IsMouseDownLost = true;
            }

            Interlocked.Exchange(ref hasMouseDown, 1);

            mouseDownEvent.Set();
        }

        private void WindowForm_MouseUp(object sender, MouseEventArgs e)
        {
            if (mouseUpBuffer.Count <= MaxMouseUpBufferLength)
            {
                mouseUpBuffer.Enqueue((new Point(e.X, e.Y), e.Button));

                IsMouseUpLost = false;
            }
            else
            {
                IsMouseUpLost = true;
            }

            Interlocked.Exchange(ref hasMouseUp, 1);

            mouseUpEvent.Set();
        }

        public bool IsMouseDownAvailable => hasMouseDown == 1;
        public bool IsMouseUpAvailable   => hasMouseUp   == 1;

        public void FlushMouseDown() => Interlocked.Exchange(ref mouseDownBuffer, new ConcurrentQueue<(Point, MouseButtons)>());
        public void FlushMouseUp  () => Interlocked.Exchange(ref mouseUpBuffer,   new ConcurrentQueue<(Point, MouseButtons)>());

        public bool ConsumeMouseDown(out Point location, out MouseButtons button)
        {
            if (Interlocked.Exchange(ref hasMouseDown, 0) == 1)
            {
                if (mouseDownBuffer.TryDequeue(out (Point, MouseButtons) mouseData))
                {
                    location = mouseData.Item1;
                    button   = mouseData.Item2;

                    return true;
                }
            }

            location = new Point(-1, -1);
            button   = MouseButtons.None;

            return false;
        }

        public bool ConsumeMouseUp(out Point location, out MouseButtons button)
        {
            if (Interlocked.Exchange(ref hasMouseUp, 0) == 1)
            {
                if (mouseUpBuffer.TryDequeue(out (Point, MouseButtons) mouseData))
                {
                    location = mouseData.Item1;
                    button   = mouseData.Item2;

                    return true;
                }
            }

            location = new Point(-1, -1);
            button   = MouseButtons.None;

            return false;
        }

        public bool DiscardMouseDown() => ConsumeMouseDown(out Point _, out MouseButtons _);
        public bool DiscardMouseUp()   => ConsumeMouseUp  (out Point _, out MouseButtons _);

        public void WaitMouseDown() => mouseDownEvent.WaitOne();
        public void WaitMouseUp()   => mouseUpEvent  .WaitOne();

        public bool IsMouseDownLost
        {
            get;
            private set;
        }

        public bool IsMouseUpLost
        {
            get;
            private set;
        }

        public bool IsMouseDownBufferFull => mouseDownBuffer.Count == MaxMouseDownBufferLength;
        public bool IsMouseUpBufferFull   => mouseUpBuffer  .Count == MaxMouseUpBufferLength;



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
