//
// :.:.:.:.:.
// GWC.Native
// v0.1.1
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// canvas_macros.hpp
//  Licenza MIT
//

#pragma once

#ifndef CANVAS_MACROS_HPP
#define CANVAS_MACROS_HPP

#ifdef __cplusplus

#include "Color.hpp"

#ifndef INVOKE_CANVAS_VOID_CPP
#define INVOKE_CANVAS_VOID_CPP(canvas, target) \
    void* nativeHandle = canvas; \
    \
    IntPtr managedHandle = IntPtr(nativeHandle); \
    \
    if (CanvasHandler::IsNull(managedHandle)) \
    { \
        return; \
    } \
    \
    CanvasHandler::Invoke(managedHandle)->target;
#endif // !INVOKE_CANVAS_VOID_CPP

#ifndef INVOKE_CANVAS_BOOL_CPP
#define INVOKE_CANVAS_BOOL_CPP(canvas, target) \
    void* nativeHandle = canvas; \
    \
    IntPtr managedHandle = IntPtr(nativeHandle); \
    \
    if (CanvasHandler::IsNull(managedHandle)) \
    { \
        return false; \
    } \
    \
    return CanvasHandler::Invoke(managedHandle)->target;
#endif // !INVOKE_CANVAS_BOOL_CPP

#ifndef INVOKE_CANVAS_GET_COLOR_CPP
#define INVOKE_CANVAS_GET_COLOR_CPP(canvas, target) \
    void* nativeHandle = canvas; \
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
    Color nativeColor = Color( \
        (int)managedBorderColor->A, \
        (int)managedBorderColor->R, \
        (int)managedBorderColor->G, \
        (int)managedBorderColor->B \
    ); \
    \
    return nativeColor;
#endif // !INVOKE_CANVAS_GET_COLOR_CPP

#ifndef INVOKE_CANVAS_SET_COLOR_CPP
#define INVOKE_CANVAS_SET_COLOR_CPP(canvas, target, color) \
    void* nativeHandle = canvas; \
    \
    IntPtr managedHandle = IntPtr(nativeHandle); \
    \
    if (CanvasHandler::IsNull(managedHandle)) \
    { \
        throw gcnew NullReferenceException(""); \
    } \
    \
    Color nativeColor = color; \
    \
    Drawing::Color managedColor = Drawing::Color::FromArgb( \
        nativeColor.getAlpha(), \
        nativeColor.getRed(), \
        nativeColor.getGreen(), \
        nativeColor.getBlue() \
    ); \
    \
    CanvasHandler::Invoke(managedHandle)->BorderColor = managedColor;
#endif // !INVOKE_CANVAS_SET_COLOR_CPP

#endif // __cplusplus

#endif // !CANVAS_MACROS_HPP
