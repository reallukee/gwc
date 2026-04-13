//
// :.:.:.
// GWC
// v0.3.0
// :.:.:.
//
// https://github.com/reallukee/gwc
//
// BorderRectangle.cs
//  Licenza MIT
//

using System;
using System.Collections;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.ComponentModel;
using System.Diagnostics;
using System.Globalization;
using System.Reflection;
using System.Resources;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading;

using System.Drawing;
using System.Windows.Forms;

namespace Reallukee.GWC
{
    internal class BorderRectangle : Rectangle, IRenderable, IBorderColor
    {
        public BorderRectangle(Color borderColor, int x, int y, int width, int height) : base(x, y, width, height)
        {
            BorderColor = borderColor;
        }

        public BorderRectangle(Color borderColor, Point location, Size size) : base(location, size)
        {
            BorderColor = borderColor;
        }

        public BorderRectangle(int x, int y, int width, int height) : this(Color.Black, x, y, width, height) { }

        public BorderRectangle(Point location, Size size) : this(Color.Black, location, size) { }

        public BorderRectangle() : this(Color.Black, 0, 0, 0, 0) { }



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

            if (left == null || right == null)
            {
                return false;
            }

            Rectangle baseLeft = left;
            Rectangle baseRight = right;

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
            BorderRectangle other = obj as BorderRectangle;

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
