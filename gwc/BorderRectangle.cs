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
 * Nome file : BorderRectangle.cs
 *
 * Titolo    : BORDERRECTANGLE
 * Sommario  : Contiene l'implementazione della
 *             classe BorderRectangle.
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
    internal class BorderRectangle : BaseRectangle, IRenderable, IBorderColor
    {
        public BorderRectangle(Color borderColor, int x, int y, int width, int height) : base(x, y, width, height)
        {
            this.BorderColor = borderColor;
        }

        public BorderRectangle(Color borderColor, Point location, Size size) : base(location, size)
        {
            this.BorderColor = borderColor;
        }

        public BorderRectangle(int x, int y, int width, int height) : this(Color.Black, x, y, width, height)
        {

        }

        public BorderRectangle(Point location, Size size) : this(Color.Black, location, size)
        {

        }

        public BorderRectangle() : this(Color.Black, 0, 0, 0, 0)
        {

        }

        public BorderRectangle(BorderRectangle other) : base(other)
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
                g.DrawRectangle(border, X, Y, Width, Height);
            }
        }



        public static bool operator ==(BorderRectangle left, BorderRectangle right)
        {
            if (ReferenceEquals(left, right))
            {
                return true;
            }

            if (ReferenceEquals(left, null) || ReferenceEquals(right, null))
            {
                return false;
            }

            BaseRectangle baseLeft = left;
            BaseRectangle baseRight = right;

            if (baseLeft == baseRight)
            {
                return left.BorderColor == right.BorderColor;
            }

            return false;
        }

        public static bool operator !=(BorderRectangle left, BorderRectangle right)
        {
            return !(left == right);
        }



        public override bool Equals(object obj)
        {
            if (!(obj is BorderRectangle other))
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
                "BorderRectangle: BorderColor={0}, X={1}, Y={2}, Width={3}, Height={4}",
                BorderColor,
                X,
                Y,
                Width,
                Height
            );
        }
    }
}
