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
 * Nome file : GClear.cs
 *
 * Titolo    : GCLEAR
 * Sommario  : Contiene l'implementazione della
 *             classe GClear.
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
    internal sealed class GClear : GBaseClear<int>, IGRenderable, IGFigure
    {
        public GClear(int x, int y, int width, int height, Color clearColor)
            : base(x, y, width, height, clearColor)
        {

        }

        public GClear(Point location, Size size, Color clearColor)
            : base(location.X, location.Y, size.Width, size.Height, clearColor)
        {

        }

        public GClear(Color clearColor)
            : base(-1, -1, -1, -1, clearColor)
        {

        }

        public GClear(GClear other)
            : base(other)
        {

        }



        public override GObject<int> Clone()
        {
            return new GClear(this);
        }



        public Rectangle Bounds   => new Rectangle(X, Y, Width, Height);
        public Size      Size     => new Size     (Width, Height);
        public Point     Location => new Point    (X, Y);



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
                "GClear: X={0}, Y={1}, Width={2}, Height={3}, BackColor={4}",
                X,
                Y,
                Width,
                Height,
                BackColor
            );
        }
    }
}
