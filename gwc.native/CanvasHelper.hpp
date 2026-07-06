//
// :.:.:.:.:.
// GWC.Native
// v0.6.1
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// CanvasHelper.hpp
//  Licenza MIT
//

#pragma once

#ifndef GWC_CANVASHELPER_HPP
#define GWC_CANVASHELPER_HPP

#ifdef __cplusplus

#include "CanvasHost.clr.hpp"

using namespace Reallukee::GWC::Interop;

namespace gwc
{
    class Canvas;

    class CanvasHelper sealed
    {

    public:

        static CanvasHost* get(const Canvas* canvas);

    private:

        CanvasHelper () = default;
        ~CanvasHelper() = default;

    };
}

#endif // __cplusplus

#endif // !GWC_CANVASHELPER_HPP
