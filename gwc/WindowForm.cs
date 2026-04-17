//
// :.:.:.
// GWC
// v0.3.0
// :.:.:.
//
// https://github.com/reallukee/gwc
//
// WindowForm.cs
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
    internal class WindowForm : Form
    {
        public WindowForm()
        {
            DoubleBuffered = true;

            StartPosition = FormStartPosition.CenterScreen;

            SetStyle(ControlStyles.ResizeRedraw,                 true);
            SetStyle(ControlStyles.UserPaint,                    true);
            SetStyle(ControlStyles.AllPaintingInWmPaint,         true);
            SetStyle(ControlStyles.SupportsTransparentBackColor, true);
            SetStyle(ControlStyles.OptimizedDoubleBuffer,        true);

            handleCreated   = new ManualResetEventSlim(false);
            handleDestroyed = new ManualResetEventSlim(false);
        }

        private ManualResetEventSlim handleCreated;
        private ManualResetEventSlim handleDestroyed;

        protected override void OnHandleCreated  (EventArgs e) => handleCreated  .Set();
        protected override void OnHandleDestroyed(EventArgs e) => handleDestroyed.Set();

        public void WaitHandleCreated()   => handleCreated  .Wait();
        public void WaitHandleDestroyed() => handleDestroyed.Wait();
    }
}
