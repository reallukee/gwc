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
 * Versione  : v0.6.2
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
                nameof(width), width, IsLessOrEqualThen(0)
            );

            ThrowIfArgumentOutOfRange(
                nameof(height), height, IsLessOrEqualThen(0)
            );

            InitBitmap(width, height);
            InitBuffer(width, height);

            BorderColor = Color.Black;
            FillColor   = Color.Green;

            disposed = false;
        }

        public Canvas() : this(800, 600)
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



        public Rectangle Bounds
        {
            get
            {
                return new Rectangle(0, 0, Width, Height);
            }
        }

        public Size Size
        {
            get
            {
                return new Size(Width, Height);
            }
        }

        public Point Location
        {
            get
            {
                return new Point(0, 0);
            }
        }



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



        public bool Clear(Color clearColor)
        {
            IRenderable clear = new Clear(clearColor);

            return DrawRenderable(clear);
        }



        public bool DrawCanvas(Canvas canvas)
        {
            IRenderable canvasBox = new CanvasBox(0, 0, canvas);

            return DrawRenderable(canvasBox);
        }

        public bool DrawCanvas(int x, int y, Canvas canvas)
        {
            IRenderable canvasBox = new CanvasBox(x, y, canvas);

            return DrawRenderable(canvasBox);
        }

        public bool DrawSprite(Sprite sprite)
        {
            IRenderable spriteBox = new SpriteBox(0, 0, sprite);

            return DrawRenderable(spriteBox);
        }

        public bool DrawSprite(int x, int y, Sprite sprite)
        {
            IRenderable spriteBox = new SpriteBox(x, y, sprite);

            return DrawRenderable(spriteBox);
        }



        public bool DrawBorderSquare(int x, int y, int side)
        {
            return DrawBorderRectangle(x, y, side, side);
        }

        public bool DrawFillSquare(int x, int y, int side)
        {
            return DrawFillRectangle(x, y, side, side);
        }



        public bool DrawBorderRectangle(int x, int y, int width, int height)
        {
            IRenderable borderRectangle = new BorderRectangle(BorderColor, x, y, width, height);

            return DrawRenderable(borderRectangle);
        }

        public bool DrawFillRectangle(int x, int y, int width, int height)
        {
            IRenderable fillRectangle = new FillRectangle(FillColor, x, y, width, height);

            return DrawRenderable(fillRectangle);
        }



        public bool DrawBorderCircle(int x, int y, int radius)
        {
            return DrawBorderEllipse(x, y, radius * 2, radius * 2);
        }

        public bool DrawFillCircle(int x, int y, int radius)
        {
            return DrawFillEllipse(x, y, radius * 2, radius * 2);
        }



        public bool DrawBorderEllipse(int x, int y, int width, int height)
        {
            IRenderable borderEllipse = new BorderEllipse(BorderColor, x, y, width, height);

            return DrawRenderable(borderEllipse);
        }

        public bool DrawFillEllipse(int x, int y, int width, int height)
        {
            IRenderable fillEllipse = new FillEllipse(FillColor, x, y, width, height);

            return DrawRenderable(fillEllipse);
        }



        public bool DrawImage(int x, int y, Image image)
        {
            IRenderable baseImage = new BaseImage(x, y, image);

            return DrawRenderable(baseImage);
        }

        public bool DrawIcon(int x, int y, Icon icon)
        {
            IRenderable baseIcon = new BaseIcon(x, y, icon);

            return DrawRenderable(baseIcon);
        }



        internal void ResizeBitmap(int width, int height)
        {
            try
            {
                Bitmap oldBitmap = Bitmap;

                Bitmap newBitmap = new Bitmap(width, height);

                using (Graphics g = Graphics.FromImage(newBitmap))
                {
                    g.DrawImage(oldBitmap, 0, 0);
                }

                Bitmap = newBitmap;

                oldBitmap.Dispose();
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
