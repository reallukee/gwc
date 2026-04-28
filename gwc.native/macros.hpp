//
// :.:.:.:.:.
// GWC.Native
// v0.3.3
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
#define CCI_GET_COLOR_CPP(host, object, target) \
    host* _host = static_cast<host*>(object); \
    \
    if (_host->isNull()) \
    { \
        throw gcnew NullReferenceException(""); \
    } \
    \
    Drawing::Color^ managedColor = _host->invoke()->target; \
    \
    gColor nativeColor = gColor( \
        (int)managedColor->A, \
        (int)managedColor->R, \
        (int)managedColor->G, \
        (int)managedColor->B \
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
    const gColor nativeColor = color; \
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



#ifndef CCI_GET_POINT_CPP
#define CCI_GET_POINT_CPP(host, object, target) \
    host* _host = static_cast<host*>(object); \
    \
    if (_host->isNull()) \
    { \
        throw gcnew NullReferenceException(""); \
    } \
    \
    Drawing::Point^ managedPoint = _host->invoke()->target; \
    \
    gPoint nativePoint = gPoint( \
        (int)managedPoint->X, \
        (int)managedPoint->Y \
    ); \
    \
    return nativePoint;
#endif // !CCI_GET_POINT_CPP

#ifndef CCI_SET_POINT_CPP
#define CCI_SET_POINT_CPP(host, object, target, point) \
    host* _host = static_cast<host*>(object); \
    \
    if (_host->isNull()) \
    { \
        throw gcnew NullReferenceException(""); \
    } \
    \
    const gPoint nativePoint = point; \
    \
    Drawing::Point managedPoint = Drawing::Point::FromArgb( \
        nativePoint.getX(), \
        nativePoint.getY() \
    ); \
    \
    _host->invoke()->target = managedPoint;
#endif // !CCI_SET_POINT_CPP



#ifndef CCI_GET_SIZE_CPP
#define CCI_GET_SIZE_CPP(host, object, target) \
    host* _host = static_cast<host*>(object); \
    \
    if (_host->isNull()) \
    { \
        throw gcnew NullReferenceException(""); \
    } \
    \
    Drawing::Size^ managedSize = _host->invoke()->target; \
    \
    gSize nativeSize = gSize( \
        (int)managedSize->Width, \
        (int)managedSize->Height \
    ); \
    \
    return nativeSize;
#endif // !CCI_GET_SIZE_CPP

#ifndef CCI_SET_SIZE_CPP
#define CCI_SET_SIZE_CPP(host, object, target, size) \
    host* _host = static_cast<host*>(object); \
    \
    if (_host->isNull()) \
    { \
        throw gcnew NullReferenceException(""); \
    } \
    \
    const gSize nativeSize = size; \
    \
    Drawing::Size managedSize = Drawing::Size::FromArgb( \
        nativeSize.getWidth (), \
        nativeSize.getHeight() \
    ); \
    \
    _host->invoke()->target = managedSize;
#endif // !CCI_SET_SIZE_CPP



#ifndef CCI_GET_RECTANGLE_CPP
#define CCI_GET_RECTANGLE_CPP(host, object, target) \
    host* _host = static_cast<host*>(object); \
    \
    if (_host->isNull()) \
    { \
        throw gcnew NullReferenceException(""); \
    } \
    \
    Drawing::Rectangle^ managedRectangle = _host->invoke()->target; \
    \
    gRectangle nativeRectangle = gRectangle( \
        (int)managedRectangle->X, \
        (int)managedRectangle->Y, \
        (int)managedRectangle->Width, \
        (int)managedRectangle->Height \
    ); \
    \
    return nativeRectangle;
#endif // !CCI_GET_RECTANGLE_CPP

#ifndef CCI_SET_RECTANGLE_CPP
#define CCI_SET_RECTANGLE_CPP(host, object, target, rectangle) \
    host* _host = static_cast<host*>(object); \
    \
    if (_host->isNull()) \
    { \
        throw gcnew NullReferenceException(""); \
    } \
    \
    const gRectangle nativeRectangle = rectangle; \
    \
    Drawing::Rectangle managedRectangle = Drawing::Rectangle::FromArgb( \
        nativeRectangle.getX     (), \
        nativeRectangle.getY     (), \
        nativeRectangle.getWidth (), \
        nativeRectangle.getHeight() \
    ); \
    \
    _host->invoke()->target = managedRectangle;
#endif // !CCI_SET_RECTANGLE_CPP

#endif // __cplusplus

#endif // !GWC_MACROS_HPP
