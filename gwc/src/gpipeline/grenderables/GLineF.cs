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
 * Nome file : GLineF.cs
 *
 * Titolo    : GLINEF
 * Sommario  : Contiene l'implementazione della
 *             classe GLineF.
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
    internal class GLineF : GBaseLine<float>, IGBorderColor, IGRenderable
    {
        public GLineF(
            Color borderColor,
            float x1,
            float y1,
            float x2,
            float y2
        ) : base(x1, y1, x2, y2)
        {
            this.BorderColor = borderColor;
        }

        public GLineF(
            Color  borderColor,
            PointF location1,
            PointF location2
        ) : base(location1.X, location1.Y, location2.X, location2.Y)
        {
            this.BorderColor = borderColor;
        }

        public GLineF(GLineF other)
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



        public override GObject<float> Clone()
        {
            return new GLineF(this);
        }



        public void Render(Graphics g)
        {
            using (Pen border = new Pen(BorderColor))
            {
                g.DrawLine(border, X1, Y1, X2, Y2);
            }
        }



        public static bool operator ==(GLineF left, GLineF right)
        {
            if (ReferenceEquals(left, right))
            {
                return true;
            }

            if (ReferenceEquals(left, null) || ReferenceEquals(right, null))
            {
                return false;
            }

            if (!(left as GBaseLine<float> == right as GBaseLine<float>))
            {
                return false;
            }

            return left.BorderColor == right.BorderColor;
        }

        public static bool operator !=(GLineF left, GLineF right)
        {
            return !(left == right);
        }



        public override bool Equals(object obj)
        {
            if (!(obj is GLineF other))
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
                "GLineF: X1={0}, Y1={1}, X2={2}, Y2={3}, BorderColor={4}",
                X1,
                Y1,
                X2,
                Y2,
                BorderColor
            );
        }
    }
}
