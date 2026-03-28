//
// :.:.:.
// GWC
// v0.1.1
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
