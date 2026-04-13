//
// :.:.:.
// GWC
// v0.2.0
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
                if (value < 30 || value > 60)
                {
                    return;
                }

                refreshRate = value;

                FrameTime = 1000.0 / value;

                UtilFrameTime = DutyCycle / 100.0 * FrameTime;
            }
        }

        public static void SetDefaultRefreshRate() => RefreshRate = 60;

        private static int dutyCycle = 80;

        public static int DutyCycle
        {
            get => dutyCycle;

            set
            {
                if (value < 10 || value > 90)
                {
                    return;
                }

                dutyCycle = value;

                FrameTime = 1000.0 / RefreshRate;

                UtilFrameTime = value / 100.0 * FrameTime;
            }
        }

        public static void SetDefaultDutyCycle() => DutyCycle = 80;

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
