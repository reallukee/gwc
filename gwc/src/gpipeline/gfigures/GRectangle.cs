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
 * Titolo    : GRECTANGLE
 * Sommario  : Contiene l'implementazione della
 *             classe GRectangle.
 *
 * Autore    : Luca Pollicino
 *             (https://github.com/reallukee)
 * Versione  : v0.7.0
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
using System.Drawing.Imaging;
using System.Windows.Forms;

using Reallukee.GWC.GPipeline.GCore;
using Reallukee.GWC.GPipeline.GBase;
using Reallukee.GWC.GPipeline.GProperties;

namespace Reallukee.GWC.GPipeline.GFigures
{
    internal class GRectangle : GBaseRectangle<int>, IGFigure
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



        public override GObject<int> Clone()
        {
            return new GRectangle(this);
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
}
