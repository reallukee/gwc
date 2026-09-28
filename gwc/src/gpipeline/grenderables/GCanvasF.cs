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
 * Nome file : GCanvasF.cs
 *
 * Titolo    : GCANVASF
 * Sommario  : Contiene l'implementazione della
 *             classe GCanvasF.
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
using Reallukee.GWC.GPipeline.GFigures;

namespace Reallukee.GWC.GPipeline.GRenderable
{
    internal sealed class GCanvasF : GBaseCanvas<float>, IGRenderable, IGFigureF
    {
        public GCanvasF(float x, float y, Canvas canvas)
            : base(x, y, canvas)
        {

        }

        public GCanvasF(PointF location, Canvas canvas)
            : base(location.X, location.Y, canvas)
        {

        }

        public GCanvasF(GCanvasF other)
            : base(other)
        {

        }



        public override GObject<float> Clone()
        {
            return new GCanvasF(this);
        }



        public RectangleF Bounds   => new RectangleF(X, Y, Width, Height);
        public SizeF      Size     => new SizeF     (Width, Height);
        public PointF     Location => new PointF    (X, Y);



        public void Render(Graphics g)
        {
            g.DrawImage(Bitmap, X, Y);
        }



        public override string ToString()
        {
            return string.Format(
                "GCanvasF: X={0}, Y={1}, Disposed={2}",
                X,
                Y,
                disposed
            );
        }
    }
}
