//
// :.:.:.:.:.
// GWC.Native
// v0.2.0
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
    #ifndef CLR_WINDOW
    typedef void* CLRWindow;
    #define CLR_WINDOW void*
    #endif // !CLR_WINDOW

    #ifndef CLR_CANVAS
    typedef void* CLRCanvas;
    #define CLR_CANVAS void*
    #endif // !CLR_CANVAS
}

#endif // __cplusplus

#endif // !GWC_TYPES_HPP
