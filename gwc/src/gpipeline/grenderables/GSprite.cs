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
 * Titolo    : GSPRITE
 * Sommario  : Contiene l'implementazione della
 *             classe GSprite.
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
}
