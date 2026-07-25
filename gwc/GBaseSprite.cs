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
 * Nome file : GBaseSprite.cs
 *
 * Titolo    : GBASESPRITE
 * Sommario  : Contiene l'implementazione della
 *             classe GBaseSprite.
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

namespace Reallukee.GWC.Internal
{
    internal abstract class GBaseSprite<T> : IDisposable
    {
        private int    rawBitmapSize;
        private IntPtr rawBitmap;
        private Bitmap bitmap;

        protected bool disposed;

        public GBaseSprite(T x, T y, Sprite sprite)
        {
            ThrowIfArgumentNull(
                nameof(sprite),
                sprite
            );

            this.X      = x;
            this.Y      = y;
            this.Width  = sprite.Bitmap.Width;
            this.Height = sprite.Bitmap.Height;

            if (!sprite.IsCached)
            {
                sprite.Render();
            }

            try
            {
                int bitmapStride = Width * 4;

                this.rawBitmapSize = Math.Abs(bitmapStride) * Height;
                this.rawBitmap = Marshal.AllocHGlobal(rawBitmapSize);

                unsafe
                {
                    Buffer.MemoryCopy(
                        (void*)sprite.RawBitmap,
                        (void*)rawBitmap,
                        rawBitmapSize,
                        rawBitmapSize
                    );
                }

                bitmap = new Bitmap(
                    Width,
                    Height,
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
                rawBitmap = IntPtr.Zero;
            }

            disposed = true;
        }



        protected static void ThrowIfArgumentNull(
            string name, object value
        )
        {
            if (value == null)
            {
                throw new ArgumentNullException(
                    name,
                    "Object cannot null."
                );
            }
        }



        public T X
        {
            get;
            set;
        }

        public T Y
        {
            get;
            set;
        }

        public int Width
        {
            get;
            set;
        }

        public int Height
        {
            get;
            set;
        }



        protected Bitmap Bitmap => bitmap;



        public override string ToString()
        {
            return string.Format(
                "GBaseSprite: X={0}, Y={1}, Disposed={2}",
                X,
                Y,
                disposed
            );
        }
    }
}
