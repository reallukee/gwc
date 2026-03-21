//
// GWC.Native
//
//  Version : 0.1.0
//  MIT License
//  window_macros.h
//

#pragma once

#ifndef WINDOW_MACROS_H
#define WINDOW_MACROS_H

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

#endif // !WINDOW_MACROS_H
