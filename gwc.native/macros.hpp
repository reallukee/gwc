//
// :.:.:.:.:.
// GWC.Native
// v0.3.2
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// macros.hpp
//  Licenza MIT
//

#pragma once

#ifndef GWC_MACROS_HPP
#define GWC_MACROS_HPP

#ifdef __cplusplus

#ifndef CC_VOID_CPP
#define CC_VOID_CPP(host, object) \
    host* _host = static_cast<host*>(object); \
    \
    if (_host->isNull()) \
    { \
        return; \
    }
#endif // !CC_VOID_CPP

#ifndef CC_BOOL_CPP
#define CC_BOOL_CPP(host, object) \
    host* _host = static_cast<host*>(object); \
    \
    if (_host->isNull()) \
    { \
        return false; \
    }
#endif // !CC_BOOL_CPP

#ifndef CC_INT_CPP
#define CC_INT_CPP(host, object) \
    host* _host = static_cast<host*>(object); \
    \
    if (_host->isNull()) \
    { \
        return -1; \
    }
#endif // !CC_INT_CPP



#ifndef CCI_VOID_CPP
#define CCI_VOID_CPP(host, object, target) \
    CC_VOID_CPP(host, object) \
    \
    _host->invoke()->target;
#endif // !CCI_VOID_CPP

#ifndef CCI_BOOL_CPP
#define CCI_BOOL_CPP(host, object, target) \
    CC_BOOL_CPP(host, object) \
    \
    return _host->invoke()->target;
#endif // !CCI_BOOL_CPP

#ifndef CCI_INT_CPP
#define CCI_INT_CPP(host, object, target) \
    CC_INT_CPP(host, object) \
    \
    return _host->invoke()->target;
#endif // !CCI_INT_CPP



#ifndef CCI_GET_COLOR_CPP
#define CCI_GET_COLOR_CPP(host, object, target, color) \
    host* _host = static_cast<host*>(object); \
    \
    if (_host->isNull()) \
    { \
        throw gcnew NullReferenceException(""); \
    } \
    \
    Drawing::Color^ managedBorderColor = _host->invoke()->target; \
    \
    Color nativeColor = Color( \
        (int)managedBorderColor->A, \
        (int)managedBorderColor->R, \
        (int)managedBorderColor->G, \
        (int)managedBorderColor->B \
    ); \
    \
    return nativeColor;
#endif // !CCI_GET_COLOR_CPP

#ifndef CCI_SET_COLOR_CPP
#define CCI_SET_COLOR_CPP(host, object, target, color) \
    host* _host = static_cast<host*>(object); \
    \
    if (_host->isNull()) \
    { \
        throw gcnew NullReferenceException(""); \
    } \
    \
    const Color nativeColor = color; \
    \
    Drawing::Color managedColor = Drawing::Color::FromArgb( \
        nativeColor.getAlpha(), \
        nativeColor.getRed  (), \
        nativeColor.getGreen(), \
        nativeColor.getBlue () \
    ); \
    \
    _host->invoke()->target = managedColor;
#endif // !CCI_SET_COLOR_CPP

#endif // __cplusplus

#endif // !GWC_MACROS_HPP
