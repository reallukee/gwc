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
 * Nome file : GBaseEllipse.cs
 *
 * Titolo    : GBASEELLIPSE
 * Sommario  : Contiene l'implementazione della
 *             classe GBaseEllipse.
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
using System.Windows.Forms;

namespace Reallukee.GWC.Internal
{
    internal abstract class GBaseEllipse<T>
    {
        public GBaseEllipse(
            T x,
            T y,
            T width,
            T height
        )
        {
            this.X      = x;
            this.Y      = y;
            this.Width  = width;
            this.Height = height;
        }

        public GBaseEllipse(GBaseEllipse<T> other)
        {
            ThrowIfArgumentNull(
                nameof(other),
                other
            );

            this.X      = other.X;
            this.Y      = other.Y;
            this.Width  = other.Width;
            this.Height = other.Height;
        }



        protected static void ThrowIfArgumentNull(
            string name, object value
        )
        {
            if (value == null)
            {
                throw new ArgumentNullException(
                    name,
                    "Object cannot null."
                );
            }
        }



        public T X
        {
            get;
            set;
        }

        public T Y
        {
            get;
            set;
        }

        public T Width
        {
            get;
            set;
        }

        public T Height
        {
            get;
            set;
        }



        public static bool operator ==(GBaseEllipse<T> left, GBaseEllipse<T> right)
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

            return comparer.Equals(left.X,      right.X     ) &&
                   comparer.Equals(left.Y,      right.Y     ) &&
                   comparer.Equals(left.Width,  right.Width ) &&
                   comparer.Equals(left.Height, right.Height);
        }

        public static bool operator !=(GBaseEllipse<T> left, GBaseEllipse<T> right)
        {
            return !(left == right);
        }



        public override bool Equals(object obj)
        {
            if (!(obj is GBaseEllipse<T> other))
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

                hash *= 23 + comparer.GetHashCode(X);
                hash *= 23 + comparer.GetHashCode(Y);
                hash *= 23 + comparer.GetHashCode(Width);
                hash *= 23 + comparer.GetHashCode(Height);

                return hash;
            }
        }

        public override string ToString()
        {
            return string.Format(
                "GBaseEllipse<{0}>: X={1}, Y={2}, Width={3}, Height={4}",
                typeof(T).Name,
                X,
                Y,
                Width,
                Height
            );
        }
    }
}
