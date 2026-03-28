//
// :.:.:.:.:.
// GWC.Native
// v0.1.1
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// window_macros.h
//  Licenza MIT
//

#pragma once

#ifndef WINDOW_MACROS_H
#define WINDOW_MACROS_H

#include "COLOR.h"

#ifndef INVOKE_WINDOW_VOID_C
#define INVOKE_WINDOW_VOID_C(window, target) \
    void* nativeHandle = window->window; \
    \
    IntPtr managedHandle = IntPtr(nativeHandle); \
    \
    if (WindowHandler::IsNull(managedHandle)) \
    { \
        return; \
    } \
    \
    WindowHandler::Invoke(managedHandle)->target;
#endif // !INVOKE_WINDOW_VOID_C

#ifndef INVOKE_WINDOW_BOOL_C
#define INVOKE_WINDOW_BOOL_C(window, target) \
    void* nativeHandle = window->window; \
    \
    IntPtr managedHandle = IntPtr(nativeHandle); \
    \
    if (WindowHandler::IsNull(managedHandle)) \
    { \
        return false; \
    } \
    \
    return WindowHandler::Invoke(managedHandle)->target;
#endif // !INVOKE_WINDOW_BOOL_C

#ifndef INVOKE_WINDOW_GET_COLOR_C
#define INVOKE_WINDOW_GET_COLOR_C(window, target) \
    if (window == NULL) \
    { \
        return color_new(0, 0, 0, 0); \
    } \
    \
    void* nativeHandle = window->window; \
    \
    IntPtr managedHandle = IntPtr(nativeHandle); \
    \
    if (WindowHandler::IsNull(managedHandle)) \
    { \
        \
        throw gcnew NullReferenceException(""); \
    } \
    \
    Drawing::Color^ managedBorderColor = WindowHandler::Invoke(managedHandle)->target; \
    \
    COLOR* nativeColor = color_new( \
        (int)managedBorderColor->A, \
        (int)managedBorderColor->R, \
        (int)managedBorderColor->G, \
        (int)managedBorderColor->B \
    ); \
    \
    return nativeColor;
#endif // !INVOKE_WINDOW_GET_COLOR_C

#ifndef INVOKE_WINDOW_SET_COLOR_C
#define INVOKE_WINDOW_SET_COLOR_C(window, target, color) \
    if (window == NULL || color == NULL) \
    { \
        return; \
    } \
    \
    void* nativeHandle = window->window; \
    \
    IntPtr managedHandle = IntPtr(nativeHandle); \
    \
    if (WindowHandler::IsNull(managedHandle)) \
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
    WindowHandler::Invoke(managedHandle)->target = managedColor;
#endif // !INVOKE_WINDOW_SET_COLOR_C

#endif // !WINDOW_MACROS_H
