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

#ifndef INVOKE_C_VOID
#define INVOKE_C_VOID(window, target) \
    WINDOW* nativeHandle = window; \
    \
    IntPtr managedHandle = IntPtr(nativeHandle); \
    \
    if (WindowHandler::isNull(managedHandle)) \
    { \
        return; \
    }\
    \
    WindowHandler::invoke(managedHandle)->target;
#endif // !INVOKE_C_VOID

#ifndef INVOKE_C_BOOL
#define INVOKE_C_BOOL(window, target) \
    WINDOW* nativeHandle = window; \
    \
    IntPtr managedHandle = IntPtr(nativeHandle); \
    \
    if (WindowHandler::isNull(managedHandle)) \
    { \
        return false; \
    } \
    \
    return WindowHandler::invoke(managedHandle)->target;
#endif // !INVOKE_C_BOOL

#endif // !WINDOW_MACROS_H
