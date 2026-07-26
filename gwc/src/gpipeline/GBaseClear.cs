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
 * Nome file : GBaseClear.cs
 *
 * Titolo    : GBASECLEAR
 * Sommario  : Contiene l'implementazione della
 *             classe GBaseClear.
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
    internal abstract class GBaseClear<T> : GObject<T>
    {
        public GBaseClear(
            T     x,
            T     y,
            T     width,
            T     height,
            Color clearColor
        )
        {
            this.X          = x;
            this.Y          = y;
            this.Width      = width;
            this.Height     = height;
            this.ClearColor = clearColor;
        }

        public GBaseClear(GBaseClear<T> other)
        {
            ThrowIfArgumentNull(
                nameof(other),
                other
            );

            this.X          = other.X;
            this.Y          = other.Y;
            this.Width      = other.Width;
            this.Height     = other.Height;
            this.ClearColor = other.ClearColor;
        }



        public T X
        {
            get;
            private set;
        }

        public T Y
        {
            get;
            private set;
        }

        public T Width
        {
            get;
            private set;
        }

        public T Height
        {
            get;
            private set;
        }

        public Color ClearColor
        {
            get;
            private set;
        }
    }
}
