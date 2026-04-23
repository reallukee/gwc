//
// :.:.:.:.:.
// GWC.Native
// v0.3.2
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// macros.h
//  Licenza MIT
//

#pragma once

#ifndef GWC_MACROS_H
#define GWC_MACROS_H

#ifndef CC_VOID_C
#define CC_VOID_C(host, object) \
    host* _host = static_cast<host*>(object->object); \
    \
    if (_host->isNull()) \
    { \
        return; \
    }
#endif // !CC_VOID_C

#ifndef CC_BOOL_C
#define CC_BOOL_C(host, object) \
    host* _host = static_cast<host*>(object->object); \
    \
    if (_host->isNull()) \
    { \
        return false; \
    }
#endif // !CC_BOOL_C

#ifndef CC_INT_C
#define CC_INT_C(host, object) \
    host* _host = static_cast<host*>(object->object); \
    \
    if (_host->isNull()) \
    { \
        return -1; \
    }
#endif // !CC_INT_C



#ifndef CCI_VOID_C
#define CCI_VOID_C(host, object, target) \
    CC_VOID_C(host, object) \
    \
    _host->invoke()->target;
#endif // !CCI_VOID_C

#ifndef CCI_BOOL_C
#define CCI_BOOL_C(host, object, target) \
    CC_BOOL_C(host, object) \
    \
    return _host->invoke()->target;
#endif // !CCI_BOOL_C

#ifndef CCI_INT_C
#define CCI_INT_C(host, object, target) \
    CC_INT_C(host, object) \
    \
    return _host->invoke()->target;
#endif // !CCI_INT_C



#ifndef CCI_GET_COLOR_C
#define CCI_GET_COLOR_C(host, object, target, color) \
    if (object == NULL) \
    { \
        return NULL; \
    } \
    \
    host* _host = static_cast<host*>(object->object); \
    \
    if (_host->isNull()) \
    { \
        throw gcnew NullReferenceException(""); \
    } \
    \
    Drawing::Color^ managedBorderColor = _host->invoke()->target; \
    \
    Color* nativeColor = color_new( \
        (int)managedBorderColor->A, \
        (int)managedBorderColor->R, \
        (int)managedBorderColor->G, \
        (int)managedBorderColor->B \
    ); \
    \
    return nativeColor;
#endif // !CCI_GET_COLOR_C

#ifndef CCI_SET_COLOR_C
#define CCI_SET_COLOR_C(host, object, target, color) \
    if (object == NULL || color == NULL) \
    { \
        return; \
    } \
    \
    host* _host = static_cast<host*>(object->object); \
    \
    if (_host->isNull()) \
    { \
        throw gcnew NullReferenceException(""); \
    } \
    \
    const Color* nativeColor = color; \
    \
    Drawing::Color managedColor = Drawing::Color::FromArgb( \
        color_getAlpha(nativeColor), \
        color_getRed  (nativeColor), \
        color_getGreen(nativeColor), \
        color_getBlue (nativeColor) \
    ); \
    \
    _host->invoke()->target = managedColor;
#endif // !CCI_SET_COLOR_C

#endif // !GWC_MACROS_H
