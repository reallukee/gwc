//
// :.:.:.:.:.
// GWC.Native
// v0.3.3
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// types.hpp
//  Licenza MIT
//

#pragma once

#ifndef GWC_TYPES_HPP
#define GWC_TYPES_HPP

#ifdef __cplusplus

#include "Color.hpp"
#include "Point.hpp"
#include "Size.hpp"
#include "Rectangle.hpp"

#include "Keys.hpp"
#include "MouseButtons.hpp"

namespace gwc
{
    #ifndef CLR_SPRITE_HOST
    #define CLR_SPRITE_HOST void*

    typedef void* CLRSpriteHost;

    #endif // !CLR_SPRITE_HOST

    #ifndef CLR_CANVAS_HOST
    #define CLR_CANVAS_HOST void*

    typedef void* CLRCanvasHost;

    #endif // !CLR_CANVAS_HOST

    #ifndef CLR_WINDOW_HOST
    #define CLR_WINDOW_HOST void*

    typedef void* CLRWindowHost;

    #endif // !CLR_WINDOW_HOST
}

#endif // __cplusplus

#endif // !GWC_TYPES_HPP
