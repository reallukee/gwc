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
 * Nome file : BorderEllipse.cs
 *
 * Titolo    : BORDERELLIPSE
 * Sommario  : Contiene l'implementazione della
 *             classe BorderEllipse.
 *
 * Autore    : Luca Pollicino
 *             (https://github.com/reallukee)
 * Versione  : v0.6.0
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
    internal class BorderEllipse : BaseEllipse, IRenderable, IBorderColor
    {
        public BorderEllipse(Color borderColor, int x, int y, int width, int height) : base(x, y, width, height)
        {
            this.BorderColor = borderColor;
        }

        public BorderEllipse(Color borderColor, Point location, Size size) : base(location, size)
        {
            this.BorderColor = borderColor;
        }

        public BorderEllipse(int x, int y, int width, int height) : this(Color.Black, x, y, width, height)
        {

        }

        public BorderEllipse(Point location, Size size) : this(Color.Black, location, size)
        {

        }

        public BorderEllipse() : this(Color.Black, 0, 0, 0, 0)
        {

        }

        public BorderEllipse(BorderEllipse other) : base(other)
        {
            ThrowIfArgumentNull(nameof(other), other);

            this.BorderColor = other.BorderColor;
        }



        public Color BorderColor
        {
            get;
            set;
        }



        public void Render(Graphics g)
        {
            using (Pen border = new Pen(BorderColor))
            {
                g.DrawEllipse(border, X - Width / 2, Y - Height / 2, Width, Height);
            }
        }



        public static bool operator ==(BorderEllipse left, BorderEllipse right)
        {
            if (ReferenceEquals(left, right))
            {
                return true;
            }

            if (ReferenceEquals(left, null) || ReferenceEquals(right, null))
            {
                return false;
            }

            BaseEllipse baseLeft = left;
            BaseEllipse baseRight = right;

            if (baseLeft == baseRight)
            {
                return left.BorderColor == right.BorderColor;
            }

            return false;
        }

        public static bool operator !=(BorderEllipse left, BorderEllipse right)
        {
            return !(left == right);
        }



        public override bool Equals(object obj)
        {
            if (!(obj is BorderEllipse other))
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

                hash = hash * 23 + BorderColor.GetHashCode();
                hash = hash * 23 + X;
                hash = hash * 23 + Y;
                hash = hash * 23 + Width;
                hash = hash * 23 + Height;

                return hash;
            }
        }

        public override string ToString()
        {
            return string.Format(
                "BorderEllipse: BorderColor={0}, X={1}, Y={2}, Width={3}, Height={4}",
                BorderColor,
                X,
                Y,
                Width,
                Height
            );
        }
    }
}
