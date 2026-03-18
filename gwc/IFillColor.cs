//
// GWC
//
//  Version : 0.1.0
//  MIT License
//  IFillColor.cs
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
    public interface IFillColor
    {
        Color FillColor
        {
            get;
            set;
        }
    }
}
