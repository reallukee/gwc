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
 * Nome file : GEllipse.cs
 *
 * Titolo    : GELLIPSE/F
 * Sommario  : Contiene l'implementazione della
 *             classe GEllipse/F.
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
    internal class GEllipse : GBaseEllipse<int>, IFigure
    {
        public GEllipse(int x, int y, int width, int height)
            : base(x, y, width, height)
        {

        }

        public GEllipse(Point location, Size size)
            : base(location.X, location.Y, size.Width, size.Height)
        {

        }

        public GEllipse(GEllipse other)
            : base(other)
        {

        }



        public Rectangle Bounds   => new Rectangle(X, Y, Width, Height);
        public Size      Size     => new Size     (Width, Height);
        public Point     Location => new Point    (X, Y);



        public override string ToString()
        {
            return string.Format(
                "GEllipse: X={0}, Y={1}, Width={2}, Height={3}",
                X,
                Y,
                Width,
                Height
            );
        }
    }



    internal class GEllipseF : GBaseEllipse<float>, IFigureF
    {
        public GEllipseF(float x, float y, float width, float height)
            : base(x, y, width, height)
        {

        }

        public GEllipseF(PointF location, SizeF size)
            : base(location.X, location.Y, size.Width, size.Height)
        {

        }

        public GEllipseF(GEllipseF other)
            : base(other)
        {

        }



        public RectangleF Bounds   => new RectangleF(X, Y, Width, Height);
        public SizeF      Size     => new SizeF     (Width, Height);
        public PointF     Location => new PointF    (X, Y);



        public override string ToString()
        {
            return string.Format(
                "GEllipseF: X={0}, Y={1}, Width={2}, Height={3}",
                X,
                Y,
                Width,
                Height
            );
        }
    }
}
