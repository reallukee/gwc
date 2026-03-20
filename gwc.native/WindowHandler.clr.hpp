//
// GWC.Native
//
//  Version : 0.1.0
//  MIT License
//  WindowHandler.clr.hpp
//

#pragma once

#ifndef GWC_WINDOWHANDLER_CLR_HPP
#define GWC_WINDOWHANDLER_CLR_HPP

#ifdef __cplusplus_cli

#include <msclr\auto_gcroot.h>
#include <msclr\auto_handle.h>
#include <msclr\lock.h>
#include <msclr\event.h>
#include <msclr\marshal.h>
#include <msclr\marshal_cppstd.h>
#include <msclr\marshal_windows.h>

using namespace System;
using namespace System::Reflection;
using namespace System::Runtime::InteropServices;

using namespace Reallukee::GWC;

namespace Reallukee
{
namespace GWC
{
namespace Interop
{
    public ref class WindowHandler abstract
    {

    private:

        WindowHandler();
        ~WindowHandler();

    public:

        static IntPtr  alloc ();
        static bool    free  (IntPtr handle);
        static Window^ invoke(IntPtr handle);
        static bool    isNull(IntPtr handle);

    };
}
}
}

#endif // __cplusplus_cli

#endif // !GWC_WINDOWHANDLER_CLR_HPP
