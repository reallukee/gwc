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
 * Nome file : GRectangle.cs
 *
 * Titolo    : GRECTANGLE/F
 * Sommario  : Contiene l'implementazione della
 *             classe GRectangle/F.
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
    internal class GRectangle : GBaseRectangle<int>, IFigure
    {
        public GRectangle(int x, int y, int width, int height)
            : base(x, y, width, height)
        {

        }

        public GRectangle(Point location, Size size)
            : base(location.X, location.Y, size.Width, size.Height)
        {

        }

        public GRectangle(GRectangle other)
            : base(other)
        {

        }



        public Rectangle Bounds   => new Rectangle(X, Y, Width, Height);
        public Size      Size     => new Size     (Width, Height);
        public Point     Location => new Point    (X, Y);



        public override string ToString()
        {
            return string.Format(
                "GRectangle: X={0}, Y={1}, Width={2}, Height={3}",
                X,
                Y,
                Width,
                Height
            );
        }
    }



    internal class GRectangleF : GBaseRectangle<float>, IFigureF
    {
        public GRectangleF(float x, float y, float width, float height)
            : base(x, y, width, height)
        {

        }

        public GRectangleF(PointF location, SizeF size)
            : base(location.X, location.Y, size.Width, size.Height)
        {

        }

        public GRectangleF(GRectangleF other)
            : base(other)
        {

        }



        public RectangleF Bounds   => new RectangleF(X, Y, Width, Height);
        public SizeF      Size     => new SizeF     (Width, Height);
        public PointF     Location => new PointF    (X, Y);



        public override string ToString()
        {
            return string.Format(
                "GRectangleF: X={0}, Y={1}, Width={2}, Height={3}",
                X,
                Y,
                Width,
                Height
            );
        }
    }
}
