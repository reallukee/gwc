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
 * Nome file : GArcF.cs
 *
 * Titolo    : GARCF
 * Sommario  : Contiene l'implementazione della
 *             classe GArcF.
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
    internal class GArcF : GBaseArc<float>, IGBorderColor, IGRenderable
    {
        public GArcF(
            Color borderColor,
            float x1,
            float y1,
            float x2,
            float y2,
            float startAngle,
            float sweepAngle
        ) : base(x1, y1, x2, y2, startAngle, sweepAngle)
        {
            this.BorderColor = borderColor;
        }

        public GArcF(
            Color  borderColor,
            PointF location1,
            PointF location2,
            float  startAngle,
            float  sweepAngle
        ) : base(location1.X, location1.Y, location2.X, location2.Y, startAngle, sweepAngle)
        {
            this.BorderColor = borderColor;
        }

        public GArcF(GArcF other)
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
            return new GArcF(this);
        }



        public void Render(Graphics g)
        {
            using (Pen border = new Pen(BorderColor))
            {
                g.DrawArc(
                    border,
                    X1,
                    Y1,
                    Math.Abs(X2 - X1),
                    Math.Abs(Y2 - Y1),
                    StartAngle,
                    SweepAngle
                );
            }
        }



        public static bool operator ==(GArcF left, GArcF right)
        {
            if (ReferenceEquals(left, right))
            {
                return true;
            }

            if (ReferenceEquals(left, null) || ReferenceEquals(right, null))
            {
                return false;
            }

            if (!(left as GBaseArc<float> == right as GBaseArc<float>))
            {
                return false;
            }

            return left.BorderColor == right.BorderColor;
        }

        public static bool operator !=(GArcF left, GArcF right)
        {
            return !(left == right);
        }



        public override bool Equals(object obj)
        {
            if (!(obj is GArcF other))
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
                hash *= 23 + StartAngle.GetHashCode();
                hash *= 23 + SweepAngle.GetHashCode();
                hash *= 23 + BorderColor.GetHashCode();

                return hash;
            }
        }

        public override string ToString()
        {
            return string.Format(
                "GArcF: X1={0}, Y1={1}, X2={2}, Y2={3}, StartAngle={4}, SweepAngle={5}, BorderColor={6}",
                X1,
                Y1,
                X2,
                Y2,
                StartAngle,
                SweepAngle,
                BorderColor
            );
        }
    }
}
