//
// :.:.:.:.:.
// GWC.Native
// v0.3.1
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

#include "Color.hpp"

#include "CanvasHost.clr.hpp"

#ifndef CC_CANVAS_VOID_CPP
#define CC_CANVAS_VOID_CPP(canvas) \
    CanvasHost* host = static_cast<CanvasHost*>(canvas); \
    \
    if (host->isNull()) \
    { \
        return; \
    }
#endif // !CC_CANVAS_VOID_CPP

#ifndef CC_CANVAS_BOOL_CPP
#define CC_CANVAS_BOOL_CPP(canvas) \
    CanvasHost* host = static_cast<CanvasHost*>(canvas); \
    \
    if (host->isNull()) \
    { \
        return false; \
    }
#endif // !CC_CANVAS_BOOL_CPP

#ifndef CC_CANVAS_INT_CPP
#define CC_CANVAS_INT_CPP(canvas) \
    CanvasHost* host = static_cast<CanvasHost*>(canvas); \
    \
    if (host->isNull()) \
    { \
        return -1; \
    }
#endif // !CC_CANVAS_INT_CPP



#ifndef CCI_CANVAS_VOID_CPP
#define CCI_CANVAS_VOID_CPP(canvas, target) \
    CC_CANVAS_VOID_CPP(canvas) \
    \
    host->invoke()->target;
#endif // !CCI_CANVAS_VOID_CPP

#ifndef CCI_CANVAS_BOOL_CPP
#define CCI_CANVAS_BOOL_CPP(canvas, target) \
    CC_CANVAS_BOOL_CPP(canvas) \
    \
    return host->invoke()->target;
#endif // !CCI_CANVAS_BOOL_CPP

#ifndef CCI_CANVAS_INT_CPP
#define CCI_CANVAS_INT_CPP(canvas, target) \
    CC_CANVAS_INT_CPP(canvas) \
    \
    return host->invoke()->target;
#endif // !CCI_CANVAS_INT_CPP



#ifndef CCI_CANVAS_GET_COLOR_CPP
#define CCI_CANVAS_GET_COLOR_CPP(canvas, target) \
    CanvasHost* host = static_cast<CanvasHost*>(canvas); \
    \
    if (host->isNull()) \
    { \
        throw gcnew NullReferenceException(""); \
    } \
    \
    Drawing::Color^ managedBorderColor = host->invoke()->target; \
    \
    Color nativeColor = Color( \
        (int)managedBorderColor->A, \
        (int)managedBorderColor->R, \
        (int)managedBorderColor->G, \
        (int)managedBorderColor->B \
    ); \
    \
    return nativeColor;
#endif // !CCI_CANVAS_GET_COLOR_CPP

#ifndef CCI_CANVAS_SET_COLOR_CPP
#define CCI_CANVAS_SET_COLOR_CPP(canvas, target, color) \
    CanvasHost* host = static_cast<CanvasHost*>(canvas); \
    \
    if (host->isNull()) \
    { \
        throw gcnew NullReferenceException(""); \
    } \
    \
    Color nativeColor = color; \
    \
    Drawing::Color managedColor = Drawing::Color::FromArgb( \
        nativeColor.getAlpha(), \
        nativeColor.getRed  (), \
        nativeColor.getGreen(), \
        nativeColor.getBlue () \
    ); \
    \
    host->invoke()->target = managedColor;
#endif // !CCI_CANVAS_SET_COLOR_CPP

#endif // __cplusplus

#endif // !GWC_CANVAS_MACROS_HPP
