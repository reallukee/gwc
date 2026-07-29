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
 * Nome file : GBorderRectangle.cs
 *
 * Titolo    : GBORDERRECTANGLE/F
 * Sommario  : Contiene l'implementazione della
 *             classe GBorderRectangle/F.
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
    internal class GBorderRectangle : GRectangle, IGBorderColor, IGRenderable, IGFigure
    {
        public GBorderRectangle(
            Color BorderColor,
            int   x,
            int   y,
            int   width,
            int   height
        ) : base(x, y, width, height)
        {
            this.BorderColor = BorderColor;
        }

        public GBorderRectangle(
            Color BorderColor,
            Point location,
            Size size
        ) : base(location.X, location.Y, size.Width, size.Height)
        {
            this.BorderColor = BorderColor;
        }

        public GBorderRectangle(GBorderRectangle other)
            : base(other)
        {
            ThrowIfArgumentNull(
                nameof(other),
                other
            );

            this.BorderColor = other.BorderColor;
        }



        public Color BorderColor
        {
            get;
            private set;
        }



        public void Render(Graphics g)
        {
            using (Pen border = new Pen(BorderColor))
            {
                g.DrawRectangle(border, X, Y, Width, Height);
            }
        }



        public static bool operator ==(GBorderRectangle left, GBorderRectangle right)
        {
            if (ReferenceEquals(left, right))
            {
                return true;
            }

            if (ReferenceEquals(left, null) || ReferenceEquals(right, null))
            {
                return false;
            }

            if (!(left as GBaseRectangle<int> == right as GBaseRectangle<int>))
            {
                return false;
            }

            return left.BorderColor == right.BorderColor;
        }

        public static bool operator !=(GBorderRectangle left, GBorderRectangle right)
        {
            return !(left == right);
        }



        public override bool Equals(object obj)
        {
            if (!(obj is GBorderRectangle other))
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

                hash *= 23 + X.GetHashCode();
                hash *= 23 + Y.GetHashCode();
                hash *= 23 + Width.GetHashCode();
                hash *= 23 + Height.GetHashCode();
                hash *= 23 + BorderColor.GetHashCode();

                return hash;
            }
        }

        public override string ToString()
        {
            return string.Format(
                "GBorderRectangle: X={0}, Y={1}, Width={2}, Height={3}, BorderColor={4}",
                X,
                Y,
                Width,
                Height,
                BorderColor
            );
        }
    }



    internal class GBorderRectangleF : GRectangleF, IGBorderColor, IGRenderable, IGFigureF
    {
        public GBorderRectangleF(
            Color BorderColor,
            float x,
            float y,
            float width,
            float height
        ) : base(x, y, width, height)
        {
            this.BorderColor = BorderColor;
        }

        public GBorderRectangleF(
            Color BorderColor,
            PointF location,
            SizeF size
        ) : base(location.X, location.Y, size.Width, size.Height)
        {
            this.BorderColor = BorderColor;
        }

        public GBorderRectangleF(GBorderRectangleF other)
            : base(other)
        {
            ThrowIfArgumentNull(
                nameof(other),
                other
            );

            this.BorderColor = other.BorderColor;
        }



        public Color BorderColor
        {
            get;
            private set;
        }



        public void Render(Graphics g)
        {
            using (Pen border = new Pen(BorderColor))
            {
                g.DrawRectangle(border, X, Y, Width, Height);
            }
        }



        public static bool operator ==(GBorderRectangleF left, GBorderRectangleF right)
        {
            if (ReferenceEquals(left, right))
            {
                return true;
            }

            if (ReferenceEquals(left, null) || ReferenceEquals(right, null))
            {
                return false;
            }

            if (!(left as GBaseRectangle<float> == right as GBaseRectangle<float>))
            {
                return false;
            }

            return left.BorderColor == right.BorderColor;
        }

        public static bool operator !=(GBorderRectangleF left, GBorderRectangleF right)
        {
            return !(left == right);
        }



        public override bool Equals(object obj)
        {
            if (!(obj is GBorderRectangleF other))
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

                hash *= 23 + X.GetHashCode();
                hash *= 23 + Y.GetHashCode();
                hash *= 23 + Width.GetHashCode();
                hash *= 23 + Height.GetHashCode();
                hash *= 23 + BorderColor.GetHashCode();

                return hash;
            }
        }

        public override string ToString()
        {
            return string.Format(
                "GBorderRectangleF: X={0}, Y={1}, Width={2}, Height={3}, BorderColor={4}",
                X,
                Y,
                Width,
                Height,
                BorderColor
            );
        }
    }
}
