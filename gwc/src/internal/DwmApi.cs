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
 * Nome file : DwmApi
 *
 * Titolo    : DWMAPI
 * Sommario  : Contiene l'implementazione della
 *             classe DwmApi.
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

using Microsoft.Win32;

namespace Reallukee.GWC.Internal
{
    internal static class DwmApi
    {
        [DllImport("dwmapi.dll")]
        public static extern int DwmSetWindowAttribute(
            IntPtr  hwnd,
            int     dwAttribute,
            ref int pvAttribute,
            int     cbAttribute
        );

        [DllImport("dwmapi.dll")]
        public static extern int DwmGetWindowAttribute(
            IntPtr  hwnd,
            int     attribute,
            out int pvAttribute,
            int     cbAttribute
        );
    }
}
