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
 * Nome file : SpriteHandler.cs
 *
 * Titolo    : SPRITEHANDLER
 * Sommario  : Contiene l'implementazione della
 *             classe SpriteHandler.
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
    public static class SpriteHandler
    {
        private static IntPtr GCAlloc(Sprite sprite)
        {
            GCHandle gcHandle = GCHandle.Alloc(sprite);

            IntPtr handle = GCHandle.ToIntPtr(gcHandle);

            return handle;
        }

        public static IntPtr Alloc(int width, int height)
        {
            Sprite sprite = new Sprite(width, height);

            return GCAlloc(sprite);
        }

        public static IntPtr Alloc()
        {
            Sprite sprite = new Sprite();

            return GCAlloc(sprite);
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



        public static Sprite Invoke(IntPtr handle)
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

            if (!(target is Sprite sprite))
            {
                throw new InvalidCastException(
                    $"GCHandle target type mismatch {nameof(Sprite)}."
                );
            }

            return sprite;
        }
    }
}
