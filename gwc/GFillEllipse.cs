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
 * Nome file : GFillEllipse.cs
 *
 * Titolo    : GFILLELLIPSE/F
 * Sommario  : Contiene l'implementazione della
 *             classe GFillEllipse/F.
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
    internal class GFillEllipse : GEllipse, IFillColor, IRenderable
    {
        public GFillEllipse(
            Color fillColor,
            int   x,
            int   y,
            int   width,
            int   height
        ) : base(x, y, width, height)
        {
            this.FillColor = fillColor;
        }

        public GFillEllipse(
            Color fillColor,
            Point location,
            Size size
        ) : base(location.X, location.Y, size.Width, size.Height)
        {
            this.FillColor = fillColor;
        }

        public GFillEllipse(GFillEllipse other)
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
                g.FillEllipse(fill, X - Width / 2, Y - Height / 2, Width, Height);
            }
        }



        public override string ToString()
        {
            return string.Format(
                "GFillEllipse: X={0}, Y={1}, Width={2}, Height={3}",
                X,
                Y,
                Width,
                Height
            );
        }
    }



    internal class GFillEllipseF : GEllipseF, IFillColor, IRenderableF
    {
        public GFillEllipseF(
            Color fillColor,
            float x,
            float y,
            float width,
            float height
        ) : base(x, y, width, height)
        {
            this.FillColor = fillColor;
        }

        public GFillEllipseF(
            Color fillColor,
            PointF location,
            SizeF size
        ) : base(location.X, location.Y, size.Width, size.Height)
        {
            this.FillColor = fillColor;
        }

        public GFillEllipseF(GFillEllipseF other)
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
                g.FillEllipse(fill, X - Width / 2, Y - Height / 2, Width, Height);
            }
        }



        public override string ToString()
        {
            return string.Format(
                "GFillEllipseF: X={0}, Y={1}, Width={2}, Height={3}",
                X,
                Y,
                Width,
                Height
            );
        }
    }
}
