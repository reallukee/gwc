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
 * Nome file : WindowForm.cs
 *
 * Titolo    : WINDOWFORM
 * Sommario  : Contiene l'implementazione della
 *             classe WindowForm.
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

using Reallukee.GWC.GPipeline;
using Reallukee.GWC.Internal;
using Reallukee.GWC.Interop;

using Microsoft.Win32;

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

        public Color FormCaptionColor
        {
            get
            {
                int result = DwmApi.DwmGetWindowAttribute(
                    Handle,
                    0x23,
                    out int value,
                    sizeof(int)
                );

                if (result != 0)
                {
                    throw new Exception("DwmApi error!");
                }

                Color captionColor = Color.FromArgb(
                    (value >> 0x00) & 0xFF,
                    (value >> 0x08) & 0xFF,
                    (value >> 0x10) & 0xFF
                );

                return captionColor;
            }

            set
            {
                int captionColor = (value.R << 0x00) | (value.G << 0x08) | (value.B << 0x10);

                DwmApi.DwmSetWindowAttribute(
                    Handle,
                    0x23,
                    ref captionColor,
                    sizeof(int)
                );
            }
        }

        public Color FormTextColor
        {
            get
            {
                int result = DwmApi.DwmGetWindowAttribute(
                    Handle,
                    0x24,
                    out int value,
                    sizeof(int)
                );

                if (result != 0)
                {
                    throw new Exception("DwmApi error!");
                }

                Color captionColor = Color.FromArgb(
                    (value >> 0x00) & 0xFF,
                    (value >> 0x08) & 0xFF,
                    (value >> 0x10) & 0xFF
                );

                return captionColor;
            }

            set
            {
                int captionColor = (value.R << 0x00) | (value.G << 0x08) | (value.B << 0x10);

                DwmApi.DwmSetWindowAttribute(
                    Handle,
                    0x24,
                    ref captionColor,
                    sizeof(int)
                );
            }
        }

        protected static bool IsSystemUsingLightTheme()
        {
            const string keyPath = @"Software\Microsoft\Windows\CurrentVersion\Themes\Personalize";

            using (RegistryKey key = Registry.CurrentUser.OpenSubKey(keyPath))
            {
                object value = key?.GetValue("SystemUsesLightTheme");

                if (!(value is int i))
                {
                    return false;
                }

                return i == 0;
            }
        }

        protected static bool IsSystemUsingDarkTheme()
        {
            const string keyPath = @"Software\Microsoft\Windows\CurrentVersion\Themes\Personalize";

            using (RegistryKey key = Registry.CurrentUser.OpenSubKey(keyPath))
            {
                object value = key?.GetValue("SystemUsesLightTheme");

                if (!(value is int i))
                {
                    return false;
                }

                return i != 0;
            }
        }

        private (Color, Color) GetLightTheme()
        {
            return (Color.FromArgb(20, 20, 20), Color.FromArgb(250, 250, 250));
        }

        private (Color, Color) GetDarkTheme()
        {
            return (Color.FromArgb(250, 250, 250), Color.FromArgb(20, 20, 20));
        }

        private ManualResetEventSlim handleCreated;

        protected override void OnHandleCreated(EventArgs e)
        {
            try
            {
                Color foreColor;
                Color backColor;

                #if EXPERIMENTAL
                if (IsSystemUsingDarkTheme())
                {
                    (foreColor, backColor) = GetDarkTheme();
                }
                else
                #endif
                {
                    (foreColor, backColor) = GetLightTheme();
                }

                FormCaptionColor = backColor;
                FormTextColor = foreColor;

                BackColor = backColor;
                ForeColor = foreColor;
            }
            catch
            {

            }

            handleCreated.Set();
        }

        public void WaitHandleCreated()
        {
            handleCreated.Wait();
        }

        private ManualResetEventSlim handleDestroyed;

        protected override void OnHandleDestroyed(EventArgs e)
        {
            try
            {
                Color foreColor;
                Color backColor;

                #if EXPERIMENTAL
                if (IsSystemUsingDarkTheme())
                {
                    (foreColor, backColor) = GetDarkTheme();
                }
                else
                #endif
                {
                    (foreColor, backColor) = GetLightTheme();
                }

                FormCaptionColor = backColor;
                FormTextColor = foreColor;

                BackColor = backColor;
                ForeColor = foreColor;
            }
            catch
            {

            }

            handleDestroyed.Set();
        }

        public void WaitHandleDestroyed()
        {
            handleDestroyed.Wait();
        }
    }
}
