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
 * Nome file : GBaseClear.cs
 *
 * Titolo    : GBASECLEAR
 * Sommario  : Contiene l'implementazione della
 *             classe GBaseClear.
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
    internal abstract class GBaseClear<T> : GObject<T>, IGBackColor
    {
        public GBaseClear(
            T     x,
            T     y,
            T     width,
            T     height,
            Color backColor
        )
        {
            this.X         = x;
            this.Y         = y;
            this.Width     = width;
            this.Height    = height;
            this.BackColor = backColor;
        }

        public GBaseClear(GBaseClear<T> other)
        {
            ThrowIfArgumentNull(
                nameof(other),
                other
            );

            this.X         = other.X;
            this.Y         = other.Y;
            this.Width     = other.Width;
            this.Height    = other.Height;
            this.BackColor = other.BackColor;
        }



        public T X
        {
            get;
            private set;
        }

        public T Y
        {
            get;
            private set;
        }

        public T Width
        {
            get;
            private set;
        }

        public T Height
        {
            get;
            private set;
        }

        public Color BackColor
        {
            get;
            private set;
        }



        public static bool operator ==(GBaseClear<T> left, GBaseClear<T> right)
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
                   comparer.Equals(left.Height, right.Height) &&
                   left.BackColor == right.BackColor;
        }

        public static bool operator !=(GBaseClear<T> left, GBaseClear<T> right)
        {
            return !(left == right);
        }



        public override bool Equals(object obj)
        {
            if (!(obj is GBaseClear<T> other))
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
                hash *= 23 + BackColor.GetHashCode();

                return hash;
            }
        }

        public override string ToString()
        {
            return string.Format(
                "GBaseClear<{0}>: X={1}, Y={2}, Width={3}, Height={4}, BackColor={5}",
                typeof(T).Name,
                X,
                Y,
                Width,
                Height,
                BackColor
            );
        }
    }
}
