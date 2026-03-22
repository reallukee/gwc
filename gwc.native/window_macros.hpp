//
// :.:.:.:.:.
// GWC.Native
// v0.1.0
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

#endif // __cplusplus

#endif // !WINDOW_MACROS_HPP
