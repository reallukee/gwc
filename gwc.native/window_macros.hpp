//
// :.:.:.:.:.
// GWC.Native
// v0.2.0
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// window_macros.hpp
//  Licenza MIT
//

#pragma once

#ifndef GWC_WINDOW_MACROS_HPP
#define GWC_WINDOW_MACROS_HPP

#ifdef __cplusplus

#include "Color.hpp"

#ifndef CC_WINDOW_VOID_CPP
#define CC_WINDOW_VOID_CPP(window) \
    CLRWindow nativeHandle = window; \
    \
    IntPtr managedHandle = IntPtr(nativeHandle); \
    \
    if (WindowHandler::IsNull(managedHandle)) \
    { \
        return; \
    }
#endif // !CC_WINDOW_VOID_CPP

#ifndef CC_WINDOW_BOOL_CPP
#define CC_WINDOW_BOOL_CPP(window) \
    CLRWindow nativeHandle = window; \
    \
    IntPtr managedHandle = IntPtr(nativeHandle); \
    \
    if (WindowHandler::IsNull(managedHandle)) \
    { \
        return false; \
    }
#endif // !CC_WINDOW_BOOL_CPP

#ifndef CC_WINDOW_INT_CPP
#define CC_WINDOW_INT_CPP(window) \
    CLRWindow nativeHandle = window; \
    \
    IntPtr managedHandle = IntPtr(nativeHandle); \
    \
    if (WindowHandler::IsNull(managedHandle)) \
    { \
        return -1; \
    }
#endif // !CC_WINDOW_INT_CPP



#ifndef CCI_WINDOW_VOID_CPP
#define CCI_WINDOW_VOID_CPP(window, target) \
    CC_WINDOW_VOID_CPP(window) \
    \
    WindowHandler::Invoke(managedHandle)->target;
#endif // !CCI_WINDOW_VOID_CPP

#ifndef CCI_WINDOW_BOOL_CPP
#define CCI_WINDOW_BOOL_CPP(window, target) \
    CC_WINDOW_BOOL_CPP(window) \
    \
    return WindowHandler::Invoke(managedHandle)->target;
#endif // !CCI_WINDOW_BOOL_CPP

#ifndef CCI_WINDOW_INT_CPP
#define CCI_WINDOW_INT_CPP(window, target) \
    CC_WINDOW_INT_CPP(window) \
    \
    return WindowHandler::Invoke(managedHandle)->target;
#endif // !CCI_WINDOW_INT_CPP



#ifndef CCI_WINDOW_GET_COLOR_CPP
#define CCI_WINDOW_GET_COLOR_CPP(window, target) \
    CLRWindow nativeHandle = window; \
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
#endif // !CCI_WINDOW_GET_COLOR_CPP

#ifndef CCI_WINDOW_SET_COLOR_CPP
#define CCI_WINDOW_SET_COLOR_CPP(window, target, color) \
    CLRWindow nativeHandle = window; \
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
#endif // !CCI_WINDOW_SET_COLOR_CPP

#endif // __cplusplus

#endif // !GWC_WINDOW_MACROS_HPP
