//
// GWC
//
//  Version : 0.1.0
//  MIT License
//  Program.cs
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
            Window window = new Window();

            window.Open();

            if (window.IsOpen)
            {
                IFigure fillRectangle = new FillRectangle(
                    Color.Green, 50, 50, 100, 100
                );

                window.Draw(fillRectangle);

                IFigure borderRectangle = new BorderRectangle(
                    Color.Red, 50, 50, 100, 100
                );

                window.Draw(borderRectangle);

                Console.ReadKey();

                window.Shutdown();
            }
        }
    }
}
