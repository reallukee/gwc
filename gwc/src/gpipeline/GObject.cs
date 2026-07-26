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
 * Nome file : GObject.cs
 *
 * Titolo    : GOBJECT
 * Sommario  : Contiene l'implementazione della
 *             classe GObject.
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
    public abstract class GObject<T>
    {
        protected static void ThrowIfArgumentNull(
            string name, object value
        )
        {
            if (value == null)
            {
                throw new ArgumentNullException(
                    name,
                    "ArgumentNull"
                );
            }
        }

        protected static void ThrowIfObjectDisposed(
            string name, bool disposed
        )
        {
            if (disposed)
            {
                throw new ArgumentNullException(
                    name,
                    "ObjectDisposed"
                );
            }
        }



        public abstract GObject<T> Clone();
    }
}
