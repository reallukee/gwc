//
// GWC.Native
//
//  Version : 0.1.0
//  MIT License
//  Canvas.hpp
//

#pragma once

#ifndef GWC_CANVAS_HPP
#define GWC_CANVAS_HPP

#ifdef  __cplusplus

#include "header.hpp"

#define _CANVAS void*

namespace gwc
{
    class GWC_CPP_API Canvas
    {

    private:

        _CANVAS canvas;

    public:

        Canvas (int width, int height);
        ~Canvas();

        bool isInitialized();

        bool drawBorderRectangle(int x, int y, int width, int height);
        bool drawFillRectangle(int x, int y, int width, int height);

    };
}

#endif //  __cplusplus

#endif // !GWC_CANVAS_HPP
