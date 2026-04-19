//
// :.:.:.
// GWC
// v0.3.0
// :.:.:.
//
// https://github.com/reallukee/gwc
//
// FillEllipse.cs
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
    internal class FillEllipse : BaseEllipse, IRenderable, IFillColor
    {
        public FillEllipse(Color fillColor, int x, int y, int width, int height) : base(x, y, width, height)
        {
            FillColor = fillColor;
        }

        public FillEllipse(Color fillColor, Point location, Size size) : base(location, size)
        {
            FillColor = fillColor;
        }

        public FillEllipse(int x, int y, int width, int height) : this(Color.Green, x, y, width, height) { }

        public FillEllipse(Point location, Size size) : this(Color.Green, location, size) { }

        public FillEllipse() : this(Color.Green, 0, 0, 0, 0) { }



        public Color FillColor
        {
            get;
            set;
        }



        public void Render(Graphics g)
        {
            using (SolidBrush fill = new SolidBrush(FillColor))
            {
                g.FillEllipse(fill, X - Width / 2, Y - Height / 2, Width, Height);
            }
        }



        public static bool operator ==(FillEllipse left, FillEllipse right)
        {
            if (ReferenceEquals(left, right))
            {
                return true;
            }

            if (left == null || right == null)
            {
                return false;
            }

            BaseEllipse baseLeft = left;
            BaseEllipse baseRight = right;

            if (baseLeft == baseRight)
            {
                return left.FillColor == right.FillColor;
            }

            return false;
        }

        public static bool operator !=(FillEllipse left, FillEllipse right)
        {
            return !(left == right);
        }



        public override bool Equals(object obj)
        {
            FillEllipse other = obj as FillEllipse;

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
                "FillEllipse: FillColor={0}, X={1}, Y={2}, Width={3}, Height={4}",
                FillColor,
                X,
                Y,
                Width,
                Height
            );
        }
    }
}
