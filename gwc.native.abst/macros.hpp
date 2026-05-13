//
// :.:.:.:.:.:.:.:
// GWC.Native.Abst
// v0.5.0
// :.:.:.:.:.:.:.:
//
// https://github.com/reallukee/gwc
//
// macros.hpp
//  Licenza MIT
//

#pragma once

#ifndef GWC_ABST_MACROS_HPP
#define GWC_ABST_MACROS_HPP

#include <types.hpp>

using namespace gwc;

#ifdef __cplusplus

#define ITEM items[currentItem]

const int NO_ITEM = -1;

#ifndef CC_VOID_CPP
#define CC_VOID_CPP \
    if (!ready || currentItem == NO_ITEM || ITEM == nullptr) \
    { \
        return; \
    }
#endif // !CC_VOID_CPP

#ifndef CC_BOOL_CPP
#define CC_BOOL_CPP \
    if (!ready || currentItem == NO_ITEM || ITEM == nullptr) \
    { \
        return false; \
    }
#endif // !CC_BOOL_CPP

#ifndef CC_INT_CPP
#define CC_INT_CPP \
    if (!ready || currentItem == NO_ITEM || ITEM == nullptr) \
    { \
        return -1; \
    }
#endif // !CC_INT_CPP



#ifndef CCI_VOID_CPP
#define CCI_VOID_CPP(target) \
    CC_VOID_CPP \
    \
    ITEM->target;
#endif // !CCI_VOID_CPP

#ifndef CCI_BOOL_CPP
#define CCI_BOOL_CPP(target) \
    CC_BOOL_CPP \
    \
    return ITEM->target;
#endif // !CCI_BOOL_CPP

#ifndef CCI_INT_CPP
#define CCI_INT_CPP(target) \
    CC_INT_CPP \
    \
    return ITEM->target;
#endif // !CCI_INT_CPP



#ifndef CCI_GET_COLOR_CPP
#define CCI_GET_COLOR_CPP(target) \
    if (!ready || currentItem == NO_ITEM || ITEM == nullptr) \
    { \
        return gColor(); \
    } \
    \
    return ITEM->target;
#endif // !CCI_GET_COLOR_CPP

#ifndef CCI_SET_COLOR_CPP
#define CCI_SET_COLOR_CPP(target) \
    if (!ready || currentItem == NO_ITEM || ITEM == nullptr) \
    { \
        return; \
    } \
    \
    ITEM->target;
#endif // !CCI_SET_COLOR_CPP



#ifndef CCI_GET_POINT_CPP
#define CCI_GET_POINT_CPP(target) \
    if (!ready || currentItem == NO_ITEM || ITEM == nullptr) \
    { \
        return gPoint(); \
    } \
    \
    return ITEM->target;
#endif // !CCI_GET_POINT_CPP

#ifndef CCI_SET_POINT_CPP
#define CCI_SET_POINT_CPP(target) \
    if (!ready || currentItem == NO_ITEM || ITEM == nullptr) \
    { \
        return; \
    } \
    \
    ITEM->target;
#endif // !CCI_SET_POINT_CPP



#ifndef CCI_GET_SIZE_CPP
#define CCI_GET_SIZE_CPP(target) \
    if (!ready || currentItem == NO_ITEM || ITEM == nullptr) \
    { \
        return gSize(); \
    } \
    \
    return ITEM->target;
#endif // !CCI_GET_SIZE_CPP

#ifndef CCI_SET_SIZE_CPP
#define CCI_SET_SIZE_CPP(target) \
    if (!ready || currentItem == NO_ITEM || ITEM == nullptr) \
    { \
        return; \
    } \
    \
    ITEM->target;
#endif // !CCI_SET_SIZE_CPP



#ifndef CCI_GET_RECTANGLE_CPP
#define CCI_GET_RECTANGLE_CPP(target) \
    if (!ready || currentItem == NO_ITEM || ITEM == nullptr) \
    { \
        return gRectangle(); \
    } \
    \
    return ITEM->target;
#endif // !CCI_GET_RECTANGLE_CPP

#ifndef CCI_SET_RECTANGLE_CPP
#define CCI_SET_RECTANGLE_CPP(target) \
    if (!ready || currentItem == NO_ITEM || ITEM == nullptr) \
    { \
        return; \
    } \
    \
    ITEM->target;
#endif // !CCI_SET_RECTANGLE_CPP

#endif // __cplusplus

#endif // !GWC_ABST_MACROS_HPP
