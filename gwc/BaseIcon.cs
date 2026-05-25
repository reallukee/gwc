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
 * Nome file : BaseIcon.cs
 *
 * Titolo    : BASEICON
 * Sommario  : Contiene l'implementazione della
 *             classe BaseIcon.
 *
 * Autore    : Luca Pollicino
 *             (https://github.com/reallukee)
 * Versione  : v0.6.0
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
    internal class BaseIcon : IRenderable, IDisposable
    {
        private bool disposed;

        public BaseIcon(int x, int y, Icon icon)
        {
            ThrowIfArgumentNull(nameof(icon), icon);

            this.X    = x;
            this.Y    = y;
            this.Icon = (Icon)icon.Clone();

            disposed = false;
        }

        public BaseIcon(Icon icon) : this(0, 0, icon)
        {

        }

        public BaseIcon(BaseIcon other)
        {
            ThrowIfArgumentNull(nameof(other), other);

            ThrowIfObjectDisposed(nameof(other), other.disposed);

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



        protected static void ThrowIfObjectDisposed(string name, bool disposed)
        {
            if (disposed)
            {
                string message = "Object is disposed.";

                throw new ArgumentNullException(name, message);
            }
        }



        protected static void ThrowIfArgumentNull(string name, object value)
        {
            if (value == null)
            {
                string message = "Object cannot null.";

                throw new ArgumentNullException(name, message);
            }
        }



        protected delegate (bool Invalid, string Message) RangeCheck(int value);

        protected static RangeCheck IsLessThen(int min)
        {
            return value =>
            {
                if (value < min)
                {
                    string message = $"Value cannot be less than {min}.";

                    return (true, message);
                }

                return (false, null);
            };
        }

        protected static RangeCheck IsGreaterThan(int max)
        {
            return value =>
            {
                if (value > max)
                {
                    string message = $"Value cannot be greater than {max}.";

                    return (true, message);
                }

                return (false, null);
            };
        }

        protected static void ThrowIfArgumentOutOfRange(
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



        private int x;

        public int X
        {
            get
            {
                return x;
            }

            set
            {
                ThrowIfArgumentOutOfRange(nameof(X), value, IsLessThen(0));

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
                ThrowIfArgumentOutOfRange(nameof(Y), value, IsLessThen(0));

                y = value;
            }
        }

        private Icon Icon
        {
            get;
            set;
        }



        public int Width
        {
            get
            {
                ThrowIfObjectDisposed(nameof(BaseIcon), disposed);

                return Icon.Width;
            }
        }

        public int Height
        {
            get
            {
                ThrowIfObjectDisposed(nameof(BaseIcon), disposed);

                return Icon.Height;
            }
        }



        public Rectangle Bounds
        {
            get
            {
                ThrowIfObjectDisposed(nameof(BaseIcon), disposed);

                return new Rectangle(X, Y, Icon.Width, Icon.Height);
            }
        }

        public Point Location
        {
            get
            {
                return new Point(X, Y);
            }
        }

        public Size Size
        {
            get
            {
                ThrowIfObjectDisposed(nameof(BaseIcon), disposed);

                return new Size(Icon.Width, Icon.Height);
            }
        }



        public BaseIcon Clone()
        {
            return new BaseIcon(this);
        }



        public void Render(Graphics g)
        {
            ThrowIfObjectDisposed(nameof(BaseIcon), disposed);

            g.DrawIcon(Icon, X, Y);
        }



        public static bool operator ==(BaseIcon left, BaseIcon right)
        {
            return ReferenceEquals(left, right);
        }

        public static bool operator !=(BaseIcon left, BaseIcon right)
        {
            return !(left == right);
        }



        public override bool Equals(object obj)
        {
            if (!(obj is BaseIcon other))
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
                "BaseIcon: X={0}, Y={1}, Disposed={2}",
                X,
                Y,
                disposed
            );
        }
    }
}
