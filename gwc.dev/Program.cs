//
// :.:.:.
// GWC
// v0.2.0
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
            Render.DutyCycle   = 80;

            Window window = new Window(800, 600);

            window.Open();

            bool loop = true;

            Console.WriteLine("Press \"ESC\" to exit...");

            while (window.IsOpen && loop)
            {
                bool keyDown = window.ConsumeKeyDown(out int key);

                if (key == 27)
                {
                    loop = false;

                    continue;
                }

                if (keyDown)
                {
                    Console.WriteLine($"Pressed: {key}");

                    window.BorderColor = GenerateRandomColor();
                    window.FillColor   = GenerateRandomColor();

                    window.DrawFillRectangle  (100, 100, 100, 100);
                    window.DrawBorderRectangle(100, 100, 100, 100);
                }

                window.Wait(100);
            }

            if (window.IsOpen)
            {
                window.Shutdown();
            }

            window.Dispose();
        }

        static Color GenerateRandomColor()
        {
            Random random = new Random();

            int alpha = random.Next(0, 100 + 1);
            int red   = random.Next(0, 255 + 1);
            int blue  = random.Next(0, 255 + 1);
            int green = random.Next(0, 255 + 1);

            Color randomColor = Color.FromArgb(alpha, red, green, blue);

            return randomColor;
        }
    }
}
