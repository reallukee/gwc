//
// GWC.Native
//
//  Version : 0.1.0
//  MIT License
//  window_macros.hpp
//

#pragma once

#ifndef WINDOW_MACROS_HPP
#define WINDOW_MACROS_HPP

#ifdef __cplusplus

#ifndef INVOKE_CPP_VOID
#define INVOKE_CPP_VOID(window, target) \
    void* nativeHandle = window; \
    \
    IntPtr managedHandle = IntPtr(nativeHandle); \
    \
    if (WindowHandler::isNull(managedHandle)) \
    { \
        return; \
    }\
    \
    WindowHandler::invoke(managedHandle)->target;
#endif // !INVOKE_CPP_VOID

#ifndef INVOKE_CPP_BOOL
#define INVOKE_CPP_BOOL(window, target) \
    void* nativeHandle = window; \
    \
    IntPtr managedHandle = IntPtr(nativeHandle); \
    \
    if (WindowHandler::isNull(managedHandle)) \
    { \
        return false; \
    } \
    \
    return WindowHandler::invoke(managedHandle)->target;
#endif // !INVOKE_CPP_BOOL

#endif // __cplusplus

#endif // !WINDOW_MACROS_HPP
