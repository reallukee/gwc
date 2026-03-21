//
// GWC.Native
//
//  Version : 0.1.0
//  MIT License
//  canvas_macros.hpp
//

#pragma once

#ifndef CANVAS_MACROS_HPP
#define CANVAS_MACROS_HPP

#ifdef __cplusplus

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

#endif // __cplusplus

#endif // !CANVAS_MACROS_HPP
