//
// :.:.:.
// GWC
// v0.5.0
// :.:.:.
//
// https://github.com/reallukee/gwc
//
// BaseIcon.cs
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
    internal class BaseIcon : IRenderable, IDisposable
    {
        private Icon icon;

        public BaseIcon(int x, int y, Icon icon)
        {
            this.X    = x;
            this.Y    = y;
            this.icon = (Icon)icon.Clone();
        }

        public BaseIcon(Icon icon) : this(0, 0, icon) { }

        ~BaseIcon()
        {
            Dispose();
        }

        public void Dispose()
        {
            icon?.Dispose();
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

        public int Width  => icon.Width;
        public int Height => icon.Height;



        public Rectangle Bounds   => new Rectangle(X, Y, icon.Width, icon.Height);

        public Point     Location => new Point(X, Y);

        public Size      Size     => new Size(icon.Width, icon.Height);



        public void Render(Graphics g)
        {
            g.DrawIcon(icon, X, Y);
        }
    }
}
