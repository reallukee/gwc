//
// GWC
//
//  Version : 0.1.0
//  MIT License
//  Rectangle.cs
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
            get
            {
                return x;
            }

            set
            {
                x = value;
            }
        }

        private int y;

        public int Y
        {
            get
            {
                return y;
            }

            set
            {
                y = value;
            }
        }

        private int width;

        public int Width
        {
            get
            {
                return width;
            }

            set
            {
                width = value;
            }
        }

        private int height;

        public int Height
        {
            get
            {
                return height;
            }

            set
            {
                height = value;
            }
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
            return X ^ Y ^ Width ^ Height;
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
