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
 * Nome file : GBorderEllipse.cs
 *
 * Titolo    : GBORDERELLIPSE/F
 * Sommario  : Contiene l'implementazione della
 *             classe GBorderEllipse/F.
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
    internal class GBorderEllipse : GEllipse, IGBorderColor, IGRenderable, IGFigure
    {
        public GBorderEllipse(
            Color BorderColor,
            int   x,
            int   y,
            int   width,
            int   height
        ) : base(x, y, width, height)
        {
            this.BorderColor = BorderColor;
        }

        public GBorderEllipse(
            Color BorderColor,
            Point location,
            Size size
        ) : base(location.X, location.Y, size.Width, size.Height)
        {
            this.BorderColor = BorderColor;
        }

        public GBorderEllipse(GBorderEllipse other)
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
                g.DrawEllipse(border, X - Width / 2, Y - Height / 2, Width, Height);
            }
        }



        public static bool operator ==(GBorderEllipse left, GBorderEllipse right)
        {
            if (ReferenceEquals(left, right))
            {
                return true;
            }

            if (ReferenceEquals(left, null) || ReferenceEquals(right, null))
            {
                return false;
            }

            if (!(left as GBaseEllipse<int> == right as GBaseEllipse<int>))
            {
                return false;
            }

            return left.BorderColor == right.BorderColor;
        }

        public static bool operator !=(GBorderEllipse left, GBorderEllipse right)
        {
            return !(left == right);
        }



        public override bool Equals(object obj)
        {
            if (!(obj is GBorderEllipse other))
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
                "GBorderEllipse: X={0}, Y={1}, Width={2}, Height={3}, BorderColor={4}",
                X,
                Y,
                Width,
                Height,
                BorderColor
            );
        }
    }



    internal class GBorderEllipseF : GEllipseF, IGBorderColor, IGRenderable, IGFigureF
    {
        public GBorderEllipseF(
            Color BorderColor,
            float x,
            float y,
            float width,
            float height
        ) : base(x, y, width, height)
        {
            this.BorderColor = BorderColor;
        }

        public GBorderEllipseF(
            Color BorderColor,
            PointF location,
            SizeF size
        ) : base(location.X, location.Y, size.Width, size.Height)
        {
            this.BorderColor = BorderColor;
        }

        public GBorderEllipseF(GBorderEllipseF other)
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
                g.DrawEllipse(border, X - Width / 2, Y - Height / 2, Width, Height);
            }
        }



        public static bool operator ==(GBorderEllipseF left, GBorderEllipseF right)
        {
            if (ReferenceEquals(left, right))
            {
                return true;
            }

            if (ReferenceEquals(left, null) || ReferenceEquals(right, null))
            {
                return false;
            }

            if (!(left as GBaseEllipse<float> == right as GBaseEllipse<float>))
            {
                return false;
            }

            return left.BorderColor == right.BorderColor;
        }

        public static bool operator !=(GBorderEllipseF left, GBorderEllipseF right)
        {
            return !(left == right);
        }



        public override bool Equals(object obj)
        {
            if (!(obj is GBorderEllipseF other))
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
                "GBorderEllipseF: X={0}, Y={1}, Width={2}, Height={3}, BorderColor={4}",
                X,
                Y,
                Width,
                Height,
                BorderColor
            );
        }
    }
}
