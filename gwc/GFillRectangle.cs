/*
 * :.:.:.:.:.:.:.:.
 * GWC
 * Graphical Window
 * for Console Apps
 * :.:.:.:.:.:.:.:.
 *
 * A Graphics Library
 *
 * https://github.com/reallukee/gwc
 *
 * Nome file : GFillRectangle.cs
 *
 * Titolo    : GFILLRECTANGLE/F
 * Sommario  : Contiene l'implementazione della
 *             classe GFillRectangle/F.
 *
 * Autore    : Luca Pollicino
 *             (https://github.com/reallukee)
 * Versione  : v0.6.3
 *             NOTA BENE: Campo INDICATIVO!
 * Licenza   : MIT
 */

using System;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Reflection;
using System.Resources;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Threading;

using System.Drawing;
using System.Windows.Forms;

namespace Reallukee.GWC.Internal
{
    internal class GFillRectangle : GRectangle, IFillColor, IRenderable, IFigure
    {
        public GFillRectangle(
            Color fillColor,
            int   x,
            int   y,
            int   width,
            int   height
        ) : base(x, y, width, height)
        {
            this.FillColor = fillColor;
        }

        public GFillRectangle(
            Color fillColor,
            Point location,
            Size size
        ) : base(location.X, location.Y, size.Width, size.Height)
        {
            this.FillColor = fillColor;
        }

        public GFillRectangle(GFillRectangle other)
            : base(other)
        {
            ThrowIfArgumentNull(
                nameof(other),
                other
            );

            this.FillColor = other.FillColor;
        }



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



        public override string ToString()
        {
            return string.Format(
                "GFillRectangle: X={0}, Y={1}, Width={2}, Height={3}",
                X,
                Y,
                Width,
                Height
            );
        }
    }



    internal class GFillRectangleF : GRectangleF, IFillColor, IRenderable, IFigureF
    {
        public GFillRectangleF(
            Color fillColor,
            float x,
            float y,
            float width,
            float height
        ) : base(x, y, width, height)
        {
            this.FillColor = fillColor;
        }

        public GFillRectangleF(
            Color fillColor,
            PointF location,
            SizeF size
        ) : base(location.X, location.Y, size.Width, size.Height)
        {
            this.FillColor = fillColor;
        }

        public GFillRectangleF(GFillRectangleF other)
            : base(other)
        {
            ThrowIfArgumentNull(
                nameof(other),
                other
            );

            this.FillColor = other.FillColor;
        }



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



        public override string ToString()
        {
            return string.Format(
                "GFillRectangleF: X={0}, Y={1}, Width={2}, Height={3}",
                X,
                Y,
                Width,
                Height
            );
        }
    }
}
