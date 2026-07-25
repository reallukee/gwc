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
 * Titolo    : GICON/F
 * Sommario  : Contiene l'implementazione della
 *             classe GIcon/F.
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
    internal class GIcon : GBaseIcon<int>, IRenderable, IDisposable, IFigure
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



        public override GBaseIcon<int> Clone()
        {
            return new GIcon(this);
        }



        public void Render(Graphics g)
        {
            ThrowIfObjectDisposed(
                nameof(GIcon),
                disposed
            );

            g.DrawIcon(Icon, X, Y);
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



    internal class GIconF : GBaseIcon<float>, IRenderable, IDisposable, IFigureF
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



        public override GBaseIcon<float> Clone()
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
