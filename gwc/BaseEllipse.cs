//
// :.:.:.
// GWC
// v0.3.1
// :.:.:.
//
// https://github.com/reallukee/gwc
//
// Ellipse.cs
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
    internal class BaseEllipse : IFigure
    {
        public BaseEllipse(int x, int y, int width, int height)
        {
            this.X      = x;
            this.Y      = y;
            this.Width  = width;
            this.Height = height;
        }

        public BaseEllipse(Point location, Size size)
        {
            this.X      = location.X;
            this.Y      = location.Y;
            this.Width  = size.Width;
            this.Height = size.Height;
        }

        public BaseEllipse() : this(0, 0, 0, 0) { }



        public int X
        {
            get;
            set;
        }

        public int Y
        {
            get;
            set;
        }

        public int Width
        {
            get;
            set;
        }

        public int Height
        {
            get;
            set;
        }



        public Rectangle Bounds   => new Rectangle(X, Y, Width, Height);
        public Size      Size     => new Size     (Width, Height);
        public Point     Location => new Point    (X, Y);



        public static bool operator ==(BaseEllipse left, BaseEllipse right)
        {
            if (ReferenceEquals(left, right))
            {
                return true;
            }

            if (left == null || right == null)
            {
                return false;
            }

            return left.X      == right.X      &&
                   left.Y      == right.Y      &&
                   left.Width  == right.Width  &&
                   left.Height == right.Height;
        }

        public static bool operator !=(BaseEllipse left, BaseEllipse right)
        {
            return !(left == right);
        }



        public override bool Equals(object obj)
        {
            BaseEllipse other = obj as BaseEllipse;

            return this == other;
        }

        public override int GetHashCode()
        {
            unchecked
            {
                int hash = 17;

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
                "Ellipse: X={0}, Y={1}, Width={2}, Height={3}",
                X,
                Y,
                Width,
                Height
            );
        }
    }
}
