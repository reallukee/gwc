//
// GWC.Native
//
//  Version : 0.1.0
//  MIT License
//  CanvasHandler.clr.hpp
//

#pragma once

#ifndef GWC_CANVASHANDLER_CLR_HPP
#define GWC_CANVASHANDLER_CLR_HPP

#ifdef __cplusplus_cli

#include "header.clr.hpp"

namespace Reallukee
{
namespace GWC
{
namespace Interop
{
    public ref class CanvasHandler abstract
    {

    public:

        static IntPtr  Alloc (int width, int height);
        static bool    Free  (IntPtr handle);
        static bool    IsNull(IntPtr handle);
        static Canvas^ Invoke(IntPtr handle);

    private:

        CanvasHandler();
        ~CanvasHandler();

    };
}
}
}

#endif // __cplusplus_cli

#endif // !GWC_CANVASHANDLER_CLR_HPP
