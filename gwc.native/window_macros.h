//
// :.:.:.:.:.
// GWC.Native
// v0.3.3
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// window_macros.h
//  Licenza MIT
//

#pragma once

#ifndef GWC_WINDOW_MACROS_H
#define GWC_WINDOW_MACROS_H

#include "macros.h"

#include "WindowHost.clr.hpp"

#ifndef CC_WINDOW_VOID_C
#define CC_WINDOW_VOID_C(window) \
    CC_VOID_C(WindowHost, window)
#endif // !CC_WINDOW_VOID_C

#ifndef CC_WINDOW_BOOL_C
#define CC_WINDOW_BOOL_C(window) \
    CC_BOOL_C(WindowHost, window)
#endif // !CC_WINDOW_BOOL_C

#ifndef CC_WINDOW_INT_C
#define CC_WINDOW_INT_C(window) \
    CC_INT_C(WindowHost, window)
#endif // !CC_WINDOW_INT_C



#ifndef CCI_WINDOW_VOID_C
#define CCI_WINDOW_VOID_C(window, target) \
    CCI_VOID_C(WindowHost, window, target)
#endif // !CCI_WINDOW_VOID_C

#ifndef CCI_WINDOW_BOOL_C
#define CCI_WINDOW_BOOL_C(window, target) \
    CCI_BOOL_C(WindowHost, window, target)
#endif // !CCI_WINDOW_BOOL_C

#ifndef CCI_WINDOW_INT_C
#define CCI_WINDOW_INT_C(window, target) \
    CCI_INT_C(WindowHost, window, target)
#endif // !CCI_WINDOW_INT_C



#ifndef CCI_WINDOW_GET_COLOR_C
#define CCI_WINDOW_GET_COLOR_C(window, target) \
    CCI_GET_COLOR_C(WindowHost, window, target)
#endif // !CCI_WINDOW_GET_COLOR_C

#ifndef CCI_WINDOW_SET_COLOR_C
#define CCI_WINDOW_SET_COLOR_C(window, target, color) \
    CCI_SET_COLOR_C(WindowHost, window, target, color)
#endif // !CCI_WINDOW_SET_COLOR_C



#ifndef CCI_WINDOW_GET_POINT_C
#define CCI_WINDOW_GET_POINT_C(window, target) \
    CCI_GET_POINT_C(WindowHost, window, target)
#endif // !CCI_WINDOW_GET_POINT_C

#ifndef CCI_WINDOW_SET_POINT_C
#define CCI_WINDOW_SET_POINT_C(window, target, point) \
    CCI_SET_POINT_C(WindowHost, window, target, point)
#endif // !CCI_WINDOW_SET_POINT_C



#ifndef CCI_WINDOW_GET_SIZE_C
#define CCI_WINDOW_GET_SIZE_C(window, target) \
    CCI_GET_SIZE_C(WindowHost, window, target)
#endif // !CCI_WINDOW_GET_SIZE_C

#ifndef CCI_WINDOW_SET_SIZE_C
#define CCI_WINDOW_SET_SIZE_C(window, target, size) \
    CCI_SET_SIZE_C(WindowHost, window, target, size)
#endif // !CCI_WINDOW_SET_SIZE_C



#ifndef CCI_WINDOW_GET_RECTANGLE_C
#define CCI_WINDOW_GET_RECTANGLE_C(window, target) \
    CCI_GET_RECTANGLE_C(WindowHost, window, target)
#endif // !CCI_WINDOW_GET_RECTANGLE_C

#ifndef CCI_WINDOW_SET_RECTANGLE_C
#define CCI_WINDOW_SET_RECTANGLE_C(window, target, rectangle) \
    CCI_SET_RECTANGLE_C(WindowHost, window, target, rectangle)
#endif // !CCI_WINDOW_SET_RECTANGLE_C

#endif // !GWC_WINDOW_MACROS_H
