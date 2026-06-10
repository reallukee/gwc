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

        static void Loop(Window window)
        {
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

                window.Wait(16);
            }
        }
    }
}
