//
// :.:.:.:.:.
// GWC.Native
// v0.3.1
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

#include "COLOR.h"

#include "CanvasHost.clr.hpp"

#ifndef CC_CANVAS_VOID_C
#define CC_CANVAS_VOID_C(canvas) \
    CanvasHost* host = static_cast<CanvasHost*>(canvas->canvas); \
    \
    if (host->isNull()) \
    { \
        return; \
    }
#endif // !CC_CANVAS_VOID_C

#ifndef CC_CANVAS_BOOL_C
#define CC_CANVAS_BOOL_C(canvas) \
    CanvasHost* host = static_cast<CanvasHost*>(canvas->canvas); \
    \
    if (host->isNull()) \
    { \
        return false; \
    }
#endif // !CC_CANVAS_BOOL_C

#ifndef CC_CANVAS_INT_C
#define CC_CANVAS_INT_C(canvas) \
    CanvasHost* host = static_cast<CanvasHost*>(canvas->canvas); \
    \
    if (host->isNull()) \
    { \
        return -1; \
    }
#endif // !CC_CANVAS_INT_C



#ifndef CCI_CANVAS_VOID_C
#define CCI_CANVAS_VOID_C(canvas, target) \
    CC_CANVAS_VOID_C(canvas) \
    \
    host->invoke()->target;
#endif // !CCI_CANVAS_VOID_C

#ifndef CCI_CANVAS_BOOL_C
#define CCI_CANVAS_BOOL_C(canvas, target) \
    CC_CANVAS_BOOL_C(canvas) \
    \
    return host->invoke()->target;
#endif // !CCI_CANVAS_BOOL_C

#ifndef CCI_CANVAS_INT_C
#define CCI_CANVAS_INT_C(canvas, target) \
    CC_CANVAS_INT_C(canvas) \
    \
    return host->invoke()->target;
#endif // !CCI_CANVAS_INT_C



#ifndef CCI_CANVAS_GET_COLOR_C
#define CCI_CANVAS_GET_COLOR_C(canvas, target) \
    if (canvas == NULL) \
    { \
        return color_new(0, 0, 0, 0); \
    } \
    \
    CanvasHost* host = static_cast<CanvasHost*>(canvas->canvas); \
    \
    if (host->isNull()) \
    { \
        throw gcnew NullReferenceException(""); \
    } \
    \
    Drawing::Color^ managedBorderColor = host->invoke()->target; \
    \
    Color* nativeColor = color_new( \
        (int)managedBorderColor->A, \
        (int)managedBorderColor->R, \
        (int)managedBorderColor->G, \
        (int)managedBorderColor->B \
    ); \
    \
    return nativeColor;
#endif // !CCI_CANVAS_GET_COLOR_C

#ifndef CCI_CANVAS_SET_COLOR_C
#define CCI_CANVAS_SET_COLOR_C(canvas, target, color) \
    if (canvas == NULL || color == NULL) \
    { \
        return; \
    } \
    \
    CanvasHost* host = static_cast<CanvasHost*>(canvas->canvas); \
    \
    if (host->isNull()) \
    { \
        throw gcnew NullReferenceException(""); \
    } \
    \
    const Color* nativeColor = color; \
    \
    Drawing::Color managedColor = Drawing::Color::FromArgb( \
        color_getAlpha(nativeColor), \
        color_getRed  (nativeColor), \
        color_getGreen(nativeColor), \
        color_getBlue (nativeColor) \
    ); \
    \
    host->invoke()->target = managedColor;
#endif // !CCI_CANVAS_SET_COLOR_C

#endif // !GWC_CANVAS_MACROS_H
