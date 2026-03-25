//
// :.:.:.
// GWC
// v0.1.0
// :.:.:.
//
// https://github.com/reallukee/gwc
//
// Render.cs
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
    public static class Render
    {
        private static int refreshRate = 60;

        public static int RefreshRate
        {
            get => refreshRate;

            set
            {
                if (value < 0 || value > 120)
                {
                    return;
                }

                refreshRate = value;

                FrameTime = 1000.0 / value;

                UtilFrameTime = DutyCycle / 100.0 * FrameTime;
            }
        }

        private static int dutyCycle = 80;

        public static int DutyCycle
        {
            get => dutyCycle;

            set
            {
                if (value < 0 || value > 100)
                {
                    return;
                }

                dutyCycle = value;

                FrameTime = 1000.0 / RefreshRate;

                UtilFrameTime = value / 100.0 * FrameTime;
            }
        }

        private static double frameTime = 16.66;

        public static double FrameTime
        {
            get         => frameTime;
            private set => frameTime = value;
        }

        private static double utilFrameTime = 13.33;

        public static double UtilFrameTime
        {
            get         => utilFrameTime;
            private set => utilFrameTime = value;
        }
    }
}
