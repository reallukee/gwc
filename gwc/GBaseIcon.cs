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
 * Nome file : GBaseIcon.cs
 *
 * Titolo    : GBASEICON
 * Sommario  : Contiene l'implementazione della
 *             classe GBaseIcon.
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
    internal abstract class GBaseIcon<T> : IDisposable
    {
        protected bool disposed;

        public GBaseIcon(T x, T y, Icon icon)
        {
            ThrowIfArgumentNull(
                nameof(icon),
                icon
            );

            this.X    = x;
            this.Y    = y;
            this.Icon = (Icon)icon.Clone();

            disposed = false;
        }

        public GBaseIcon(GBaseIcon<T> other)
        {
            ThrowIfArgumentNull(
                nameof(other),
                other
            );

            ThrowIfObjectDisposed(
                nameof(other),
                other.disposed
            );

            this.X    = other.X;
            this.Y    = other.Y;
            this.Icon = (Icon)other.Icon.Clone();

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
                Icon?.Dispose();

                Icon = null;
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

        protected Icon Icon
        {
            get;
            set;
        }



        public int Width
        {
            get
            {
                ThrowIfObjectDisposed(
                    nameof(GBaseIcon<T>),
                    disposed
                );

                return Icon.Width;
            }
        }

        public int Height
        {
            get
            {
                ThrowIfObjectDisposed(
                    nameof(GBaseIcon<T>),
                    disposed
                );

                return Icon.Height;
            }
        }



        public abstract GBaseIcon<T> Clone();



        public static bool operator ==(GBaseIcon<T> left, GBaseIcon<T> right)
        {
            return ReferenceEquals(left, right);
        }

        public static bool operator !=(GBaseIcon<T> left, GBaseIcon<T> right)
        {
            return !(left == right);
        }



        public override bool Equals(object obj)
        {
            if (!(obj is GBaseIcon<T> other))
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
                "GBaseIcon: X={0}, Y={1}, Disposed={2}",
                X,
                Y,
                disposed
            );
        }
    }
}
