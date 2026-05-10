//
// :.:.:.
// GWC
// v0.5.0
// :.:.:.
//
// https://github.com/reallukee/gwc
//
// BaseImage.cs
//  Licenza MIT
//

using System;
using System.Collections;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.ComponentModel;
using System.Diagnostics;
using System.Globalization;
using System.Reflection;
using System.Resources;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading;

using System.Drawing;
using System.Windows.Forms;

namespace Reallukee.GWC
{
    internal class BaseImage : IRenderable, IDisposable
    {
        private Image image;

        public BaseImage(int x, int y, Image image)
        {
            this.X     = x;
            this.Y     = y;
            this.image = (Image)image.Clone();
        }

        public BaseImage(Image image) : this(0, 0, image) { }

        ~BaseImage()
        {
            Dispose();
        }

        public void Dispose()
        {
            image?.Dispose();
        }



        public int X
        {
            get;
            set;
        }

        public int Y
        {
            get;
            set;
        }

        public int Width  => image.Width;
        public int Height => image.Height;



        public Rectangle Bounds   => new Rectangle(X, Y, image.Width, image.Height);

        public Point     Location => new Point(X, Y);

        public Size      Size     => new Size(image.Width, image.Height);



        public void Render(Graphics g)
        {
            g.DrawImage(image, X, Y);
        }
    }
}
