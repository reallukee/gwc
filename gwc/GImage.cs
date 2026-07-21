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
 * Nome file : GImage.cs
 *
 * Titolo    : GIMAGE/F
 * Sommario  : Contiene l'implementazione della
 *             classe GImage/F.
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
    internal class GImage : GBaseImage<int>, IRenderable, IDisposable
    {
        public GImage(int x, int y, Image image)
            : base(x, y, image)
        {

        }

        public GImage(Point location, Image image)
            : base(location.X, location.Y, image)
        {

        }

        public GImage(GImage other)
            : base(other)
        {

        }



        public Rectangle Bounds
        {
            get
            {
                ThrowIfObjectDisposed(
                    nameof(GImage),
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
                    nameof(GImage),
                    disposed
                );

                return new Size(Width, Height);
            }
        }



        public override GBaseImage<int> Clone()
        {
            return new GImage(this);
        }



        public void Render(Graphics g)
        {
            ThrowIfObjectDisposed(
                nameof(GImage),
                disposed
            );

            g.DrawImage(Image, X, Y);
        }



        public override string ToString()
        {
            return string.Format(
                "GImage: X={0}, Y={1}, Disposed={2}",
                X,
                Y,
                disposed
            );
        }
    }



    internal class GImageF : GBaseImage<float>, IRenderableF, IDisposable
    {
        public GImageF(float x, float y, Image image)
            : base(x, y, image)
        {

        }

        public GImageF(PointF location, Image image)
            : base(location.X, location.Y, image)
        {

        }

        public GImageF(GImageF other)
            : base(other)
        {

        }



        public RectangleF Bounds
        {
            get
            {
                ThrowIfObjectDisposed(
                    nameof(GImageF),
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
                    nameof(GImageF),
                    disposed
                );

                return new SizeF(Width, Height);
            }
        }



        public override GBaseImage<float> Clone()
        {
            return new GImageF(this);
        }



        public void Render(Graphics g)
        {
            ThrowIfObjectDisposed(
                nameof(GImageF),
                disposed
            );

            g.DrawImage(Image, X, Y);
        }



        public override string ToString()
        {
            return string.Format(
                "GImageF: X={0}, Y={1}, Disposed={2}",
                X,
                Y,
                disposed
            );
        }
    }
}
