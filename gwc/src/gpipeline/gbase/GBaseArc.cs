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
 * Nome file : GBaseArc.cs
 *
 * Titolo    : GBASEARC
 * Sommario  : Contiene l'implementazione della
 *             classe GBaseArc.
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
using Reallukee.GWC.GPipeline.GProperties;

namespace Reallukee.GWC.GPipeline.GBase
{
    internal abstract class GBaseArc<T> : GObject<T>
    {
        public GBaseArc(
            T x1,
            T y1,
            T x2,
            T y2,
            T startAngle,
            T sweepAngle
        )
        {
            this.X1         = x1;
            this.Y1         = y1;
            this.X2         = x2;
            this.Y2         = y2;
            this.StartAngle = startAngle;
            this.SweepAngle = sweepAngle;
        }

        public GBaseArc(GBaseArc<T> other)
        {
            ThrowIfArgumentNull(
                nameof(other),
                other
            );

            this.X1         = other.X1;
            this.Y1         = other.Y1;
            this.X2         = other.X2;
            this.Y2         = other.Y2;
            this.StartAngle = other.StartAngle;
            this.SweepAngle = other.SweepAngle;
        }



        public T X1
        {
            get;
            private set;
        }

        public T Y1
        {
            get;
            private set;
        }

        public T X2
        {
            get;
            private set;
        }

        public T Y2
        {
            get;
            private set;
        }

        public T StartAngle
        {
            get;
            private set;
        }

        public T SweepAngle
        {
            get;
            private set;
        }



        public static bool operator ==(GBaseArc<T> left, GBaseArc<T> right)
        {
            if (ReferenceEquals(left, right))
            {
                return true;
            }

            if (ReferenceEquals(left, null) || ReferenceEquals(right, null))
            {
                return false;
            }

            var comparer = EqualityComparer<T>.Default;

            return comparer.Equals(left.X1,         right.X1        ) &&
                   comparer.Equals(left.Y1,         right.Y1        ) &&
                   comparer.Equals(left.X2,         right.X2        ) &&
                   comparer.Equals(left.Y2,         right.Y2        ) &&
                   comparer.Equals(left.StartAngle, right.StartAngle) &&
                   comparer.Equals(left.SweepAngle, right.SweepAngle);
        }

        public static bool operator !=(GBaseArc<T> left, GBaseArc<T> right)
        {
            return !(left == right);
        }



        public override bool Equals(object obj)
        {
            if (!(obj is GBaseArc<T> other))
            {
                return false;
            }

            return this == other;
        }

        public override int GetHashCode()
        {
            var comparer = EqualityComparer<T>.Default;

            unchecked
            {
                int hash = 17;

                hash *= 23 + comparer.GetHashCode(X1);
                hash *= 23 + comparer.GetHashCode(Y1);
                hash *= 23 + comparer.GetHashCode(X2);
                hash *= 23 + comparer.GetHashCode(Y2);
                hash *= 23 + comparer.GetHashCode(StartAngle);
                hash *= 23 + comparer.GetHashCode(SweepAngle);

                return hash;
            }
        }

        public override string ToString()
        {
            return string.Format(
                "GBaseArc<{0}>: X1={1}, Y1={2}, X2={3}, Y2={4}, StartAngle={5}, SweepAngle={6}",
                typeof(T).Name,
                X1,
                Y1,
                X2,
                Y2,
                StartAngle,
                SweepAngle
            );
        }
    }
}
