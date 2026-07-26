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
 * Nome file : Program.cs
 *
 * Titolo    : PROGRAM
 * Sommario  : Contiene l'implementazione della
 *             classe Program.
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

namespace Reallukee.GWC
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Window window = new Window(800, 600);

            window.Open();

            Loop(window);

            if (window.IsOpen)
            {
                window.Close();
            }

            window.Dispose();
        }

        static int x = 0;
        static int y = 0;
        static int vx = 15;
        static int vy = 10;

        const int r = 50;

        static void Update()
        {
            x = x + vx;
            y = y + vy;

            if (x < 0)
            {
                x = 0;
                vx = -vx;
            }

            if (x + 2 * r > 800)
            {
                x = 800 - 2 * r;
                vx = -vx;
            }

            if (y < 0)
            {
                y = 0;
                vy = -vy;
            }

            if (y + 2 * r > 600)
            {
                y = 600 - 2 * r;
                vy = -vy;
            }
        }

        static void Render(Canvas canvas, Window window)
        {
            canvas.FillColor = Color.Black;
            canvas.Clear();

            canvas.FillColor = Color.Red;
            canvas.DrawFillCircle(r, r, r);

            canvas.Render();

            window.FillColor = Color.Black;
            window.Clear();

            window.DrawCanvas(x, y, canvas);
        }

        static void Loop(Window window)
        {
            Canvas canvas = new Canvas(r * 2, r * 2);

            bool loop = true;

            while (window.IsOpen && loop)
            {
                Keys modifiers = Keys.None;
                Keys key = Keys.None;

                bool keyDown = window.ConsumeKeyDown(out modifiers, out key);

                if (keyDown)
                {
                    if (key == Keys.Escape)
                    {
                        loop = false;

                        continue;
                    }
                }

                bool exit = window.IsKeyDownInBuffer(Keys.None, Keys.Escape);

                if (exit)
                {
                    loop = false;

                    continue;
                }

                Update();

                Render(canvas, window);

                window.Wait(16);
            }

            canvas.Dispose();
        }
    }
}
