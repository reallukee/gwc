//
// :.:.:.
// GWC
// v0.1.0
// :.:.:.
//
// https://github.com/reallukee/gwc
//
// Program.cs
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
    internal class Program
    {
        static void Main(string[] args)
        {
            Render.RefreshRate = 60;
            Render.DutyCycle = 80;

            Window window = new Window(800, 600);

            window.Open();

            window.FillColor = Color.FromArgb(100, 0, 255, 0);
            window.BorderColor = Color.FromArgb(100, 0, 128, 0);

            if (window.IsOpen)
            {
                window.DrawFillRectangle(50, 50, 100, 100);
                window.DrawBorderRectangle(50, 50, 100, 100);

                Console.WriteLine("Press any key to exit...");

                Console.ReadKey(true);

                window.Shutdown();
            }
            else
            {
                Console.WriteLine("Oh :(!");
            }

            window.Dispose();
        }
    }
}
