//
// :.:.:.:.:.
// GWC.Native
// v0.3.1
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// CanvasHost.clr.hpp
//  Licenza MIT
//

#pragma once

#ifndef GWC_CANVASHOST_CLR_HPP
#define GWC_CANVASHOST_CLR_HPP

#ifdef __cplusplus_cli

#include "header.clr.hpp"

namespace Reallukee
{
namespace GWC
{
namespace Interop
{
    class CanvasHost sealed
    {

    public:

        CanvasHost (int width, int height);
        CanvasHost ();
        ~CanvasHost();

        bool    isNull();

        Canvas^ invoke();

    private:

        gcroot<Canvas^> canvas;

    };
}
}
}

#endif // __cplusplus_cli

#endif // !GWC_CANVASHOST_CLR_HPP
