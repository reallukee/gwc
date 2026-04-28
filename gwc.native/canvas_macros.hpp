//
// :.:.:.:.:.
// GWC.Native
// v0.3.3
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// canvas_macros.hpp
//  Licenza MIT
//

#pragma once

#ifndef GWC_CANVAS_MACROS_HPP
#define GWC_CANVAS_MACROS_HPP

#ifdef __cplusplus

#include "macros.hpp"

#include "CanvasHost.clr.hpp"

#ifndef CC_CANVAS_VOID_CPP
#define CC_CANVAS_VOID_CPP(canvas) \
    CC_VOID_CPP(CanvasHost, canvas)
#endif // !CC_CANVAS_VOID_CPP

#ifndef CC_CANVAS_BOOL_CPP
#define CC_CANVAS_BOOL_CPP(canvas) \
    CC_BOOL_CPP(CanvasHost, canvas)
#endif // !CC_CANVAS_BOOL_CPP

#ifndef CC_CANVAS_INT_CPP
#define CC_CANVAS_INT_CPP(canvas) \
    CC_INT_CPP(CanvasHost, canvas)
#endif // !CC_CANVAS_INT_CPP



#ifndef CCI_CANVAS_VOID_CPP
#define CCI_CANVAS_VOID_CPP(canvas, target) \
    CCI_VOID_CPP(CanvasHost, canvas, target)
#endif // !CCI_CANVAS_VOID_CPP

#ifndef CCI_CANVAS_BOOL_CPP
#define CCI_CANVAS_BOOL_CPP(canvas, target) \
    CCI_BOOL_CPP(CanvasHost, canvas, target)
#endif // !CCI_CANVAS_BOOL_CPP

#ifndef CCI_CANVAS_INT_CPP
#define CCI_CANVAS_INT_CPP(canvas, target) \
    CCI_INT_CPP(CanvasHost, canvas, target)
#endif // !CCI_CANVAS_INT_CPP



#ifndef CCI_CANVAS_GET_COLOR_CPP
#define CCI_CANVAS_GET_COLOR_CPP(canvas, target) \
    CCI_GET_COLOR_CPP(CanvasHost, canvas, target)
#endif // !CCI_CANVAS_GET_COLOR_CPP

#ifndef CCI_CANVAS_SET_COLOR_CPP
#define CCI_CANVAS_SET_COLOR_CPP(canvas, target, color) \
    CCI_SET_COLOR_CPP(CanvasHost, canvas, target, color)
#endif // !CCI_CANVAS_SET_COLOR_CPP



#ifndef CCI_CANVAS_GET_POINT_CPP
#define CCI_CANVAS_GET_POINT_CPP(canvas, target) \
    CCI_GET_POINT_CPP(CanvasHost, canvas, target)
#endif // !CCI_CANVAS_GET_POINT_CPP

#ifndef CCI_CANVAS_SET_POINT_CPP
#define CCI_CANVAS_SET_POINT_CPP(canvas, target, point) \
    CCI_SET_POINT_CPP(CanvasHost, canvas, target, point)
#endif // !CCI_CANVAS_SET_POINT_CPP



#ifndef CCI_CANVAS_GET_SIZE_CPP
#define CCI_CANVAS_GET_SIZE_CPP(canvas, target) \
    CCI_GET_SIZE_CPP(CanvasHost, canvas, target)
#endif // !CCI_CANVAS_GET_SIZE_CPP

#ifndef CCI_CANVAS_SET_SIZE_CPP
#define CCI_CANVAS_SET_SIZE_CPP(canvas, target, size) \
    CCI_SET_SIZE_CPP(CanvasHost, canvas, target, size)
#endif // !CCI_CANVAS_SET_SIZE_CPP



#ifndef CCI_CANVAS_GET_RECTANGLE_CPP
#define CCI_CANVAS_GET_RECTANGLE_CPP(canvas, target) \
    CCI_GET_RECTANGLE_CPP(CanvasHost, canvas, target)
#endif // !CCI_CANVAS_GET_RECTANGLE_CPP

#ifndef CCI_CANVAS_SET_RECTANGLE_CPP
#define CCI_CANVAS_SET_RECTANGLE_CPP(canvas, target, rectangle) \
    CCI_SET_RECTANGLE_CPP(CanvasHost, canvas, target, rectangle)
#endif // !CCI_CANVAS_SET_RECTANGLE_CPP

#endif // __cplusplus

#endif // !GWC_CANVAS_MACROS_HPP
