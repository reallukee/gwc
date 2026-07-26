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
 * Nome file : IGFigure.cs
 *
 * Titolo    : IGFIGURE/F
 * Sommario  : Contiene l'implementazione della
 *             classe IGFigure/F.
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
    internal interface IGFigure
    {
        Rectangle Bounds
        {
            get;
        }

        Point Location
        {
            get;
        }

        Size Size
        {
            get;
        }
    }

    internal interface IGFigureF
    {
        RectangleF Bounds
        {
            get;
        }

        PointF Location
        {
            get;
        }

        SizeF Size
        {
            get;
        }
    }
}
