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
 * Nome file : Canvas.cs
 *
 * Titolo    : CANVAS
 * Sommario  : Contiene l'implementazione della
 *             classe Canvas.
 *
 * Autore    : Luca Pollicino
 *             (https://github.com/reallukee)
 * Versione  : v0.6.3
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
using System.Drawing.Imaging;
using System.Windows.Forms;

using Reallukee.GWC.Internal;
using Reallukee.GWC.Interop;

namespace Reallukee.GWC
{
    public sealed class Canvas : IDisposable, IRenderable, IBorderColor, IFillColor
    {
        public const int MaxBufferLength = 10000;

        private bool disposed;

        public Canvas(int width, int height)
        {
            ThrowIfArgumentOutOfRange(
                nameof(width),
                width,
                IsLessOrEqualThen(0)
            );

            ThrowIfArgumentOutOfRange(
                nameof(height),
                height,
                IsLessOrEqualThen(0)
            );

            InitBitmap(width, height);
            InitBuffer(width, height);

            BorderColor = Color.Black;
            FillColor   = Color.Green;

            disposed = false;
        }

        public Canvas()
            : this(800, 600)
        {

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
                Bitmap?.Dispose();
                Marshal.FreeHGlobal(RawBitmap);

                Bitmap = null;
                RawBitmap = IntPtr.Zero;
            }

            disposed = true;
        }



        private delegate (bool Invalid, string Message) RangeCheck(int value);

        private RangeCheck IsLessOrEqualThen(int min)
        {
            return value =>
            {
                if (value <= min)
                {
                    return (
                        true,
                        $"Value cannot be less or equal than {min}."
                    );
                }

                return (false, null);
            };
        }

        private RangeCheck IsGreaterOrEqualThan(int max)
        {
            return value =>
            {
                if (value >= max)
                {
                    return (
                        true,
                        $"Value cannot be greater or equal than {max}."
                    );
                }

                return (false, null);
            };
        }

        private void ThrowIfArgumentOutOfRange(
            string name, int value, params RangeCheck[] rangeChecks
        )
        {
            foreach (var rangeCheck in rangeChecks)
            {
                (bool invalid, string message) = rangeCheck(value);

                if (invalid)
                {
                    throw new ArgumentOutOfRangeException(
                        name,
                        message
                    );
                }
            }
        }



        private object bitmapLock;

        private object bufferLock;

        private void InitBitmap(int width, int height)
        {
            try
            {
                RawBitmap = Marshal.AllocHGlobal(width * height * 4);

                Bitmap = new Bitmap(
                    width,
                    height,
                    width * 4,
                    PixelFormat.Format32bppPArgb,
                    RawBitmap
                );
            }
            catch (Exception ex)
            {
                MessageBox.Show(
                    $"Critical Error!\n Reason: {ex.Message}",
                    "GWC",
                    MessageBoxButtons.OK,
                    MessageBoxIcon.Error
                );
            }

            bitmapLock = new object();
        }

        private void InitBuffer(int width, int height)
        {
            Buffer = new ConcurrentQueue<IRenderable>();

            bufferLock = new object();
        }



        internal int RawBitmapSize
        {
            get;
            set;
        }

        internal IntPtr RawBitmap
        {
            get;
            set;
        }

        internal Bitmap Bitmap
        {
            get;
            set;
        }

        internal ConcurrentQueue<IRenderable> Buffer
        {
            get;
            set;
        }



        public Color BorderColor
        {
            get;
            set;
        }

        public Color FillColor
        {
            get;
            set;
        }



        public Rectangle Bounds   => new Rectangle(0, 0, Width, Height);
        public Size      Size     => new Size     (Width, Height);
        public Point     Location => new Point    (0, 0);



        public int Width
        {
            get
            {
                lock (bitmapLock)
                {
                    return Bitmap.Width;
                }
            }
        }

        public int Height
        {
            get
            {
                lock (bitmapLock)
                {
                    return Bitmap.Height;
                }
            }
        }



        internal bool IsCached
        {
            get;
            private set;
        }

        internal bool DrawRenderable(IRenderable renderable)
        {
            if (Buffer.Count > MaxBufferLength)
            {
                return false;
            }

            Buffer.Enqueue(renderable);

            IsCached = false;

            return true;
        }



        public bool Clear()
        {
            IRenderable renderable = new Clear(FillColor);

            return DrawRenderable(renderable);
        }



        public bool DrawCanvas(Canvas canvas)
        {
            IRenderable renderable = new GCanvas(0, 0, canvas);

            return DrawRenderable(renderable);
        }

        public bool DrawCanvas(int x, int y, Canvas canvas)
        {
            IRenderable renderable = new GCanvas(x, y, canvas);

            return DrawRenderable(renderable);
        }

        public bool DrawCanvasF(float x, float y, Canvas canvas)
        {
            IRenderable renderable = new GCanvasF(x, y, canvas);

            return DrawRenderable(renderable);
        }



        public bool DrawSprite(Sprite sprite)
        {
            IRenderable renderable = new GSprite(0, 0, sprite);

            return DrawRenderable(renderable);
        }

        public bool DrawSprite(int x, int y, Sprite sprite)
        {
            IRenderable renderable = new GSprite(x, y, sprite);

            return DrawRenderable(renderable);
        }

        public bool DrawSpriteF(float x, float y, Sprite sprite)
        {
            IRenderable renderable = new GSpriteF(x, y, sprite);

            return DrawRenderable(renderable);
        }



        public bool DrawBorderSquare(int x, int y, int side)
        {
            return DrawBorderRectangle(x, y, side, side);
        }

        public bool DrawBorderSquareF(float x, float y, float side)
        {
            return DrawBorderRectangleF(x, y, side, side);
        }

        public bool DrawFillSquare(int x, int y, int side)
        {
            return DrawFillRectangle(x, y, side, side);
        }

        public bool DrawFillSquareF(float x, float y, float side)
        {
            return DrawFillRectangleF(x, y, side, side);
        }



        public bool DrawBorderRectangle(int x, int y, int width, int height)
        {
            IRenderable renderable = new GBorderRectangle(BorderColor, x, y, width, height);

            return DrawRenderable(renderable);
        }

        public bool DrawBorderRectangleF(float x, float y, float width, float height)
        {
            IRenderable renderable = new GBorderRectangleF(BorderColor, x, y, width, height);

            return DrawRenderable(renderable);
        }

        public bool DrawFillRectangle(int x, int y, int width, int height)
        {
            IRenderable renderable = new GFillRectangle(FillColor, x, y, width, height);

            return DrawRenderable(renderable);
        }

        public bool DrawFillRectangleF(float x, float y, float width, float height)
        {
            IRenderable renderable = new GFillRectangleF(FillColor, x, y, width, height);

            return DrawRenderable(renderable);
        }



        public bool DrawBorderCircle(int x, int y, int radius)
        {
            return DrawBorderEllipse(x, y, radius * 2, radius * 2);
        }

        public bool DrawBorderCircleF(float x, float y, float radius)
        {
            return DrawBorderEllipseF(x, y, radius * 2, radius * 2);
        }

        public bool DrawFillCircle(int x, int y, int radius)
        {
            return DrawFillEllipse(x, y, radius * 2, radius * 2);
        }

        public bool DrawFillCircleF(float x, float y, float radius)
        {
            return DrawFillEllipseF(x, y, radius * 2, radius * 2);
        }



        public bool DrawBorderEllipse(int x, int y, int width, int height)
        {
            IRenderable renderable = new GBorderEllipse(BorderColor, x, y, width, height);

            return DrawRenderable(renderable);
        }

        public bool DrawBorderEllipseF(float x, float y, float width, float height)
        {
            IRenderable renderable = new GBorderEllipseF(BorderColor, x, y, width, height);

            return DrawRenderable(renderable);
        }

        public bool DrawFillEllipse(int x, int y, int width, int height)
        {
            IRenderable renderable = new GFillEllipse(FillColor, x, y, width, height);

            return DrawRenderable(renderable);
        }

        public bool DrawFillEllipseF(float x, float y, float width, float height)
        {
            IRenderable renderable = new GFillEllipseF(FillColor, x, y, width, height);

            return DrawRenderable(renderable);
        }



        public bool DrawImage(int x, int y, Image image)
        {
            IRenderable renderable = new GImage(x, y, image);

            return DrawRenderable(renderable);
        }

        public bool DrawImageF(float x, float y, Image image)
        {
            IRenderable renderable = new GImageF(x, y, image);

            return DrawRenderable(renderable);
        }

        public bool DrawIcon(int x, int y, Icon icon)
        {
            IRenderable renderable = new GIcon(x, y, icon);

            return DrawRenderable(renderable);
        }

        public bool DrawIconF(float x, float y, Icon icon)
        {
            IRenderable renderable = new GIconF(x, y, icon);

            return DrawRenderable(renderable);
        }



        public void Render(Graphics g)
        {
            if (IsCached)
            {
                lock (bitmapLock)
                {
                    g.DrawImage(Bitmap, 0, 0);
                }
            }
            else
            {
                while (Buffer.TryDequeue(out IRenderable renderable))
                {
                    renderable.Render(g);

                    if (renderable is IDisposable disposable)
                    {
                        disposable.Dispose();
                    }
                }

                IsCached = true;
            }
        }

        public void Render()
        {
            lock (bitmapLock)
            {
                using (Graphics g = Graphics.FromImage(Bitmap))
                {
                    Render(g);
                }

                IsCached = true;
            }
        }
    }
}
