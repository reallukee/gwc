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
 * Nome file : GClearF.cs
 *
 * Titolo    : GCLEARF
 * Sommario  : Contiene l'implementazione della
 *             classe GClearF.
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
    internal sealed class GClearF : GBaseClear<float>, IGRenderable, IGFigureF
    {
        public GClearF(float x, float y, float width, float height, Color clearColor)
            : base(x, y, width, height, clearColor)
        {

        }

        public GClearF(PointF location, SizeF size, Color clearColor)
            : base(location.X, location.Y, size.Width, size.Height, clearColor)
        {

        }

        public GClearF(Color clearColor)
            : base(-1, -1, -1, -1, clearColor)
        {

        }

        public GClearF(GClearF other)
            : base(other)
        {

        }



        public override GObject<float> Clone()
        {
            return new GClearF(this);
        }



        public RectangleF Bounds   => new RectangleF(X, Y, Width, Height);
        public SizeF      Size     => new SizeF     (Width, Height);
        public PointF     Location => new PointF    (X, Y);



        public void Render(Graphics g)
        {
            if (X < 0 || Y < 0 || Width < 0 || Height < 0)
            {
                g.Clear(BackColor);
            }
            else
            {
                using (SolidBrush fill = new SolidBrush(BackColor))
                {
                    g.FillRectangle(fill, X, Y, Width, Height);
                }
            }
        }



        public override string ToString()
        {
            return string.Format(
                "GClearF: X={0}, Y={1}, Width={2}, Height={3}, BackColor={4}",
                X,
                Y,
                Width,
                Height,
                BackColor
            );
        }
    }
}
