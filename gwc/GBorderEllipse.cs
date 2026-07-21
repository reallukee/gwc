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
 * Nome file : GBorderEllipse.cs
 *
 * Titolo    : GBORDERELLIPSE/F
 * Sommario  : Contiene l'implementazione della
 *             classe GBorderEllipse/F.
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
    internal class GBorderEllipse : GEllipse, IBorderColor, IRenderable
    {
        public GBorderEllipse(
            Color BorderColor,
            int   x,
            int   y,
            int   width,
            int   height
        ) : base(x, y, width, height)
        {
            this.BorderColor = BorderColor;
        }

        public GBorderEllipse(
            Color BorderColor,
            Point location,
            Size size
        ) : base(location.X, location.Y, size.Width, size.Height)
        {
            this.BorderColor = BorderColor;
        }

        public GBorderEllipse(GBorderEllipse other)
            : base(other)
        {
            ThrowIfArgumentNull(
                nameof(other),
                other
            );

            this.BorderColor = other.BorderColor;
        }



        public Color BorderColor
        {
            get;
            set;
        }



        public void Render(Graphics g)
        {
            using (Pen border = new Pen(BorderColor))
            {
                g.DrawEllipse(border, X - Width / 2, Y - Height / 2, Width, Height);
            }
        }



        public override string ToString()
        {
            return string.Format(
                "GBorderEllipse: X={0}, Y={1}, Width={2}, Height={3}",
                X,
                Y,
                Width,
                Height
            );
        }
    }



    internal class GBorderEllipseF : GEllipseF, IBorderColor, IRenderableF
    {
        public GBorderEllipseF(
            Color BorderColor,
            float x,
            float y,
            float width,
            float height
        ) : base(x, y, width, height)
        {
            this.BorderColor = BorderColor;
        }

        public GBorderEllipseF(
            Color BorderColor,
            PointF location,
            SizeF size
        ) : base(location.X, location.Y, size.Width, size.Height)
        {
            this.BorderColor = BorderColor;
        }

        public GBorderEllipseF(GBorderEllipseF other)
            : base(other)
        {
            ThrowIfArgumentNull(
                nameof(other),
                other
            );

            this.BorderColor = other.BorderColor;
        }



        public Color BorderColor
        {
            get;
            set;
        }



        public void Render(Graphics g)
        {
            using (Pen border = new Pen(BorderColor))
            {
                g.DrawEllipse(border, X - Width / 2, Y - Height / 2, Width, Height);
            }
        }



        public override string ToString()
        {
            return string.Format(
                "GBorderEllipseF: X={0}, Y={1}, Width={2}, Height={3}",
                X,
                Y,
                Width,
                Height
            );
        }
    }
}
