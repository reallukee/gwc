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
 * Nome file : GIconF.cs
 *
 * Titolo    : GICONF
 * Sommario  : Contiene l'implementazione della
 *             classe GIconF.
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
    internal class GIconF : GBaseIcon<float>, IGRenderable, IDisposable, IGFigureF
    {
        public GIconF(float x, float y, Icon icon)
            : base(x, y, icon)
        {

        }

        public GIconF(PointF location, Icon icon)
            : base(location.X, location.Y, icon)
        {

        }

        public GIconF(GIconF other)
            : base(other)
        {

        }



        public RectangleF Bounds
        {
            get
            {
                ThrowIfObjectDisposed(
                    nameof(GIconF),
                    disposed
                );

                return new RectangleF(X, Y, Width, Height);
            }
        }

        public PointF Location => new PointF(X, Y);

        public SizeF Size
        {
            get
            {
                ThrowIfObjectDisposed(
                    nameof(GIconF),
                    disposed
                );

                return new SizeF(Width, Height);
            }
        }



        public override GObject<float> Clone()
        {
            return new GIconF(this);
        }



        public void Render(Graphics g)
        {
            ThrowIfObjectDisposed(
                nameof(GIconF),
                disposed
            );

            g.DrawIcon(Icon, (int)X, (int)Y);
        }



        public override string ToString()
        {
            return string.Format(
                "GIconF: X={0}, Y={1}, Disposed={2}",
                X,
                Y,
                disposed
            );
        }
    }
}
