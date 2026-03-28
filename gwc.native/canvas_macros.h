//
// :.:.:.:.:.
// GWC.Native
// v0.1.1
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// canvas_macros.h
//  Licenza MIT
//

#pragma once

#ifndef CANVAS_MACROS_H
#define CANVAS_MACROS_H

#include "COLOR.h"

#ifndef INVOKE_CANVAS_VOID_C
#define INVOKE_CANVAS_VOID_C(canvas, target) \
    void* nativeHandle = canvas->canvas; \
    \
    IntPtr managedHandle = IntPtr(nativeHandle); \
    \
    if (CanvasHandler::IsNull(managedHandle)) \
    { \
        return; \
    } \
    \
    CanvasHandler::Invoke(managedHandle)->target;
#endif // !INVOKE_CANVAS_VOID_C

#ifndef INVOKE_CANVAS_BOOL_C
#define INVOKE_CANVAS_BOOL_C(canvas, target) \
    void* nativeHandle = canvas->canvas; \
    \
    IntPtr managedHandle = IntPtr(nativeHandle); \
    \
    if (CanvasHandler::IsNull(managedHandle)) \
    { \
        return false; \
    } \
    \
    return CanvasHandler::Invoke(managedHandle)->target;
#endif // !INVOKE_CANVAS_BOOL_C

#ifndef INVOKE_CANVAS_GET_COLOR_C
#define INVOKE_CANVAS_GET_COLOR_C(canvas, target) \
    if (canvas == NULL) \
    { \
        return color_new(0, 0, 0, 0); \
    } \
    \
    void* nativeHandle = canvas->canvas; \
    \
    IntPtr managedHandle = IntPtr(nativeHandle); \
    \
    if (CanvasHandler::IsNull(managedHandle)) \
    { \
        \
        throw gcnew NullReferenceException(""); \
    } \
    \
    Drawing::Color^ managedBorderColor = CanvasHandler::Invoke(managedHandle)->target; \
    \
    COLOR* nativeColor = color_new( \
        (int)managedBorderColor->A, \
        (int)managedBorderColor->R, \
        (int)managedBorderColor->G, \
        (int)managedBorderColor->B \
    ); \
    \
    return nativeColor;
#endif // !INVOKE_CANVAS_GET_COLOR_C

#ifndef INVOKE_CANVAS_SET_COLOR_C
#define INVOKE_CANVAS_SET_COLOR_C(canvas, target, color) \
    if (canvas == NULL || color == NULL) \
    { \
        return; \
    } \
    \
    void* nativeHandle = canvas->canvas; \
    \
    IntPtr managedHandle = IntPtr(nativeHandle); \
    \
    if (CanvasHandler::IsNull(managedHandle)) \
    { \
        throw gcnew NullReferenceException(""); \
    } \
    \
    const COLOR* nativeColor = color; \
    \
    Drawing::Color managedColor = Drawing::Color::FromArgb( \
        color_getAlpha(nativeColor), \
        color_getRed(nativeColor), \
        color_getGreen(nativeColor), \
        color_getBlue(nativeColor) \
    ); \
    \
    CanvasHandler::Invoke(managedHandle)->BorderColor = managedColor;
#endif // !INVOKE_CANVAS_SET_COLOR_C

#endif // !CANVAS_MACROS_H
