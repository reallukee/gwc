//
// :.:.:.:.:.
// GWC.Native
// v0.2.0
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

#include "COLOR.h"

#ifndef CC_WINDOW_VOID_C
#define CC_WINDOW_VOID_C(window) \
    CLRWindow nativeHandle = window->window; \
    \
    IntPtr managedHandle = IntPtr(nativeHandle); \
    \
    if (WindowHandler::IsNull(managedHandle)) \
    { \
        return; \
    }
#endif // !CC_WINDOW_VOID_C

#ifndef CC_WINDOW_BOOL_C
#define CC_WINDOW_BOOL_C(window) \
    CLRWindow nativeHandle = window->window; \
    \
    IntPtr managedHandle = IntPtr(nativeHandle); \
    \
    if (WindowHandler::IsNull(managedHandle)) \
    { \
        return false; \
    }
#endif // !CC_WINDOW_BOOL_C

#ifndef CC_WINDOW_INT_C
#define CC_WINDOW_INT_C(window) \
    CLRWindow nativeHandle = window->window; \
    \
    IntPtr managedHandle = IntPtr(nativeHandle); \
    \
    if (WindowHandler::IsNull(managedHandle)) \
    { \
        return -1; \
    }
#endif // !CC_WINDOW_INT_C



#ifndef CCI_WINDOW_VOID_C
#define CCI_WINDOW_VOID_C(window, target) \
    CC_WINDOW_VOID_C(window) \
    \
    WindowHandler::Invoke(managedHandle)->target;
#endif // !CCI_WINDOW_VOID_C

#ifndef CCI_WINDOW_BOOL_C
#define CCI_WINDOW_BOOL_C(window, target) \
    CC_WINDOW_BOOL_C(window) \
    \
    return WindowHandler::Invoke(managedHandle)->target;
#endif // !CCI_WINDOW_BOOL_C

#ifndef CCI_WINDOW_INT_C
#define CCI_WINDOW_INT_C(window, target) \
    CC_WINDOW_INT_C(window) \
    \
    return WindowHandler::Invoke(managedHandle)->target;
#endif // !CCI_WINDOW_INT_C



#ifndef CCI_WINDOW_GET_COLOR_C
#define CCI_WINDOW_GET_COLOR_C(window, target) \
    if (window == NULL) \
    { \
        return color_new(0, 0, 0, 0); \
    } \
    \
    CLRWindow nativeHandle = window->window; \
    \
    IntPtr managedHandle = IntPtr(nativeHandle); \
    \
    if (WindowHandler::IsNull(managedHandle)) \
    { \
        throw gcnew NullReferenceException(""); \
    } \
    \
    Drawing::Color^ managedBorderColor = WindowHandler::Invoke(managedHandle)->target; \
    \
    Color* nativeColor = color_new( \
        (int)managedBorderColor->A, \
        (int)managedBorderColor->R, \
        (int)managedBorderColor->G, \
        (int)managedBorderColor->B \
    ); \
    \
    return nativeColor;
#endif // !CCI_WINDOW_GET_COLOR_C

#ifndef CCI_WINDOW_SET_COLOR_C
#define CCI_WINDOW_SET_COLOR_C(window, target, color) \
    if (window == NULL || color == NULL) \
    { \
        return; \
    } \
    \
    CLRWindow nativeHandle = window->window; \
    \
    IntPtr managedHandle = IntPtr(nativeHandle); \
    \
    if (WindowHandler::IsNull(managedHandle)) \
    { \
        throw gcnew NullReferenceException(""); \
    } \
    \
    const Color* nativeColor = color; \
    \
    Drawing::Color managedColor = Drawing::Color::FromArgb( \
        color_getAlpha(nativeColor), \
        color_getRed(nativeColor), \
        color_getGreen(nativeColor), \
        color_getBlue(nativeColor) \
    ); \
    \
    WindowHandler::Invoke(managedHandle)->target = managedColor;
#endif // !CCI_WINDOW_SET_COLOR_C

#endif // !GWC_WINDOW_MACROS_H
