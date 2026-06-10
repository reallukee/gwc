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
 * Nome file : Clear.cs
 *
 * Titolo    : CLEAR
 * Sommario  : Contiene l'implementazione della
 *             classe Clear.
 *
 * Autore    : Luca Pollicino
 *             (https://github.com/reallukee)
 * Versione  : v0.6.1
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
    internal class Clear : IRenderable
    {
        public Clear(Color clearColor)
        {
            this.ClearColor = clearColor;
        }

        public Clear() : this(Color.Black)
        {

        }



        public Color ClearColor
        {
            get;
            set;
        }



        public Rectangle Bounds
        {
            get
            {
                return new Rectangle(0, 0, 0, 0);
            }
        }

        public Size Size
        {
            get
            {
                return new Size(0, 0);
            }
        }

        public Point Location
        {
            get
            {
                return new Point(0, 0);
            }
        }



        public void Render(Graphics g)
        {
            g.Clear(ClearColor);
        }



        public static bool operator ==(Clear left, Clear right)
        {
            if (ReferenceEquals(left, right))
            {
                return true;
            }

            if (ReferenceEquals(left, null) || ReferenceEquals(right, null))
            {
                return false;
            }

            return left.ClearColor == right.ClearColor;
        }

        public static bool operator !=(Clear left, Clear right)
        {
            return !(left == right);
        }



        public override bool Equals(object obj)
        {
            if (!(obj is Clear other))
            {
                return false;
            }

            return this == other;
        }

        public override int GetHashCode()
        {
            unchecked
            {
                int hash = 17;

                hash = hash * 23 + ClearColor.GetHashCode();

                return hash;
            }
        }

        public override string ToString()
        {
            return string.Format(
                "Clear: ClearColor={0}",
                ClearColor
            );
        }
    }
}
