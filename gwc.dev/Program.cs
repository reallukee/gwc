//
// :.:.:.
// GWC
// v0.4.1
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
