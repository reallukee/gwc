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
 * Nome file : CanvasBox.cs
 *
 * Titolo    : CANVASBOX
 * Sommario  : Contiene l'implementazione della
 *             classe CanvasBox.
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

namespace Reallukee.GWC.Internal
{
    internal sealed class CanvasBox : IDisposable, IRenderable
    {
        private int    rawBitmapSize;
        private IntPtr rawBitmap;
        private Bitmap bitmap;

        private bool disposed;

        public CanvasBox(int x, int y, Canvas canvas)
        {
            this.X      = x;
            this.Y      = y;
            this.Width  = canvas.Bitmap.Width;
            this.Height = canvas.Bitmap.Height;

            if (!canvas.IsCached)
            {
                canvas.Render();
            }

            try
            {
                int bitmapStride = this.Width * 4;

                this.rawBitmapSize = Math.Abs(bitmapStride) * this.Height;
                this.rawBitmap     = Marshal.AllocHGlobal(rawBitmapSize);

                unsafe
                {
                    Buffer.MemoryCopy(
                        (void*)canvas.RawBitmap,
                        (void*)rawBitmap,
                        rawBitmapSize,
                        rawBitmapSize
                    );
                }

                bitmap = new Bitmap(
                    width,
                    height,
                    bitmapStride,
                    PixelFormat.Format32bppArgb,
                    rawBitmap
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
                bitmap.Dispose();

                Marshal.FreeHGlobal(rawBitmap);

                rawBitmapSize = 0;
                rawBitmap     = IntPtr.Zero;
            }

            disposed = true;
        }



        private int x;

        public int X
        {
            get
            {
                return x;
            }

            set
            {
                x = value;
            }
        }

        private int y;

        public int Y
        {
            get
            {
                return y;
            }

            set
            {
                y = value;
            }
        }

        private int width;

        public int Width
        {
            set
            {
                width = value;
            }

            get
            {
                return width;
            }
        }

        private int height;

        public int Height
        {
            set
            {
                height = value;
            }

            get
            {
                return height;
            }
        }



        public Rectangle Bounds
        {
            get
            {
                return new Rectangle(X, Y, Width, Height);
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
                return new Point(X, Y);
            }
        }



        public void Render(Graphics g)
        {
            g.DrawImage(bitmap, X, Y);
        }
    }
}
