//
// :.:.:.
// GWC
// v0.1.0
// :.:.:.
//
// https://github.com/reallukee/gwc
//
// Canvas.cs
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
    public sealed class Canvas : IDisposable, IFillColor, IBorderColor
    {
        internal const int MaxBufferLength = 10000;

        public Canvas(int width, int height)
        {
            if (width <= 0)
            {
                throw new ArgumentOutOfRangeException(nameof(width), "");
            }

            if (height <= 0)
            {
                throw new ArgumentOutOfRangeException(nameof(height), "");
            }

            bitmap = new Bitmap(width, height);

            buffer = new ConcurrentQueue<IFigure>();
        }

        public Canvas() : this(800, 600) {}

        ~Canvas()
        {
            Dispose();
        }

        public void Dispose()
        {
            if (bitmap != null)
            {
                bitmap.Dispose();
            }
        }



        private Bitmap bitmap;

        internal Bitmap Bitmap
        {
            get => bitmap;
            set => bitmap = value;
        }

        private ConcurrentQueue<IFigure> buffer;

        internal ConcurrentQueue<IFigure> Buffer
        {
            get => buffer;
            set => buffer = value;
        }

        private Color fillColor;

        public Color FillColor
        {
            get => fillColor;
            set => fillColor = value;
        }

        private Color borderColor;

        public Color BorderColor
        {
            get => borderColor;
            set => borderColor = value;
        }



        public bool DrawFigure(IFigure figure)
        {
            if (buffer.Count > MaxBufferLength)
            {
                return false;
            }

            buffer.Enqueue(figure);

            return true;
        }



        public bool DrawBorderSquare(int x, int y, int side) => DrawBorderRectangle(x, y, side, side);
        public bool DrawFillSquare  (int x, int y, int side) => DrawFillRectangle  (x, y, side, side);

        public bool DrawBorderRectangle(int x, int y, int width, int height)
        {
            IFigure borderRectangle = new BorderRectangle(BorderColor, x, y, width, height);

            return DrawFigure(borderRectangle);
        }

        public bool DrawFillRectangle(int x, int y, int width, int height)
        {
            IFigure fillRectangle = new FillRectangle(FillColor, x, y, width, height);

            return DrawFigure(fillRectangle);
        }
    }
}
