//
// :.:.:.
// GWC
// v0.5.0
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
            Window window = new Window(800, 600);

            window.Open();

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

                window.Wait(100);
            }

            if (window.IsOpen)
            {
                window.Close();
            }

            window.Dispose();

            Environment.Exit(0);
        }
    }
}
