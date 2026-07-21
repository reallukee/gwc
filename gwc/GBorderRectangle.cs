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
 * Nome file : GBorderRectangle.cs
 *
 * Titolo    : GBORDERRECTANGLE/F
 * Sommario  : Contiene l'implementazione della
 *             classe GBorderRectangle/F.
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
    internal class GBorderRectangle : GRectangle, IBorderColor, IRenderable
    {
        public GBorderRectangle(
            Color BorderColor,
            int   x,
            int   y,
            int   width,
            int   height
        ) : base(x, y, width, height)
        {
            this.BorderColor = BorderColor;
        }

        public GBorderRectangle(
            Color BorderColor,
            Point location,
            Size size
        ) : base(location.X, location.Y, size.Width, size.Height)
        {
            this.BorderColor = BorderColor;
        }

        public GBorderRectangle(GBorderRectangle other)
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
                g.DrawRectangle(border, X, Y, Width, Height);
            }
        }



        public override string ToString()
        {
            return string.Format(
                "GBorderRectangle: X={0}, Y={1}, Width={2}, Height={3}",
                X,
                Y,
                Width,
                Height
            );
        }
    }



    internal class GBorderRectangleF : GRectangleF, IBorderColor, IRenderableF
    {
        public GBorderRectangleF(
            Color BorderColor,
            float x,
            float y,
            float width,
            float height
        ) : base(x, y, width, height)
        {
            this.BorderColor = BorderColor;
        }

        public GBorderRectangleF(
            Color BorderColor,
            PointF location,
            SizeF size
        ) : base(location.X, location.Y, size.Width, size.Height)
        {
            this.BorderColor = BorderColor;
        }

        public GBorderRectangleF(GBorderRectangleF other)
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
                g.DrawRectangle(border, X, Y, Width, Height);
            }
        }



        public override string ToString()
        {
            return string.Format(
                "GBorderRectangleF: X={0}, Y={1}, Width={2}, Height={3}",
                X,
                Y,
                Width,
                Height
            );
        }
    }
}
