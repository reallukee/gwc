//
// :.:.:.
// GWC
// v0.3.0
// :.:.:.
//
// https://github.com/reallukee/gwc
//
// FillRectangle.cs
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
    internal class FillRectangle : BaseRectangle, IRenderable, IFillColor
    {
        public FillRectangle(Color fillColor, int x, int y, int width, int height) : base(x, y, width, height)
        {
            FillColor = fillColor;
        }

        public FillRectangle(Color fillColor, Point location, Size size) : base(location, size)
        {
            FillColor = fillColor;
        }

        public FillRectangle(int x, int y, int width, int height) : this(Color.Green, x, y, width, height) { }

        public FillRectangle(Point location, Size size) : this(Color.Green, location, size) { }

        public FillRectangle() : this(Color.Green, 0, 0, 0, 0) { }



        public Color FillColor
        {
            get;
            set;
        }



        public void Render(Graphics g)
        {
            using (SolidBrush fill = new SolidBrush(FillColor))
            {
                g.FillRectangle(fill, X, Y, Width, Height);
            }
        }



        public static bool operator ==(FillRectangle left, FillRectangle right)
        {
            if (ReferenceEquals(left, right))
            {
                return true;
            }

            if (left == null || right == null)
            {
                return false;
            }

            BaseRectangle baseLeft = left;
            BaseRectangle baseRight = right;

            if (baseLeft == baseRight)
            {
                return left.FillColor == right.FillColor;
            }

            return false;
        }

        public static bool operator !=(FillRectangle left, FillRectangle right)
        {
            return !(left == right);
        }



        public override bool Equals(object obj)
        {
            FillRectangle other = obj as FillRectangle;

            return this == other;
        }

        public override int GetHashCode()
        {
            unchecked
            {
                int hash = 17;

                hash = hash * 23 + FillColor.GetHashCode();
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
                "FillRectangle: FillColor={0}, X={1}, Y={2}, Width={3}, Height={4}",
                FillColor,
                X,
                Y,
                Width,
                Height
            );
        }
    }
}
