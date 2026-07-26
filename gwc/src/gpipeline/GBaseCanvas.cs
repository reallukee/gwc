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
 * Nome file : GBaseCanvas.cs
 *
 * Titolo    : GBASECANVAS
 * Sommario  : Contiene l'implementazione della
 *             classe GBaseCanvas.
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

namespace Reallukee.GWC.GPipeline
{
    internal abstract class GBaseCanvas<T> : GObject<T>, IDisposable
    {
        protected bool disposed;

        private void CopyBitmap(IntPtr otherRawBitmap)
        {
            try
            {
                int bitmapStride = Width * 4;

                this.RawBitmapSize = Math.Abs(bitmapStride) * Height;
                this.RawBitmap = Marshal.AllocHGlobal(RawBitmapSize);

                unsafe
                {
                    Buffer.MemoryCopy(
                        (void*)otherRawBitmap,
                        (void*)RawBitmap,
                        RawBitmapSize,
                        RawBitmapSize
                    );
                }

                Bitmap = new Bitmap(
                    Width,
                    Height,
                    bitmapStride,
                    PixelFormat.Format32bppArgb,
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
        }

        public GBaseCanvas(T x, T y, Canvas canvas)
        {
            ThrowIfArgumentNull(
                nameof(canvas),
                canvas
            );

            this.X      = x;
            this.Y      = y;
            this.Width  = canvas.Bitmap.Width;
            this.Height = canvas.Bitmap.Height;

            if (!canvas.IsCached)
            {
                canvas.Render();
            }

            CopyBitmap(canvas.RawBitmap);
        }

        public GBaseCanvas(GBaseCanvas<T> other)
        {
            ThrowIfArgumentNull(
                nameof(other),
                other
            );

            ThrowIfObjectDisposed(
                nameof(other),
                other.disposed
            );

            this.X      = other.X;
            this.Y      = other.Y;
            this.Width  = other.Width;
            this.Height = other.Height;

            CopyBitmap(other.RawBitmap);
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
                Bitmap.Dispose();

                Marshal.FreeHGlobal(RawBitmap);

                RawBitmapSize = 0;
                RawBitmap = IntPtr.Zero;
            }

            disposed = true;
        }



        public T X
        {
            get;
            private set;
        }

        public T Y
        {
            get;
            private set;
        }

        public int Width
        {
            get;
            private set;
        }

        public int Height
        {
            get;
            private set;
        }



        private int RawBitmapSize
        {
            get;
            set;
        }

        protected IntPtr RawBitmap
        {
            get;
            private set;
        }

        protected Bitmap Bitmap
        {
            get;
            private set;
        }



        public override string ToString()
        {
            return string.Format(
                "GBaseCanvas<{0}>: X={1}, Y={2}, Disposed={3}",
                typeof(T).Name,
                X,
                Y,
                disposed
            );
        }
    }
}
