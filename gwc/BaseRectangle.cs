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
 * Nome file : BaseRectangle.cs
 *
 * Titolo    : BASERECTANGLE
 * Sommario  : Contiene l'implementazione della
 *             classe BaseRectangle.
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
    internal class BaseRectangle : IFigure
    {
        public BaseRectangle(int x, int y, int width, int height)
        {
            this.X      = x;
            this.Y      = y;
            this.Width  = width;
            this.Height = height;
        }

        public BaseRectangle(Point location, Size size) : this(
            location.X,
            location.Y,
            size.Width,
            size.Height
        )
        {

        }

        public BaseRectangle() : this(0, 0, 0, 0)
        {

        }

        public BaseRectangle(BaseRectangle other)
        {
            ThrowIfArgumentNull(nameof(other), other);

            this.X      = other.X;
            this.Y      = other.Y;
            this.Width  = other.Width;
            this.Height = other.Height;
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

        private int width;

        public int Width
        {
            get
            {
                return width;
            }

            set
            {
                ThrowIfArgumentOutOfRange(nameof(Width), value, IsLessThen(0));

                width = value;
            }
        }

        private int height;

        public int Height
        {
            get
            {
                return height;
            }

            set
            {
                ThrowIfArgumentOutOfRange(nameof(Height), value, IsLessThen(0));

                height = value;
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



        public static bool operator ==(BaseRectangle left, BaseRectangle right)
        {
            if (ReferenceEquals(left, right))
            {
                return true;
            }

            if (ReferenceEquals(left, null) || ReferenceEquals(right, null))
            {
                return false;
            }

            return left.X      == right.X      &&
                   left.Y      == right.Y      &&
                   left.Width  == right.Width  &&
                   left.Height == right.Height;
        }

        public static bool operator !=(BaseRectangle left, BaseRectangle right)
        {
            return !(left == right);
        }



        public override bool Equals(object obj)
        {
            if (!(obj is BaseRectangle other))
            {
                return false;
            }

            return this == other;
        }

        public override int GetHashCode()
        {
            unchecked
            {
                int hash = 17;

                hash = hash * 23 + X;
                hash = hash * 23 + Y;
                hash = hash * 23 + Width;
                hash = hash * 23 + Height;

                return hash;
            }
        }

        public override string ToString()
        {
            return string.Format(
                "Rectangle: X={0}, Y={1}, Width={2}, Height={3}",
                X,
                Y,
                Width,
                Height
            );
        }
    }
}
