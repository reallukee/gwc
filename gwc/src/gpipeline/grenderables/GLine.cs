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
 * Nome file : GLine.cs
 *
 * Titolo    : GLINE
 * Sommario  : Contiene l'implementazione della
 *             classe GLine.
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
    internal class GLine : GBaseLine<int>, IGBorderColor, IGRenderable
    {
        public GLine(
            Color borderColor,
            int   x1,
            int   y1,
            int   x2,
            int   y2
        ) : base(x1, y1, x2, y2)
        {
            this.BorderColor = borderColor;
        }

        public GLine(
            Color borderColor,
            Point location1,
            Point location2
        ) : base(location1.X, location1.Y, location2.X, location2.Y)
        {
            this.BorderColor = borderColor;
        }

        public GLine(GLine other)
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



        public override GObject<int> Clone()
        {
            return new GLine(this);
        }



        public void Render(Graphics g)
        {
            using (Pen border = new Pen(BorderColor))
            {
                g.DrawLine(border, X1, Y1, X2, Y2);
            }
        }



        public static bool operator ==(GLine left, GLine right)
        {
            if (ReferenceEquals(left, right))
            {
                return true;
            }

            if (ReferenceEquals(left, null) || ReferenceEquals(right, null))
            {
                return false;
            }

            if (!(left as GBaseLine<int> == right as GBaseLine<int>))
            {
                return false;
            }

            return left.BorderColor == right.BorderColor;
        }

        public static bool operator !=(GLine left, GLine right)
        {
            return !(left == right);
        }



        public override bool Equals(object obj)
        {
            if (!(obj is GLine other))
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

                hash *= 23 + X1.GetHashCode();
                hash *= 23 + Y1.GetHashCode();
                hash *= 23 + X2.GetHashCode();
                hash *= 23 + Y2.GetHashCode();
                hash *= 23 + BorderColor.GetHashCode();

                return hash;
            }
        }

        public override string ToString()
        {
            return string.Format(
                "GLine: X1={0}, Y1={1}, X2={2}, Y2={3}, BorderColor={4}",
                X1,
                Y1,
                X2,
                Y2,
                BorderColor
            );
        }
    }
}
