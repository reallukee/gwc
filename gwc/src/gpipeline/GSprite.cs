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
 * Nome file : GSprite.cs
 *
 * Titolo    : GSPRITE/F
 * Sommario  : Contiene l'implementazione della
 *             classe GSprite/F.
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
    internal sealed class GSprite : GBaseSprite<int>, IGRenderable, IGFigure
    {
        public GSprite(int x, int y, Sprite sprite)
            : base(x, y, sprite)
        {

        }

        public GSprite(Point location, Sprite sprite)
            : base(location.X, location.Y, sprite)
        {

        }

        public GSprite(GSprite other)
            : base(other)
        {

        }



        public override GObject<int> Clone()
        {
            return new GSprite(this);
        }



        public Rectangle Bounds   => new Rectangle(X, Y, Width, Height);
        public Size      Size     => new Size     (Width, Height);
        public Point     Location => new Point    (X, Y);



        public void Render(Graphics g)
        {
            g.DrawImage(Bitmap, X, Y);
        }



        public override string ToString()
        {
            return string.Format(
                "GSprite: X={0}, Y={1}, Disposed={2}",
                X,
                Y,
                disposed
            );
        }
    }



    internal sealed class GSpriteF : GBaseSprite<float>, IGRenderable, IGFigureF
    {
        public GSpriteF(float x, float y, Sprite sprite)
            : base(x, y, sprite)
        {

        }

        public GSpriteF(PointF location, Sprite sprite)
            : base(location.X, location.Y, sprite)
        {

        }

        public GSpriteF(GSpriteF other)
            : base(other)
        {

        }



        public override GObject<float> Clone()
        {
            return new GSpriteF(this);
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
                "GSpriteF: X={0}, Y={1}, Disposed={2}",
                X,
                Y,
                disposed
            );
        }
    }
}
