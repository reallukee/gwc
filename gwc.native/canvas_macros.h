//
// :.:.:.:.:.
// GWC.Native
// v0.3.2
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

#include "COLOR.h"

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
    CCI_GET_COLOR_C(CanvasHost, canvas, target, color)
#endif // !CCI_CANVAS_GET_COLOR_C

#ifndef CCI_CANVAS_SET_COLOR_C
#define CCI_CANVAS_SET_COLOR_C(canvas, target, color) \
    CCI_SET_COLOR_C(CanvasHost, canvas, target, color)
#endif // !CCI_CANVAS_SET_COLOR_C

#endif // !GWC_CANVAS_MACROS_H
