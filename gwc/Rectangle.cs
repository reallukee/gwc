//
// :.:.:.
// GWC
// v0.1.0
// :.:.:.
//
// https://github.com/reallukee/gwc
//
// Rectangle.cs
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
    public class Rectangle
    {
        public Rectangle(int x, int y, int width, int height)
        {
            X      = x;
            Y      = y;
            Width  = width;
            Height = height;
        }

        private int x;

        public int X
        {
            get => x;
            set => x = value;
        }

        private int y;

        public int Y
        {
            get => y;
            set => y = value;
        }

        private int width;

        public int Width
        {
            get => width;
            set => width = value;
        }

        private int height;

        public int Height
        {
            get => height;
            set => height = value;
        }

        public override bool Equals(object obj)
        {
            Rectangle rectangle = obj as Rectangle;

            if (rectangle == null)
            {
                return false;
            }

            return X      == rectangle.X      &&
                   Y      == rectangle.Y      &&
                   Width  == rectangle.Width  &&
                   Height == rectangle.Height;
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
                "Rectangle: X={0}, Y={1}, Width={2}, Height={3}",
                X,
                Y,
                Width,
                Height
            );
        }
    }
}
