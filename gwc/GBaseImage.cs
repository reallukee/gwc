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
 * Nome file : BaseImage.cs
 *
 * Titolo    : BASEIMAGE
 * Sommario  : Contiene l'implementazione della
 *             classe BaseImage.
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
using System.Windows.Forms;

namespace Reallukee.GWC.Internal
{
    internal abstract class GBaseImage<T> : IDisposable
    {
        protected bool disposed;

        public GBaseImage(T x, T y, Image image)
        {
            ThrowIfArgumentNull(
                nameof(image),
                image
            );

            this.X     = x;
            this.Y     = y;
            this.Image = (Image)image.Clone();

            disposed = false;
        }

        public GBaseImage(GBaseImage<T> other)
        {
            ThrowIfArgumentNull(
                nameof(other),
                other
            );

            ThrowIfObjectDisposed(
                nameof(other),
                other.disposed
            );

            this.X     = other.X;
            this.Y     = other.Y;
            this.Image = (Image)other.Image.Clone();

            disposed = false;
        }

        public void Dispose()
        {
            Dispose(true);
        }

        protected void Dispose(bool disposing)
        {
            if (disposed)
            {
                return;
            }

            if (disposing)
            {
                Image?.Dispose();

                Image = null;
            }

            disposed = true;
        }



        protected static void ThrowIfObjectDisposed(
            string name, bool disposed
        )
        {
            if (disposed)
            {
                throw new ArgumentNullException(
                    name,
                    "Object is disposed."
                );
            }
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

        protected Image Image
        {
            get;
            set;
        }



        public int Width
        {
            get
            {
                ThrowIfObjectDisposed(
                    nameof(GBaseImage<T>),
                    disposed
                );

                return Image.Width;
            }
        }

        public int Height
        {
            get
            {
                ThrowIfObjectDisposed(
                    nameof(GBaseImage<T>),
                    disposed
                );

                return Image.Height;
            }
        }



        public abstract GBaseImage<T> Clone();



        public static bool operator ==(GBaseImage<T> left, GBaseImage<T> right)
        {
            return ReferenceEquals(left, right);
        }

        public static bool operator !=(GBaseImage<T> left, GBaseImage<T> right)
        {
            return !(left == right);
        }



        public override bool Equals(object obj)
        {
            if (!(obj is GBaseImage<T> other))
            {
                return false;
            }

            return this == other;
        }

        public override int GetHashCode()
        {
            return RuntimeHelpers.GetHashCode(this);
        }

        public override string ToString()
        {
            return string.Format(
                "GBaseImage: X={0}, Y={1}, Disposed={2}",
                X,
                Y,
                disposed
            );
        }
    }
}
