//
// :.:.:.
// GWC
// v0.1.0
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
    public class FillRectangle : Rectangle, IFigure, IFillColor
    {
        public FillRectangle(Color fillColor, int x, int y, int width, int height) : base(x, y, width, height)
        {
            FillColor = fillColor;
        }

        public FillRectangle(int x, int y, int width, int height) : base(x, y, width, height)
        {
            FillColor = Color.Red;
        }

        private Color fillColor;

        public Color FillColor
        {
            get => fillColor;
            set => fillColor = value;
        }

        public void Render(Graphics g)
        {
            using (SolidBrush fill = new SolidBrush(fillColor))
            {
                g.FillRectangle(fill, X, Y, Width, Height);
            }
        }

        public override bool Equals(object obj)
        {
            FillRectangle borderRectangle = obj as FillRectangle;

            if (borderRectangle == null)
            {
                return false;
            }

            return FillColor == borderRectangle.fillColor &&
                   X         == borderRectangle.X         &&
                   Y         == borderRectangle.Y         &&
                   Width     == borderRectangle.Width     &&
                   Height    == borderRectangle.Height;
        }

        public override int GetHashCode()
        {
            unchecked
            {
                int hash = 17;

                hash = hash * 23 + fillColor.GetHashCode();
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
