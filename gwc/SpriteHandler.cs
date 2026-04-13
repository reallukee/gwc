//
// :.:.:.
// GWC
// v0.3.0
// :.:.:.
//
// https://github.com/reallukee/gwc
//
// SpriteHandler.cs
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

namespace Reallukee.GWC.Interop
{
    internal static class SpriteHandler
    {
        public static IntPtr Alloc(int width, int height)
        {
            Sprite window = new Sprite(width, height);

            GCHandle managedHandle = GCHandle.Alloc(window);

            IntPtr nativeHandle = GCHandle.ToIntPtr(managedHandle);

            return nativeHandle;
        }

        public static IntPtr Alloc()
        {
            Sprite window = new Sprite();

            GCHandle managedHandle = GCHandle.Alloc(window);

            IntPtr nativeHandle = GCHandle.ToIntPtr(managedHandle);

            return nativeHandle;
        }



        public static bool Free(IntPtr handle)
        {
            if (handle == IntPtr.Zero)
            {
                return false;
            }

            IntPtr nativeHandle = handle;

            GCHandle managedHandle = GCHandle.FromIntPtr(nativeHandle);

            managedHandle.Free();

            return true;
        }



        public static bool IsNull(IntPtr handle)
        {
            IntPtr nativeHandle = handle;

            return nativeHandle == IntPtr.Zero;
        }



        public static Sprite Invoke(IntPtr handle)
        {
            if (handle == IntPtr.Zero)
            {
                return null;
            }

            IntPtr nativeHandle = handle;

            GCHandle managedHandle = GCHandle.FromIntPtr(nativeHandle);

            Sprite window = (Sprite)managedHandle.Target;

            return window;
        }
    }
}
