//
// :.:.:.:.:.
// GWC.Native
// v0.3.3
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
#define CCI_GET_COLOR_C(host, object, target) \
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
    Drawing::Color^ manangedColor = _host->invoke()->target; \
    \
    gCOLOR* nativeColor = color_new( \
        (int)manangedColor->A, \
        (int)manangedColor->R, \
        (int)manangedColor->G, \
        (int)manangedColor->B \
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
    const gCOLOR* nativeColor = color; \
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



#ifndef CCI_GET_POINT_C
#define CCI_GET_POINT_C(host, object, target) \
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
    Drawing::Point^ manangedPoint = _host->invoke()->target; \
    \
    gPOINT* nativePoint = point_new( \
        (int)manangedPoint->X, \
        (int)manangedPoint->Y \
    ); \
    \
    return nativePoint;
#endif // !CCI_GET_POINT_C

#ifndef CCI_SET_POINT_C
#define CCI_SET_POINT_C(host, object, target, point) \
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
    const gPOINT* nativePoint = point; \
    \
    Drawing::Point^ managedColor = gcnew Drawing::Point( \
        point_getX(nativePoint), \
        point_getY(nativePoint) \
    ); \
    \
    _host->invoke()->target = managedColor;
#endif // !CCI_SET_POINT_C



#ifndef CCI_GET_SIZE_C
#define CCI_GET_SIZE_C(host, object, target) \
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
    Drawing::Size^ manangedSize = _host->invoke()->target; \
    \
    gSIZE* nativeSize = size_new( \
        (int)manangedSize->Width, \
        (int)manangedSize->Height \
    ); \
    \
    return nativeSize;
#endif // !CCI_GET_SIZE_C

#ifndef CCI_SET_SIZE_C
#define CCI_SET_SIZE_C(host, object, target, size) \
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
    const gSIZE* nativeSize = size; \
    \
    Drawing::Size^ managedColor = gcnew Drawing::Size( \
        size_getWidth (nativeSize), \
        size_getHeight(nativeSize) \
    ); \
    \
    _host->invoke()->target = managedColor;
#endif // !CCI_SET_SIZE_C



#ifndef CCI_GET_RECTANGLE_C
#define CCI_GET_RECTANGLE_C(host, object, target) \
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
    Drawing::Rectangle^ manangedRectangle = _host->invoke()->target; \
    \
    gRECTANGLE* nativeRectangle = rectangle_new( \
        (int)manangedRectangle->X, \
        (int)manangedRectangle->Y, \
        (int)manangedRectangle->Width, \
        (int)manangedRectangle->Height \
    ); \
    \
    return nativeRectangle;
#endif // !CCI_GET_RECTANGLE_C

#ifndef CCI_SET_RECTANGLE_C
#define CCI_SET_RECTANGLE_C(host, object, target, rectangle) \
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
    const gRECTANGLE* nativeRectangle = rectangle; \
    \
    Drawing::Rectangle^ managedColor = gcnew Drawing::Rectangle( \
        rectangle_getX     (nativeRectangle), \
        rectangle_getY     (nativeRectangle), \
        rectangle_getWidth (nativeRectangle), \
        rectangle_getHeight(nativeRectangle) \
    ); \
    \
    _host->invoke()->target = managedColor;
#endif // !CCI_SET_RECTANGLE_C

#endif // !GWC_MACROS_H
