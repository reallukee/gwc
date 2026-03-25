//
// :.:.:.
// GWC
// v0.1.0
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
    public class BorderRectangle : Rectangle, IFigure, IBorderColor
    {
        public BorderRectangle(Color borderColor, int x, int y, int width, int height) : base(x, y, width, height)
        {
            BorderColor = borderColor;
        }

        public BorderRectangle(int x, int y, int width, int height) : base(x, y, width, height)
        {
            BorderColor = Color.Black;
        }

        private Color borderColor;

        public Color BorderColor
        {
            get => borderColor;
            set => borderColor = value;
        }

        public void Render(Graphics g)
        {
            using (Pen border = new Pen(borderColor))
            {
                g.DrawRectangle(border, X, Y, Width, Height);
            }
        }

        public override bool Equals(object obj)
        {
            BorderRectangle borderRectangle = obj as BorderRectangle;

            if (borderRectangle == null)
            {
                return false;
            }

            return BorderColor == borderRectangle.borderColor &&
                   X           == borderRectangle.X           &&
                   Y           == borderRectangle.Y           &&
                   Width       == borderRectangle.Width       &&
                   Height      == borderRectangle.Height;
        }

        public override int GetHashCode()
        {
            unchecked
            {
                int hash = 17;

                hash = hash * 23 + borderColor.GetHashCode();
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
