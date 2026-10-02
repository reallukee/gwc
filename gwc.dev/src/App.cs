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
 * Nome file : App.cs
 *
 * Titolo    : APP
 * Sommario  : Contiene l'implementazione della
 *             classe App.
 *
 * Autore    : Luca Pollicino
 *             (https://github.com/reallukee)
 * Versione  : v0.7.0
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
    internal class App
    {
        private Window mainWindow;
        private Canvas mainCanvas;

        public App()
        {
            mainWindow = new Window(800, 600);
            mainCanvas = new Canvas(50, 50);
        }

        public void Run()
        {
            mainWindow.Open();

            Loop();

            if (mainWindow.IsOpen)
            {
                mainWindow.Close();
            }

            mainWindow.Dispose();
            mainCanvas.Dispose();
        }

        private void Loop()
        {
            bool loop = true;

            while (loop && mainWindow.IsOpen)
            {
                Keys modifiers = Keys.None;
                Keys key = Keys.None;

                bool exit = mainWindow.ConsumeKeyDown(
                    out modifiers, out key
                );

                if (exit)
                {
                    if (modifiers == Keys.Alt && key == Keys.Escape)
                    {
                        loop = false;

                        continue;
                    }
                }

                exit = mainWindow.IsKeyDownInBuffer(
                    Keys.Alt, Keys.Escape
                );

                if (exit)
                {
                    loop = false;

                    continue;
                }

                Render();

                mainWindow.Wait(16);
            }
        }

        private void Render()
        {
            mainCanvas.FillColor = Color.Red;
            mainCanvas.DrawFillSquare(0, 0, 50);

            mainCanvas.Render();

            mainWindow.FillColor = Color.Black;
            mainWindow.Clear();

            mainWindow.DrawCanvas(10, 10, mainCanvas);
        }
    }
}
