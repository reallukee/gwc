//
// GWC
//
//  Version : 0.1.0
//  MIT License
//  FillRectangle.cs
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
            get
            {
                return fillColor;
            }

            set
            {
                fillColor = value;
            }
        }

        public void Render(Graphics g)
        {
            SolidBrush fill = new SolidBrush(fillColor);

            g.FillRectangle(fill, X, Y, Width, Height);

            fill.Dispose();
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
            return FillColor.GetHashCode() ^ X ^ Y ^ Width ^ Height;
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
