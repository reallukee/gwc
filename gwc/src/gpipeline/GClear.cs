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
 * Titolo    : GCLEAR/F
 * Sommario  : Contiene l'implementazione della
 *             classe GClear/F.
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
using System.Drawing.Imaging;
using System.Windows.Forms;

namespace Reallukee.GWC.GPipeline
{
    internal sealed class GClear : GBaseClear<int>, IGRenderable
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



        public void Render(Graphics g)
        {
            if (X < 0 || Y < 0 || Width < 0 || Height < 0)
            {
                g.Clear(ClearColor);
            }
            else
            {
                using (SolidBrush fill = new SolidBrush(ClearColor))
                {
                    g.FillRectangle(fill, X, Y, Width, Height);
                }
            }
        }
    }



    internal sealed class GClearF : GBaseClear<float>, IGRenderable
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



        public void Render(Graphics g)
        {
            if (X < 0 || Y < 0 || Width < 0 || Height < 0)
            {
                g.Clear(ClearColor);
            }
            else
            {
                using (SolidBrush fill = new SolidBrush(ClearColor))
                {
                    g.FillRectangle(fill, X, Y, Width, Height);
                }
            }
        }
    }
}
