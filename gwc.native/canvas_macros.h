//
// :.:.:.:.:.
// GWC.Native
// v0.3.3
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// canvas_macros.h
//  Licenza MIT
//

#pragma once

#ifndef GWC_CANVAS_MACROS_H
#define GWC_CANVAS_MACROS_H

#include "macros.h"

#include "CanvasHost.clr.hpp"

#ifndef CC_CANVAS_VOID_C
#define CC_CANVAS_VOID_C(canvas) \
    CC_VOID_C(CanvasHost, canvas)
#endif // !CC_CANVAS_VOID_C

#ifndef CC_CANVAS_BOOL_C
#define CC_CANVAS_BOOL_C(canvas) \
    CC_BOOL_C(CanvasHost, canvas)
#endif // !CC_CANVAS_BOOL_C

#ifndef CC_CANVAS_INT_C
#define CC_CANVAS_INT_C(canvas) \
    CC_INT_C(CanvasHost, canvas)
#endif // !CC_CANVAS_INT_C



#ifndef CCI_CANVAS_VOID_C
#define CCI_CANVAS_VOID_C(canvas, target) \
    CCI_VOID_C(CanvasHost, canvas, target)
#endif // !CCI_CANVAS_VOID_C

#ifndef CCI_CANVAS_BOOL_C
#define CCI_CANVAS_BOOL_C(canvas, target) \
    CCI_BOOL_C(CanvasHost, canvas, target)
#endif // !CCI_CANVAS_BOOL_C

#ifndef CCI_CANVAS_INT_C
#define CCI_CANVAS_INT_C(canvas, target) \
    CCI_INT_C(CanvasHost, canvas, target)
#endif // !CCI_CANVAS_INT_C



#ifndef CCI_CANVAS_GET_COLOR_C
#define CCI_CANVAS_GET_COLOR_C(canvas, target) \
    CCI_GET_COLOR_C(CanvasHost, canvas, target)
#endif // !CCI_CANVAS_GET_COLOR_C

#ifndef CCI_CANVAS_SET_COLOR_C
#define CCI_CANVAS_SET_COLOR_C(canvas, target, color) \
    CCI_SET_COLOR_C(CanvasHost, canvas, target, color)
#endif // !CCI_CANVAS_SET_COLOR_C



#ifndef CCI_CANVAS_GET_POINT_C
#define CCI_CANVAS_GET_POINT_C(canvas, target) \
    CCI_GET_POINT_C(CanvasHost, canvas, target)
#endif // !CCI_CANVAS_GET_POINT_C

#ifndef CCI_CANVAS_SET_POINT_C
#define CCI_CANVAS_SET_POINT_C(canvas, target, point) \
    CCI_SET_POINT_C(CanvasHost, canvas, target, point)
#endif // !CCI_CANVAS_SET_POINT_C



#ifndef CCI_CANVAS_GET_SIZE_C
#define CCI_CANVAS_GET_SIZE_C(canvas, target) \
    CCI_GET_SIZE_C(CanvasHost, canvas, target)
#endif // !CCI_CANVAS_GET_SIZE_C

#ifndef CCI_CANVAS_SET_SIZE_C
#define CCI_CANVAS_SET_SIZE_C(canvas, target, size) \
    CCI_SET_SIZE_C(CanvasHost, canvas, target, size)
#endif // !CCI_CANVAS_SET_SIZE_C



#ifndef CCI_CANVAS_GET_RECTANGLE_C
#define CCI_CANVAS_GET_RECTANGLE_C(canvas, target) \
    CCI_GET_RECTANGLE_C(CanvasHost, canvas, target)
#endif // !CCI_CANVAS_GET_RECTANGLE_C

#ifndef CCI_CANVAS_SET_RECTANGLE_C
#define CCI_CANVAS_SET_RECTANGLE_C(canvas, target, rectangle) \
    CCI_SET_RECTANGLE_C(CanvasHost, canvas, target, rectangle)
#endif // !CCI_CANVAS_SET_RECTANGLE_C

#endif // !GWC_CANVAS_MACROS_H
