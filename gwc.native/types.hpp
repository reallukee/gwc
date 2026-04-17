//
// :.:.:.:.:.
// GWC.Native
// v0.3.0
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

namespace gwc
{
    #ifndef CLR_SPRITE
    #define CLR_SPRITE void*
    typedef void* CLRSprite;
    #endif // !CLR_SPRITE

    #ifndef CLR_CANVAS
    #define CLR_CANVAS void*
    typedef void* CLRCanvas;
    #endif // !CLR_CANVAS

    #ifndef CLR_WINDOW
    #define CLR_WINDOW void*
    typedef void* CLRWindow;
    #endif // !CLR_WINDOW
}

#endif // __cplusplus

#endif // !GWC_TYPES_HPP
