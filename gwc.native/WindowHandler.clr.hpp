//
// :.:.:.:.:.
// GWC.Native
// v0.1.0
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// WindowHandler.clr.hpp
//  Licenza MIT
//

#pragma once

#ifndef GWC_WINDOWHANDLER_CLR_HPP
#define GWC_WINDOWHANDLER_CLR_HPP

#ifdef __cplusplus_cli

#include "header.clr.hpp"

namespace Reallukee
{
namespace GWC
{
namespace Interop
{
    public ref class WindowHandler abstract
    {

    public:

        static IntPtr  Alloc (int width, int height);
        static IntPtr  Alloc ();

        static bool    Free  (IntPtr handle);

        static bool    IsNull(IntPtr handle);

        static Window^ Invoke(IntPtr handle);

    private:

        WindowHandler();
        ~WindowHandler();

    };
}
}
}

#endif // __cplusplus_cli

#endif // !GWC_WINDOWHANDLER_CLR_HPP
