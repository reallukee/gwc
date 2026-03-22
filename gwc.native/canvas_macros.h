//
// :.:.:.:.:.
// GWC.Native
// v0.1.0
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// canvas_macros.h
//  Licenza MIT
//

#pragma once

#ifndef CANVAS_MACROS_H
#define CANVAS_MACROS_H

#ifndef INVOKE_CANVAS_VOID_C
#define INVOKE_CANVAS_VOID_C(canvas, target) \
    void* nativeHandle = canvas->canvas; \
    \
    IntPtr managedHandle = IntPtr(nativeHandle);\
    \
    if (CanvasHandler::IsNull(managedHandle)) \
    { \
        return; \
    } \
    \
    CanvasHandler::Invoke(managedHandle)->target;
#endif // !INVOKE_CANVAS_VOID_C

#ifndef INVOKE_CANVAS_BOOL_C
#define INVOKE_CANVAS_BOOL_C(canvas, target) \
    void* nativeHandle = canvas->canvas; \
    \
    IntPtr managedHandle = IntPtr(nativeHandle);\
    \
    if (CanvasHandler::IsNull(managedHandle)) \
    { \
        return false; \
    } \
    \
    return CanvasHandler::Invoke(managedHandle)->target;
#endif // !INVOKE_CANVAS_BOOL_C

#endif // !CANVAS_MACROS_H
