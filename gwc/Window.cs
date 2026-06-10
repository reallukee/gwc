/*
 * :.:.:.:.:.:.:.:.
 * GWC
 * Graphical Window
 * for Console Apps
 * :.:.:.:.:.:.:.:.
 *
 * A Graphics Library
 *
 * https://github.com/reallukee/gwc
 *
 * Nome file : Window.cs
 *
 * Titolo    : WINDOW
 * Sommario  : Contiene l'implementazione della
 *             classe Window.
 *
 * Autore    : Luca Pollicino
 *             (https://github.com/reallukee)
 * Versione  : v0.6.1
 *             NOTA BENE: Campo INDICATIVO!
 * Licenza   : MIT
 */

using System;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Threading;

using System.Drawing;
using System.Windows.Forms;

using Reallukee.GWC.Internal;
using Reallukee.GWC.Interop;

namespace Reallukee.GWC
{
    public sealed class Window : IDisposable
    {
        public const int MaxKeyDownBufferLength = 100;
        public const int MaxKeyUpBufferLength   = 100;

        public const int MaxMouseDownBufferLength = 100;
        public const int MaxMouseUpBufferLength   = 100;

        private bool disposed;

        public Window(int width, int height)
        {
            ThrowIfArgumentOutOfRange(nameof(width), width, IsLessOrEqualThen(0));

            ThrowIfArgumentOutOfRange(nameof(height), height, IsLessOrEqualThen(0));

            InitWindow(width, height);

            InitRender(width, height);

            disposed = false;
        }

        public Window() : this(800, 600)
        {

        }

        public Window(Window other)
        {
            ThrowIfArgumentNull(nameof(other), other);

            ThrowIfObjectDisposed(nameof(other), other.disposed);

            InitWindow(other.WindowWidth, other.WindowHeight);

            InitRender(other.WindowWidth, other.WindowHeight);

            disposed = false;
        }

        public void Dispose()
        {
            Dispose(true);
        }

        private void Dispose(bool disposing)
        {
            if (disposed)
            {
                return;
            }

            if (disposing)
            {
                canvas?.Dispose();

                canvas = null;
            }

            disposed = true;
        }



        private static void ThrowIfObjectDisposed(string name, bool disposed)
        {
            if (disposed)
            {
                string message = "Object is disposed.";

                throw new ArgumentNullException(name, message);
            }
        }



        private static void ThrowIfArgumentNull(string name, object value)
        {
            if (value == null)
            {
                string message = "Object cannot null.";

                throw new ArgumentNullException(name, message);
            }
        }



        private delegate (bool Invalid, string Message) RangeCheck(int value);

        private static RangeCheck IsLessOrEqualThen(int min)
        {
            return value =>
            {
                if (value <= min)
                {
                    string message = $"Value cannot be less or equal than {min}.";

                    return (true, message);
                }

                return (false, null);
            };
        }

        private static RangeCheck IsGreaterOrEqualThan(int max)
        {
            return value =>
            {
                if (value >= max)
                {
                    string message = $"Value cannot be greater or equal than {max}.";

                    return (true, message);
                }

                return (false, null);
            };
        }

        private static void ThrowIfArgumentOutOfRange(
            string name, int value, params RangeCheck[] rangeChecks
        )
        {
            foreach (var rangeCheck in rangeChecks)
            {
                (bool invalid, string message) = rangeCheck(value);

                if (invalid)
                {
                    throw new ArgumentOutOfRangeException(name, message);
                }
            }
        }



        private WindowForm    window;

        private Thread        windowThread;
        private volatile bool windowThreadFlag;
        private object        windowLock;
        private volatile bool windowEnabled;
        private volatile int  windowSkip;

        private Canvas        canvas;

        private Thread        renderThread;
        private volatile bool renderThreadFlag;
        private object        renderLock;
        private volatile bool renderEnabled;
        private volatile int  renderSkip;

        private void InitWindow(int width, int height)
        {
            window = new WindowForm();

            string text = "GWC Window";

            if (!string.IsNullOrWhiteSpace(Application.ProductName) && !string.IsNullOrWhiteSpace(Application.ProductVersion))
            {
                text = $"{Application.ProductName} {Application.ProductVersion}";
            }

            Icon icon = Properties.Resources.AppIcon;

            window.Text        = text;
            window.Icon        = icon;
            window.MinimumSize = new Size(0, 0);
            window.MaximumSize = new Size(0, 0);
            window.Size        = new Size(width, height);
            window.ClientSize  = new Size(width, height);

            window.Paint       += WindowForm_Paint;
            window.ResizeBegin += WindowForm_ResizeBegin;
            window.Resize      += WindowForm_Resize;
            window.ResizeEnd   += WindowForm_ResizeEnd;

            window.KeyDown     += WindowForm_KeyDown;
            window.KeyUp       += WindowForm_KeyUp;
            window.MouseDown   += WindowForm_MouseDown;
            window.MouseUp     += WindowForm_MouseUp;

            keyDownEvent       = new AutoResetEvent(false);
            keyUpEvent         = new AutoResetEvent(false);
            mouseDownEvent     = new AutoResetEvent(false);
            mouseUpEvent       = new AutoResetEvent(false);

            keyDownBuffer      = new ConcurrentQueue<Keys>();
            keyUpBuffer        = new ConcurrentQueue<Keys>();
            mouseDownBuffer    = new ConcurrentQueue<(Point, MouseButtons)>();
            mouseUpBuffer      = new ConcurrentQueue<(Point, MouseButtons)>();

            windowThread = new Thread(WindowThreadLoop)
            {
                IsBackground = true
            };

            windowLock = new object();

            windowEnabled = false;

            windowSkip = 0;
        }

        private void InitRender(int width, int height)
        {
            canvas = new Canvas(width, height);

            canvas.BorderColor = Color.Black;
            canvas.FillColor   = Color.Green;

            renderThread = new Thread(RenderThreadLoop)
            {
                IsBackground = true
            };

            renderLock = new object();

            renderEnabled = false;

            renderSkip = 0;
        }



        private void WindowThreadLoop()
        {
            try
            {
                while (windowThreadFlag)
                {
                    Application.EnableVisualStyles();

                    Application.SetCompatibleTextRenderingDefault(false);

                    if (windowEnabled)
                    {
                        Application.Run(window);
                    }
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
                                while (canvas.Buffer.TryDequeue(out IRenderable renderable))
                                {
                                    renderable.Render(g);

                                    if (renderable is IDisposable disposable)
                                    {
                                        disposable.Dispose();
                                    }

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

                    if (renderEnabled)
                    {
                        if (renderSkip > 0)
                        {
                            renderSkip--;
                        }
                        else
                        {
                            window.BeginInvoke((Action)(() => {
                                window.Invalidate();

                                window.Update();
                            }));
                        }
                    }
                }

                renderRemainingTime = Render.FrameTime - renderElapsedTime;

                if (renderRemainingTime >= 0)
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

        private void WindowForm_ResizeBegin(object sender, EventArgs e)
        {

        }

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

        private void WindowForm_ResizeEnd(object sender, EventArgs e)
        {

        }



        public bool Open()
        {
            if (windowThread.IsAlive || renderThread.IsAlive)
            {
                return false;
            }

            if (window.IsHandleCreated)
            {
                return false;
            }

            windowEnabled = true;
            renderEnabled = true;

            windowThreadFlag = true;
            renderThreadFlag = true;

            windowThread.Start();
            renderThread.Start();

            window.WaitHandleCreated();

            return true;
        }

        public bool IsOpen
        {
            get
            {
                return window.IsHandleCreated;
            }
        }

        public bool Close()
        {
            if (!windowThread.IsAlive || !renderThread.IsAlive)
            {
                return false;
            }

            if (!window.IsHandleCreated)
            {
                return false;
            }

            windowEnabled = false;
            renderEnabled = false;

            windowThreadFlag = false;
            renderThreadFlag = false;

            windowThread.Join(100);
            renderThread.Join(100);

            Application.Exit();

            window.WaitHandleDestroyed();

            return true;
        }

        public bool IsClose
        {
            get
            {
                return !window.IsHandleCreated;
            }
        }



        public bool Suspend()
        {
            if (!windowEnabled && !renderEnabled)
            {
                return false;
            }

            windowEnabled = false;
            renderEnabled = false;

            return true;
        }

        public bool IsSuspend
        {
            get
            {
                return !windowEnabled && !renderEnabled;
            }
        }

        public bool Resume()
        {
            if (windowEnabled && renderEnabled)
            {
                return false;
            }

            windowEnabled = true;
            renderEnabled = true;

            return true;
        }

        public bool IsResume
        {
            get
            {
                return windowEnabled && renderEnabled;
            }
        }



        public void Wait(int milliseconds)
        {
            Thread.Sleep(milliseconds);
        }

        public void Wait()
        {
            Thread.Sleep(100);
        }



        public void Skip(int frames)
        {
            windowSkip = windowSkip + frames;
            renderSkip = renderSkip + frames;
        }

        public void Skip()
        {
            windowSkip++;
            renderSkip++;
        }



        public bool Show()
        {
            if (!window.IsHandleCreated)
            {
                return false;
            }

            window.BeginInvoke((Action)(() => {
                Show();
            }));

            return true;
        }

        public bool Hide()
        {
            if (!window.IsHandleCreated)
            {
                return false;
            }

            window.BeginInvoke((Action)(() => {
                Hide();
            }));

            return true;
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



        #if EXPERIMENTAL
        public Color WindowForeColor
        {
            get
            {
                if (window.InvokeRequired)
                {
                    return (Color)window.Invoke(new Func<Color>(() =>
                        window.ForeColor
                    ));
                }

                return window.ForeColor;
            }

            set
            {
                if (window.InvokeRequired)
                {
                    window.BeginInvoke((Action)(() =>
                    {
                        window.FormTextColor = value;
                        window.ForeColor = value;
                    }));
                }
                else
                {
                    window.FormTextColor = value;
                    window.ForeColor = value;
                }
            }
        }
        #endif

        #if EXPERIMENTAL
        public Color WindowBackColor
        {
            get
            {
                if (window.InvokeRequired)
                {
                    return (Color)window.Invoke(new Func<Color>(() =>
                        window.BackColor
                    ));
                }

                return window.BackColor;
            }

            set
            {
                if (window.InvokeRequired)
                {
                    window.BeginInvoke((Action)(() =>
                    {
                        window.FormCaptionColor = value;
                        window.BackColor = value;
                    }));
                }
                else
                {
                    window.FormCaptionColor = value;
                    window.BackColor = value;
                }
            }
        }
        #endif



        private AutoResetEvent keyDownEvent;
        private AutoResetEvent keyUpEvent;

        private ConcurrentQueue<Keys> keyDownBuffer;
        private ConcurrentQueue<Keys> keyUpBuffer;

        private int hasKeyDown = 0;
        private int hasKeyUp   = 0;

        private bool[] keyPressed = new bool[256];

        private void WindowForm_KeyDown(object sender, KeyEventArgs e)
        {
            int key = (int)e.KeyCode;

            if (keyPressed[key])
            {
                return;
            }

            keyPressed[key] = true;

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
            int key = (int)e.KeyCode;

            keyPressed[key] = false;

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

        public bool IsKeyDownAvailable
        {
            get
            {
                return hasKeyDown == 1;
            }
        }

        public bool IsKeyUpAvailable
        {
            get
            {
                return hasKeyUp == 1;
            }
        }

        public void FlushKeyDown()
        {
            Interlocked.Exchange(ref keyDownBuffer, new ConcurrentQueue<Keys>());
        }

        public void FlushKeyUp()
        {
            Interlocked.Exchange(ref keyUpBuffer, new ConcurrentQueue<Keys>());
        }

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

        public bool DiscardKeyDown()
        {
            return ConsumeKeyDown(out Keys _, out Keys _);
        }

        public bool DiscardKeyUp()
        {
            return ConsumeKeyUp(out Keys _, out Keys _);
        }

        public bool IsKeyDownInBuffer(Keys modifiers, Keys key)
        {
            Keys keyData = modifiers | key;

            Keys[] buffer = keyDownBuffer.ToArray();

            return buffer.Contains(keyData);
        }

        public bool IsKeyUpInBuffer(Keys modifiers, Keys key)
        {
            Keys keyData = modifiers | key;

            Keys[] buffer = keyUpBuffer.ToArray();

            return buffer.Contains(keyData);
        }

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

        public int KeyDownBufferLength
        {
            get
            {
                return keyDownBuffer.Count;
            }
        }

        public int KeyUpBufferLength
        {
            get
            {
                return keyUpBuffer.Count;
            }
        }



        private AutoResetEvent mouseDownEvent;
        private AutoResetEvent mouseUpEvent;

        private ConcurrentQueue<(Point, MouseButtons)> mouseDownBuffer;
        private ConcurrentQueue<(Point, MouseButtons)> mouseUpBuffer;

        private int hasMouseDown = 0;
        private int hasMouseUp   = 0;

        private bool[] mousePressed = new bool[8];

        private void WindowForm_MouseDown(object sender, MouseEventArgs e)
        {
            int mouse = (int)Math.Log((int)e.Button, 2) - 20;

            if (mousePressed[mouse])
            {
                return;
            }

            mousePressed[mouse] = true;

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
            int mouse = (int)Math.Log((int)e.Button, 2) - 20;

            mousePressed[mouse] = false;

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

        public bool IsMouseDownAvailable
        {
            get
            {
                return hasMouseDown == 1;
            }
        }

        public bool IsMouseUpAvailable
        {
            get
            {
                return hasMouseUp == 1;
            }
        }

        public void FlushMouseDown()
        {
            Interlocked.Exchange(ref mouseDownBuffer, new ConcurrentQueue<(Point, MouseButtons)>());
        }

        public void FlushMouseUp()
        {
            Interlocked.Exchange(ref mouseUpBuffer, new ConcurrentQueue<(Point, MouseButtons)>());
        }

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

        public bool DiscardMouseDown()
        {
            return ConsumeMouseDown(out Point _, out MouseButtons _);
        }

        public bool DiscardMouseUp()
        {
            return ConsumeMouseUp(out Point _, out MouseButtons _);
        }

        public bool IsMouseDownInBuffer(Point location, MouseButtons button)
        {
            (Point, MouseButtons) mouseData = (location, button);

            (Point, MouseButtons)[] buffer = mouseDownBuffer.ToArray();

            return buffer.Contains(mouseData);
        }

        public bool IsMouseUpInBuffer(Point location, MouseButtons button)
        {
            (Point, MouseButtons) mouseData = (location, button);

            (Point, MouseButtons)[] buffer = mouseUpBuffer.ToArray();

            return buffer.Contains(mouseData);
        }

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

        public int MouseDownBufferLength
        {
            get
            {
                return mouseDownBuffer.Count;
            }
        }

        public int MouseUpBufferLength
        {
            get
            {
                return mouseUpBuffer.Count;
            }
        }



        public int CanvasWidth
        {
            get
            {
                return canvas.Width;
            }
        }

        public int CanvasHeight
        {
            get
            {
                return canvas.Height;
            }
        }



        public Color BorderColor
        {
            get
            {
                return canvas.BorderColor;
            }

            set
            {
                canvas.BorderColor = value;
            }
        }

        public Color FillColor
        {
            get
            {
                return canvas.FillColor;
            }

            set
            {
                canvas.FillColor = value;
            }
        }



        internal bool DrawRenderable(IRenderable renderable)
        {
            return canvas.DrawRenderable(renderable);
        }



        public bool Clear(Color clearColor)
        {
            return canvas.Clear(clearColor);
        }



        public bool DrawCanvas(Canvas canvas)
        {
            return this.canvas.DrawCanvas(canvas);
        }

        public bool DrawSprite(Sprite sprite)
        {
            return this.canvas.DrawSprite(sprite);
        }



        public bool DrawBorderSquare(int x, int y, int side)
        {
            return canvas.DrawBorderSquare(x, y, side);
        }

        public bool DrawFillSquare(int x, int y, int side)
        {
            return canvas.DrawFillSquare(x, y, side);
        }



        public bool DrawBorderRectangle(int x, int y, int width, int height)
        {
            return canvas.DrawBorderRectangle(x, y, width, height);
        }

        public bool DrawFillRectangle(int x, int y, int width, int height)
        {
            return canvas.DrawFillRectangle(x, y, width, height);
        }



        public bool DrawBorderCircle(int x, int y, int radius)
        {
            return canvas.DrawBorderCircle(x, y, radius);
        }

        public bool DrawFillCircle(int x, int y, int radius)
        {
            return canvas.DrawFillCircle(x, y, radius);
        }



        public bool DrawBorderEllipse(int x, int y, int width, int height)
        {
            return canvas.DrawBorderEllipse(x, y, width, height);
        }

        public bool DrawFillEllipse(int x, int y, int width, int height)
        {
            return canvas.DrawFillEllipse(x, y, width, height);
        }



        public bool DrawImage(int x, int y, Image image)
        {
            return canvas.DrawImage(x, y, image);
        }

        public bool DrawIcon(int x, int y, Icon icon)
        {
            return canvas.DrawIcon(x, y, icon);
        }
    }
}
