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
 * Nome file : WindowHandler.cs
 *
 * Titolo    : WINDOWHANDLER
 * Sommario  : Contiene l'implementazione della
 *             classe WindowHandler.
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
using System.Windows.Forms;

namespace Reallukee.GWC.Interop
{
    public static class WindowHandler
    {
        private static IntPtr GCAlloc(Window window)
        {
            GCHandle gcHandle = GCHandle.Alloc(window);

            IntPtr handle = GCHandle.ToIntPtr(gcHandle);

            return handle;
        }

        public static IntPtr Alloc(int width, int height)
        {
            Window window = new Window(width, height);

            return GCAlloc(window);
        }

        public static IntPtr Alloc()
        {
            Window window = new Window();

            return GCAlloc(window);
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



        public static Window Invoke(IntPtr handle)
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

            if (!(target is Window window))
            {
                throw new InvalidCastException(
                    $"GCHandle target type mismatch {nameof(Window)}."
                );
            }

            return window;
        }
    }
}
