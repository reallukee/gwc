//
// :.:.:.
// GWC
// v0.3.0
// :.:.:.
//
// https://github.com/reallukee/gwc
//
// Sprite.cs
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
    public sealed class Sprite : IDisposable, IRenderable, IFillColor, IBorderColor
    {
        internal const int MaxBufferLength = 10000;

        public Sprite(int width, int height)
        {
            if (width <= 0)
            {
                throw new ArgumentOutOfRangeException(
                    nameof(width), "Width cannot be zero or negative."
                );
            }

            if (height <= 0)
            {
                throw new ArgumentOutOfRangeException(
                    nameof(height), "Height cannot be zero or negative."
                );
            }

            InitBitmap(width, height);

            InitBuffer(width, height);

            BorderColor = Color.Black;
            FillColor   = Color.Green;
        }

        public Sprite() : this(800, 600) { }

        ~Sprite()
        {
            Dispose();
        }

        public void Dispose()
        {
            Bitmap?.Dispose();
        }



        private object bitmapLock;

        private object bufferLock;

        private void InitBitmap(int width, int height)
        {
            Bitmap = new Bitmap(width, height);

            bitmapLock = new object();
        }

        private void InitBuffer(int width, int height)
        {
            Buffer = new ConcurrentQueue<IRenderable>();

            bufferLock = new object();
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



        public Size  Size     => new Size (Width, Height);
        public Point Location => new Point(0, 0);



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
                throw ex;
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
                }
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
