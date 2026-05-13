//
// :.:.:.:.:.:.:.:
// GWC.Native.Abst
// v0.5.0
// :.:.:.:.:.:.:.:
//
// https://github.com/reallukee/gwc
//
// macros.h
//  Licenza MIT
//

#pragma once

#ifndef GWC_ABST_MACROS_H
#define GWC_ABST_MACROS_H

#include <types.h>

#define ITEM items[currentItem]

const int NO_ITEM = -1;

#ifndef CC_VOID_C
#define CC_VOID_C \
    if (!ready || currentItem == NO_ITEM || ITEM == NULL) \
    { \
        return; \
    }
#endif // !CC_VOID_C

#ifndef CC_BOOL_C
#define CC_BOOL_C \
    if (!ready || currentItem == NO_ITEM || ITEM == NULL) \
    { \
        return false; \
    }
#endif // !CC_BOOL_C

#ifndef CC_INT_C
#define CC_INT_C \
    if (!ready || currentItem == NO_ITEM || ITEM == NULL) \
    { \
        return -1; \
    }
#endif // !CC_INT_C



#ifndef CCI_VOID_C
#define CCI_VOID_C(target) \
    CC_VOID_C \
    \
    target;
#endif // !CCI_VOID_C

#ifndef CCI_BOOL_C
#define CCI_BOOL_C(target) \
    CC_BOOL_C \
    \
    return target;
#endif // !CCI_BOOL_C

#ifndef CCI_INT_C
#define CCI_INT_C(target) \
    CC_INT_C \
    \
    return target;
#endif // !CCI_INT_C



#ifndef CCI_GET_COLOR_C
#define CCI_GET_COLOR_C(target) \
    if (!ready || currentItem == NO_ITEM || ITEM == NULL) \
    { \
        return NULL; \
    } \
    \
    return target;
#endif // !CCI_GET_COLOR_C

#ifndef CCI_SET_COLOR_C
#define CCI_SET_COLOR_C(target) \
    if (!ready || currentItem == NO_ITEM || ITEM == NULL) \
    { \
        return; \
    } \
    \
    target;
#endif // !CCI_SET_COLOR_C



#ifndef CCI_GET_POINT_C
#define CCI_GET_POINT_C(target) \
    if (!ready || currentItem == NO_ITEM || ITEM == NULL) \
    { \
        return NULL; \
    } \
    \
    return target;
#endif // !CCI_GET_POINT_C

#ifndef CCI_SET_POINT_C
#define CCI_SET_POINT_C(target) \
    if (!ready || currentItem == NO_ITEM || ITEM == NULL) \
    { \
        return; \
    } \
    \
    target;
#endif // !CCI_SET_POINT_C



#ifndef CCI_GET_SIZE_C
#define CCI_GET_SIZE_C(target) \
    if (!ready || currentItem == NO_ITEM || ITEM == NULL) \
    { \
        return NULL; \
    } \
    \
    return target;
#endif // !CCI_GET_SIZE_C

#ifndef CCI_SET_SIZE_C
#define CCI_SET_SIZE_C(target) \
    if (!ready || currentItem == NO_ITEM || ITEM == NULL) \
    { \
        return; \
    } \
    \
    target;
#endif // !CCI_SET_SIZE_C



#ifndef CCI_GET_RECTANGLE_C
#define CCI_GET_RECTANGLE_C(target) \
    if (!ready || currentItem == NO_ITEM || ITEM == NULL) \
    { \
        return NULL; \
    } \
    \
    return target;
#endif // !CCI_GET_RECTANGLE_C

#ifndef CCI_SET_RECTANGLE_C
#define CCI_SET_RECTANGLE_C(target) \
    if (!ready || currentItem == NO_ITEM || ITEM == NULL) \
    { \
        return; \
    } \
    \
    target;
#endif // !CCI_SET_RECTANGLE_C

#endif // !GWC_ABST_MACROS_H
