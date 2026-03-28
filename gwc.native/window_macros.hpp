//
// :.:.:.:.:.
// GWC.Native
// v0.1.1
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// window_macros.hpp
//  Licenza MIT
//

#pragma once

#ifndef WINDOW_MACROS_HPP
#define WINDOW_MACROS_HPP

#ifdef __cplusplus

#include "Color.hpp"

#ifndef INVOKE_WINDOW_VOID_CPP
#define INVOKE_WINDOW_VOID_CPP(window, target) \
    void* nativeHandle = window; \
    \
    IntPtr managedHandle = IntPtr(nativeHandle); \
    \
    if (WindowHandler::IsNull(managedHandle)) \
    { \
        return; \
    } \
    \
    WindowHandler::Invoke(managedHandle)->target;
#endif // !INVOKE_WINDOW_VOID_CPP

#ifndef INVOKE_WINDOW_BOOL_CPP
#define INVOKE_WINDOW_BOOL_CPP(window, target) \
    void* nativeHandle = window; \
    \
    IntPtr managedHandle = IntPtr(nativeHandle); \
    \
    if (WindowHandler::IsNull(managedHandle)) \
    { \
        return false; \
    } \
    \
    return WindowHandler::Invoke(managedHandle)->target;
#endif // !INVOKE_WINDOW_BOOL_CPP

#ifndef INVOKE_WINDOW_GET_COLOR_CPP
#define INVOKE_WINDOW_GET_COLOR_CPP(window, target) \
    void* nativeHandle = window; \
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
    Color nativeColor = Color( \
        (int)managedBorderColor->A, \
        (int)managedBorderColor->R, \
        (int)managedBorderColor->G, \
        (int)managedBorderColor->B \
    ); \
    \
    return nativeColor;
#endif // !INVOKE_WINDOW_GET_COLOR_CPP

#ifndef INVOKE_WINDOW_SET_COLOR_CPP
#define INVOKE_WINDOW_SET_COLOR_CPP(window, target, color) \
    void* nativeHandle = window; \
    \
    IntPtr managedHandle = IntPtr(nativeHandle); \
    \
    if (WindowHandler::IsNull(managedHandle)) \
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
    WindowHandler::Invoke(managedHandle)->target = managedColor;
#endif // !INVOKE_WINDOW_SET_COLOR_CPP

#endif // __cplusplus

#endif // !WINDOW_MACROS_HPP
