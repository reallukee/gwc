//
// GWC
//
//  Version : 0.1.0
//  MIT License
//  Window.cs
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
    public class Window
    {
        public Window()
        {
            InitWindow();

            if (windowCanvas != null)
            {
                InitRender();
            }
        }

        ~Window()
        {
            if (windowCanvas != null)
            {
                windowCanvas.Dispose();
            }
        }

        public const int DefaultWindowWidth    = 800;
        public const int DefaultWindowHeight   = 600;
        public const int MaxRenderBufferLength = 1000;

        private WindowForm       window;

        private Thread           windowThread;
        private volatile bool    windowThreadFlag;
        private Bitmap           windowCanvas;
        object                   windowLock;

        private Thread           renderThread;
        private volatile bool    renderThreadFlag;
        ConcurrentQueue<IFigure> renderBuffer;
        object                   renderLock;

        private void InitWindow()
        {
            window = new WindowForm();

            window.Text = string.Format(
                "{0} {1}",
                Application.ProductName,
                Application.ProductVersion
            );

            window.MinimumSize = new Size(0, 0);
            window.MaximumSize = new Size(0, 0);
            window.Size        = new Size(DefaultWindowWidth, DefaultWindowHeight);
            window.ClientSize  = new Size(DefaultWindowWidth, DefaultWindowHeight);

            borderColor = Color.Black;
            fillColor   = Color.Red;

            window.Paint += OnPaint;

            windowThread = new Thread(WindowThreadLoop);

            windowThreadFlag = true;

            windowCanvas = new Bitmap(DefaultWindowWidth, DefaultWindowHeight);
        }

        private void InitRender()
        {
            renderThread = new Thread(RenderThreadLoop)
            {
                IsBackground = true
            };

            renderThreadFlag = true;

            renderBuffer = new ConcurrentQueue<IFigure>();

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

                if (window.IsHandleCreated && !renderBuffer.IsEmpty)
                {
                    lock (renderLock)
                    {
                        try
                        {
                            renderStopwatch.Restart();

                            using (var g = Graphics.FromImage(windowCanvas))
                            {
                                while (renderBuffer.TryDequeue(out var figure))
                                {
                                    figure.Render(g);

                                    if (renderStopwatch.Elapsed.TotalMilliseconds > UtilFrameTime)
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
                                string.Format(
                                    "{0} {1}",
                                    Application.ProductName,
                                    Application.ProductVersion
                                ),
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

                double renderRemainingTime = FrameTime - renderElapsedTime;

                if (renderRemainingTime > 0)
                {
                    Thread.Sleep((int)renderRemainingTime);
                }
            }
        }

        private static int refreshRate = 60;

        public static int RefreshRate
        {
            get
            {
                return refreshRate;
            }

            set
            {
                if (value < 0 || value > 120)
                {
                    return;
                }

                refreshRate = value;

                FrameTime = 1000.0 / value;

                UtilFrameTime = DutyCycle / 100.0 * FrameTime;
            }
        }

        private static int dutyCycle = 80;

        public static int DutyCycle
        {
            get
            {
                return dutyCycle;
            }

            set
            {
                if (value < 0 || value > 100)
                {
                    return;
                }

                dutyCycle = value;

                FrameTime = 1000.0 / RefreshRate;

                UtilFrameTime = value / 100.0 * FrameTime;
            }
        }

        private static double frameTime = 16.66;

        public static double FrameTime
        {
            get
            {
                return frameTime;
            }

            private set
            {
                frameTime = value;
            }
        }

        private static double utilFrameTime = 13.32;

        public static double UtilFrameTime
        {
            get
            {
                return utilFrameTime;
            }

            private set
            {
                utilFrameTime = value;
            }
        }

        private Color borderColor;

        public Color BorderColor
        {
            get
            {
                return borderColor;
            }

            set
            {
                borderColor = value;
            }
        }

        private Color fillColor;

        public Color FillColor
        {
            get
            {
                return fillColor;
            }

            set
            {
                fillColor = value;
            }
        }

        private void OnPaint(object sender, PaintEventArgs e)
        {
            lock (renderLock)
            {
                try
                {
                    e.Graphics.DrawImage(windowCanvas, 0, 0);
                }
                catch (Exception ex)
                {
                    MessageBox.Show(
                        ex.Message,
                        string.Format(
                            "{0} {1}",
                            Application.ProductName,
                            Application.ProductVersion
                        ),
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

            if (window.IsHandleCreated)
            {
                Application.Exit();
            }

            return true;
        }

        public bool IsOpen
        {
           get
           {
                return window.IsHandleCreated;
           }
        }

        public bool IsShutdown
        {
            get
            {
                return !window.IsHandleCreated;
            }
        }

        public bool DrawBorderRectangle(int x, int y, int width, int height)
        {
            if (renderBuffer.Count > MaxRenderBufferLength)
            {
                return false;
            }

            IFigure borderRectangle = new BorderRectangle(BorderColor, x, y, width, height);

            renderBuffer.Enqueue(borderRectangle);

            return true;
        }

        public bool DrawFillRectangle(int x, int y, int width, int height)
        {
            if (renderBuffer.Count > MaxRenderBufferLength)
            {
                return false;
            }

            IFigure fillRectangle = new FillRectangle(FillColor, x, y, width, height);

            renderBuffer.Enqueue(fillRectangle);

            return true;
        }
    }
}
