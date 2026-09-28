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
 * Nome file : GIcon.cs
 *
 * Titolo    : GICON
 * Sommario  : Contiene l'implementazione della
 *             classe GIcon.
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
    internal class GIcon : GBaseIcon<int>, IGRenderable, IDisposable, IGFigure
    {
        public GIcon(int x, int y, Icon icon)
            : base(x, y, icon)
        {

        }

        public GIcon(Point location, Icon icon)
            : base(location.X, location.Y, icon)
        {

        }

        public GIcon(GIcon other)
            : base(other)
        {

        }



        public Rectangle Bounds
        {
            get
            {
                ThrowIfObjectDisposed(
                    nameof(GIcon),
                    disposed
                );

                return new Rectangle(X, Y, Width, Height);
            }
        }

        public Point Location => new Point(X, Y);

        public Size Size
        {
            get
            {
                ThrowIfObjectDisposed(
                    nameof(GIcon),
                    disposed
                );

                return new Size(Width, Height);
            }
        }



        public override GObject<int> Clone()
        {
            return new GIcon(this);
        }



        public void Render(Graphics g)
        {
            ThrowIfObjectDisposed(
                nameof(GIcon),
                disposed
            );

            g.DrawIcon(Icon, (int)X, (int)Y);
        }



        public override string ToString()
        {
            return string.Format(
                "GIcon: X={0}, Y={1}, Disposed={2}",
                X,
                Y,
                disposed
            );
        }
    }
}
