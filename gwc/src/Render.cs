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
 * Nome file : Render.cs
 *
 * Titolo    : RENDER
 * Sommario  : Contiene l'implementazione della
 *             classe Render.
 *
 * Autore    : Luca Pollicino
 *             (https://github.com/reallukee)
 * Versione  : v0.6.1
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

namespace Reallukee.GWC
{
    public static class Render
    {
        private delegate (bool Invalid, string Message) RangeCheck(int value);

        private static RangeCheck IsLessThen(int min)
        {
            return value =>
            {
                if (value < min)
                {
                    string message = $"Value cannot be less than {min}.";

                    return (true, message);
                }

                return (false, null);
            };
        }

        private static RangeCheck IsGreaterThan(int max)
        {
            return value =>
            {
                if (value > max)
                {
                    string message = $"Value cannot be greater than {max}.";

                    return (true, message);
                }

                return (false, null);
            };
        }

        private static void ThrowIfArgumentOutOfRange(
            string name, int value, params RangeCheck[] rangeChecks
        )
        {
            foreach (var rangeCheck in rangeChecks)
            {
                (bool invalid, string message) = rangeCheck(value);

                if (invalid)
                {
                    throw new ArgumentOutOfRangeException(name, message);
                }
            }
        }



        private static int refreshRate = 60;

        public static int RefreshRate
        {
            get
            {
                return refreshRate;
            }

            set
            {
                ThrowIfArgumentOutOfRange(nameof(RefreshRate), value, IsLessThen(30));
                ThrowIfArgumentOutOfRange(nameof(RefreshRate), value, IsGreaterThan(60));

                refreshRate = value;

                FrameTime = 1000.0 / value;

                UtilFrameTime = DutyCycle / 100.0 * FrameTime;
            }
        }

        public static void SetDefaultRefreshRate()
        {
            RefreshRate = 60;
        }



        private static int dutyCycle = 80;

        public static int DutyCycle
        {
            get
            {
                return dutyCycle;
            }

            set
            {
                ThrowIfArgumentOutOfRange(nameof(RefreshRate), value, IsLessThen(10));
                ThrowIfArgumentOutOfRange(nameof(RefreshRate), value, IsGreaterThan(90));

                dutyCycle = value;

                FrameTime = 1000.0 / RefreshRate;

                UtilFrameTime = value / 100.0 * FrameTime;
            }
        }

        public static void SetDefaultDutyCycle()
        {
            DutyCycle = 80;
        }



        private static double frameTime = 16.66;

        public static double FrameTime
        {
            get
            {
                return frameTime;
            }

            private set
            {
                frameTime = value;
            }
        }



        private static double utilFrameTime = 13.33;

        public static double UtilFrameTime
        {
            get
            {
                return utilFrameTime;
            }

            private set
            {
                utilFrameTime = value;
            }
        }
    }
}
