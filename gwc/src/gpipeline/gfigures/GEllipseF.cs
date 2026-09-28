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
 * Nome file : GEllipseF.cs
 *
 * Titolo    : GELLIPSEF
 * Sommario  : Contiene l'implementazione della
 *             classe GEllipseF.
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
    internal class GEllipseF : GBaseEllipse<float>, IGFigureF
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



        public override GObject<float> Clone()
        {
            return new GEllipseF(this);
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
