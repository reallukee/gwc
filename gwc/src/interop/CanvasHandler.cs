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
 * Nome file : CanvasHandler.cs
 *
 * Titolo    : CANVASHANDLER
 * Sommario  : Contiene l'implementazione della
 *             classe CanvasHandler.
 *
 * Autore    : Luca Pollicino
 *             (https://github.com/reallukee)
 * Versione  : v0.6.0
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

namespace Reallukee.GWC.Interop
{
    public static class CanvasHandler
    {
        private static IntPtr GCAlloc(Canvas canvas)
        {
            GCHandle gcHandle = GCHandle.Alloc(canvas);

            IntPtr handle = GCHandle.ToIntPtr(gcHandle);

            return handle;
        }

        public static IntPtr Alloc(int width, int height)
        {
            Canvas canvas = new Canvas(width, height);

            return GCAlloc(canvas);
        }

        public static IntPtr Alloc()
        {
            Canvas canvas = new Canvas();

            return GCAlloc(canvas);
        }



        public static void Free(IntPtr handle)
        {
            if (handle == IntPtr.Zero)
            {
                throw new ArgumentNullException(
                    nameof(handle), "Handle cannot null."
                );
            }

            GCHandle gcHandle;

            try
            {
                gcHandle = GCHandle.FromIntPtr(handle);
            }
            catch
            {
                throw new ArgumentException(
                    nameof(handle), "Invalid GCHandle pointer."
                );
            }

            if (!gcHandle.IsAllocated)
            {
                throw new InvalidOperationException("GCHandle is not allocated.");
            }

            gcHandle.Free();
        }



        public static bool IsNull(IntPtr handle)
        {
            return handle == IntPtr.Zero;
        }



        public static Canvas Invoke(IntPtr handle)
        {
            if (handle == IntPtr.Zero)
            {
                throw new ArgumentNullException(
                    nameof(handle), "Handle cannot null."
                );
            }

            GCHandle gcHandle;

            try
            {
                gcHandle = GCHandle.FromIntPtr(handle);
            }
            catch
            {
                throw new ArgumentException(
                    nameof(handle), "Invalid GCHandle pointer."
                );
            }

            if (!gcHandle.IsAllocated)
            {
                throw new InvalidOperationException(
                    "GCHandle is not allocated."
                );
            }

            object target = gcHandle.Target;

            if (target == null)
            {
                throw new InvalidOperationException(
                    "GCHandle target is null."
                );
            }

            if (!(target is Canvas canvas))
            {
                throw new InvalidCastException(
                    $"GCHandle target type mismatch {nameof(Canvas)}."
                );
            }

            return canvas;
        }
    }
}
