//
// :.:.:.
// GWC
// v0.3.0
// :.:.:.
//
// https://github.com/reallukee/gwc
//
// IFillColor.cs
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
    internal interface IFillColor
    {
        Color FillColor
        {
            get;
            set;
        }
    }
}
