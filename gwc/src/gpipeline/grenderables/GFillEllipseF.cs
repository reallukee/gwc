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
 * Nome file : GFillEllipseF.cs
 *
 * Titolo    : GFILLELLIPSEF
 * Sommario  : Contiene l'implementazione della
 *             classe GFillEllipseF.
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
    internal class GFillEllipseF : GEllipseF, IGFillColor, IGRenderable, IGFigureF
    {
        public GFillEllipseF(
            Color fillColor,
            float x,
            float y,
            float width,
            float height
        ) : base(x, y, width, height)
        {
            this.FillColor = fillColor;
        }

        public GFillEllipseF(
            Color fillColor,
            PointF location,
            SizeF size
        ) : base(location.X, location.Y, size.Width, size.Height)
        {
            this.FillColor = fillColor;
        }

        public GFillEllipseF(GFillEllipseF other)
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



        public static bool operator ==(GFillEllipseF left, GFillEllipseF right)
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

            return left.FillColor == right.FillColor;
        }

        public static bool operator !=(GFillEllipseF left, GFillEllipseF right)
        {
            return !(left == right);
        }



        public override bool Equals(object obj)
        {
            if (!(obj is GFillEllipseF other))
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
                "GFillEllipseF: X={0}, Y={1}, Width={2}, Height={3}, FillColor={4}",
                X,
                Y,
                Width,
                Height,
                FillColor
            );
        }
    }
}
