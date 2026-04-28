//
// :.:.:.:.:.
// GWC.Native
// v0.3.3
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// window_macros.hpp
//  Licenza MIT
//

#pragma once

#ifndef GWC_WINDOW_MACROS_HPP
#define GWC_WINDOW_MACROS_HPP

#ifdef __cplusplus

#include "macros.hpp"

#include "WindowHost.clr.hpp"

#ifndef CC_WINDOW_VOID_CPP
#define CC_WINDOW_VOID_CPP(window) \
    CC_VOID_CPP(WindowHost, window)
#endif // !CC_WINDOW_VOID_CPP

#ifndef CC_WINDOW_BOOL_CPP
#define CC_WINDOW_BOOL_CPP(window) \
    CC_BOOL_CPP(WindowHost, window)
#endif // !CC_WINDOW_BOOL_CPP

#ifndef CC_WINDOW_INT_CPP
#define CC_WINDOW_INT_CPP(window) \
    CC_INT_CPP(WindowHost, window)
#endif // !CC_WINDOW_INT_CPP



#ifndef CCI_WINDOW_VOID_CPP
#define CCI_WINDOW_VOID_CPP(window, target) \
    CCI_VOID_CPP(WindowHost, window, target)
#endif // !CCI_WINDOW_VOID_CPP

#ifndef CCI_WINDOW_BOOL_CPP
#define CCI_WINDOW_BOOL_CPP(window, target) \
    CCI_BOOL_CPP(WindowHost, window, target)
#endif // !CCI_WINDOW_BOOL_CPP

#ifndef CCI_WINDOW_INT_CPP
#define CCI_WINDOW_INT_CPP(window, target) \
    CCI_INT_CPP(WindowHost, window, target)
#endif // !CCI_WINDOW_INT_CPP



#ifndef CCI_WINDOW_GET_COLOR_CPP
#define CCI_WINDOW_GET_COLOR_CPP(window, target) \
    CCI_GET_COLOR_CPP(WindowHost, window, target)
#endif // !CCI_WINDOW_GET_COLOR_CPP

#ifndef CCI_WINDOW_SET_COLOR_CPP
#define CCI_WINDOW_SET_COLOR_CPP(window, target, color) \
    CCI_SET_COLOR_CPP(WindowHost, window, target, color)
#endif // !CCI_WINDOW_SET_COLOR_CPP



#ifndef CCI_WINDOW_GET_POINT_CPP
#define CCI_WINDOW_GET_POINT_CPP(window, target) \
    CCI_GET_POINT_CPP(WindowHost, window, target)
#endif // !CCI_WINDOW_GET_POINT_CPP

#ifndef CCI_WINDOW_SET_POINT_CPP
#define CCI_WINDOW_SET_POINT_CPP(window, target, point) \
    CCI_SET_POINT_CPP(WindowHost, window, target, point)
#endif // !CCI_WINDOW_SET_POINT_CPP



#ifndef CCI_WINDOW_GET_SIZE_CPP
#define CCI_WINDOW_GET_SIZE_CPP(window, target) \
    CCI_GET_SIZE_CPP(WindowHost, window, target)
#endif // !CCI_WINDOW_GET_SIZE_CPP

#ifndef CCI_WINDOW_SET_SIZE_CPP
#define CCI_WINDOW_SET_SIZE_CPP(window, target, size) \
    CCI_SET_SIZE_CPP(WindowHost, window, target, size)
#endif // !CCI_WINDOW_SET_SIZE_CPP



#ifndef CCI_WINDOW_GET_RECTANGLE_CPP
#define CCI_WINDOW_GET_RECTANGLE_CPP(window, target) \
    CCI_GET_RECTANGLE_CPP(WindowHost, window, target)
#endif // !CCI_WINDOW_GET_RECTANGLE_CPP

#ifndef CCI_WINDOW_SET_RECTANGLE_CPP
#define CCI_WINDOW_SET_RECTANGLE_CPP(window, target, rectangle) \
    CCI_SET_RECTANGLE_CPP(WindowHost, window, target, rectangle)
#endif // !CCI_WINDOW_SET_RECTANGLE_CPP

#endif // __cplusplus

#endif // !GWC_WINDOW_MACROS_HPP
