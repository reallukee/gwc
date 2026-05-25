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
    internal class BaseImage : IRenderable, IDisposable
    {
        private bool disposed;

        public BaseImage(int x, int y, Image image)
        {
            ThrowIfArgumentNull(nameof(image), image);

            this.X     = x;
            this.Y     = y;
            this.Image = (Image)image.Clone();

            disposed = false;
        }

        public BaseImage(Image image) : this(0, 0, image)
        {

        }

        public BaseImage(BaseImage other)
        {
            ThrowIfArgumentNull(nameof(other), other);

            ThrowIfObjectDisposed(nameof(other), other.disposed);

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

        private Image Image
        {
            get;
            set;
        }



        public int Width
        {
            get
            {
                ThrowIfObjectDisposed(nameof(BaseImage), disposed);

                return Image.Width;
            }
        }

        public int Height
        {
            get
            {
                ThrowIfObjectDisposed(nameof(BaseImage), disposed);

                return Image.Height;
            }
        }



        public Rectangle Bounds
        {
            get
            {
                ThrowIfObjectDisposed(nameof(BaseImage), disposed);

                return new Rectangle(X, Y, Image.Width, Image.Height);
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
                ThrowIfObjectDisposed(nameof(BaseImage), disposed);

                return new Size(Image.Width, Image.Height);
            }
        }



        public BaseImage Clone()
        {
            return new BaseImage(this);
        }



        public void Render(Graphics g)
        {
            ThrowIfObjectDisposed(nameof(BaseImage), disposed);

            g.DrawImage(Image, X, Y);
        }



        public static bool operator ==(BaseImage left, BaseImage right)
        {
            return ReferenceEquals(left, right);
        }

        public static bool operator !=(BaseImage left, BaseImage right)
        {
            return !(left == right);
        }



        public override bool Equals(object obj)
        {
            if (!(obj is BaseImage other))
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
                "BaseImage: X={0}, Y={1}, Disposed={2}",
                X,
                Y,
                disposed
            );
        }
    }
}
