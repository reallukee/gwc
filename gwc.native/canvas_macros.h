//
// :.:.:.:.:.
// GWC.Native
// v0.3.0
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

#ifndef CC_CANVAS_VOID_C
#define CC_CANVAS_VOID_C(canvas) \
    CLRCanvas nativeHandle = canvas->canvas; \
    \
    IntPtr managedHandle = IntPtr(nativeHandle); \
    \
    if (CanvasHandler::IsNull(managedHandle)) \
    { \
        return; \
    }
#endif // !CC_CANVAS_VOID_C

#ifndef CC_CANVAS_BOOL_C
#define CC_CANVAS_BOOL_C(canvas) \
    CLRCanvas nativeHandle = canvas->canvas; \
    \
    IntPtr managedHandle = IntPtr(nativeHandle); \
    \
    if (CanvasHandler::IsNull(managedHandle)) \
    { \
        return false; \
    }
#endif // !CC_CANVAS_BOOL_C

#ifndef CC_CANVAS_INT_C
#define CC_CANVAS_INT_C(canvas) \
    CLRCanvas nativeHandle = canvas->canvas; \
    \
    IntPtr managedHandle = IntPtr(nativeHandle); \
    \
    if (CanvasHandler::IsNull(managedHandle)) \
    { \
        return -1; \
    }
#endif // !CC_CANVAS_INT_C



#ifndef CCI_CANVAS_VOID_C
#define CCI_CANVAS_VOID_C(canvas, target) \
    CC_CANVAS_VOID_C(canvas) \
    \
    CanvasHandler::Invoke(managedHandle)->target;
#endif // !CCI_CANVAS_VOID_C

#ifndef CCI_CANVAS_BOOL_C
#define CCI_CANVAS_BOOL_C(canvas, target) \
    CC_CANVAS_BOOL_C(canvas) \
    \
    return CanvasHandler::Invoke(managedHandle)->target;
#endif // !CCI_CANVAS_BOOL_C

#ifndef CCI_CANVAS_INT_C
#define CCI_CANVAS_INT_C(canvas, target) \
    CC_CANVAS_INT_C(canvas) \
    \
    return CanvasHandler::Invoke(managedHandle)->target;
#endif // !CCI_CANVAS_INT_C



#ifndef CCI_CANVAS_GET_COLOR_C
#define CCI_CANVAS_GET_COLOR_C(canvas, target) \
    if (canvas == NULL) \
    { \
        return color_new(0, 0, 0, 0); \
    } \
    \
    CLRCanvas nativeHandle = canvas->canvas; \
    \
    IntPtr managedHandle = IntPtr(nativeHandle); \
    \
    if (CanvasHandler::IsNull(managedHandle)) \
    { \
        throw gcnew NullReferenceException(""); \
    } \
    \
    Drawing::Color^ managedBorderColor = CanvasHandler::Invoke(managedHandle)->target; \
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
    CLRCanvas nativeHandle = canvas->canvas; \
    \
    IntPtr managedHandle = IntPtr(nativeHandle); \
    \
    if (CanvasHandler::IsNull(managedHandle)) \
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
    CanvasHandler::Invoke(managedHandle)->BorderColor = managedColor;
#endif // !CCI_CANVAS_SET_COLOR_C

#endif // !GWC_CANVAS_MACROS_H
