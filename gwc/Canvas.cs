//
// GWC
//
//  Version : 0.1.0
//  MIT License
//  Canvas.cs
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
        public const int MaxRenderBufferLength = 10000;

        public Canvas(int width, int height)
        {
            bitmap = new Bitmap(width, height);

            buffer = new ConcurrentQueue<IFigure>();
        }

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

        public Bitmap Bitmap
        {
            get
            {
                return bitmap;
            }

            set
            {
                bitmap = value;
            }
        }

        private ConcurrentQueue<IFigure> buffer;

        public ConcurrentQueue<IFigure> Buffer
        {
            get
            {
                return buffer;
            }

            set
            {
                buffer = value;
            }
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

        private Color borderColor;

        public Color BorderColor
        {
            get
            {
                return borderColor;
            }

            set
            {
                borderColor = value;
            }
        }

        public bool DrawBorderRectangle(int x, int y, int width, int height)
        {
            if (buffer.Count > MaxRenderBufferLength)
            {
                return false;
            }

            IFigure borderRectangle = new BorderRectangle(BorderColor, x, y, width, height);

            buffer.Enqueue(borderRectangle);

            return true;
        }

        public bool DrawFillRectangle(int x, int y, int width, int height)
        {
            if (buffer.Count > MaxRenderBufferLength)
            {
                return false;
            }

            IFigure fillRectangle = new FillRectangle(FillColor, x, y, width, height);

            buffer.Enqueue(fillRectangle);

            return true;
        }
    }
}
