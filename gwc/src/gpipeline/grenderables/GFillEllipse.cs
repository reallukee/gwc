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
 * Nome file : GFillEllipse.cs
 *
 * Titolo    : GFILLELLIPSE
 * Sommario  : Contiene l'implementazione della
 *             classe GFillEllipse.
 *
 * Autore    : Luca Pollicino
 *             (https://github.com/reallukee)
 * Versione  : v0.7.0
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

using Reallukee.GWC.GPipeline.GCore;
using Reallukee.GWC.GPipeline.GBase;
using Reallukee.GWC.GPipeline.GProperties;
using Reallukee.GWC.GPipeline.GFigures;

namespace Reallukee.GWC.GPipeline.GRenderable
{
    internal class GFillEllipse : GEllipse, IGFillColor, IGRenderable, IGFigure
    {
        public GFillEllipse(
            Color fillColor,
            int   x,
            int   y,
            int   width,
            int   height
        ) : base(x, y, width, height)
        {
            this.FillColor = fillColor;
        }

        public GFillEllipse(
            Color fillColor,
            Point location,
            Size size
        ) : base(location.X, location.Y, size.Width, size.Height)
        {
            this.FillColor = fillColor;
        }

        public GFillEllipse(GFillEllipse other)
            : base(other)
        {
            ThrowIfArgumentNull(
                nameof(other),
                other
            );

            this.FillColor = other.FillColor;
        }



        public Color FillColor
        {
            get;
            private set;
        }



        public void Render(Graphics g)
        {
            using (SolidBrush fill = new SolidBrush(FillColor))
            {
                g.FillEllipse(fill, X - Width / 2, Y - Height / 2, Width, Height);
            }
        }



        public static bool operator ==(GFillEllipse left, GFillEllipse right)
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

            return left.FillColor == right.FillColor;
        }

        public static bool operator !=(GFillEllipse left, GFillEllipse right)
        {
            return !(left == right);
        }



        public override bool Equals(object obj)
        {
            if (!(obj is GFillEllipse other))
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
                hash *= 23 + FillColor.GetHashCode();

                return hash;
            }
        }

        public override string ToString()
        {
            return string.Format(
                "GFillEllipse: X={0}, Y={1}, Width={2}, Height={3}, FillColor={4}",
                X,
                Y,
                Width,
                Height,
                FillColor
            );
        }
    }
}
