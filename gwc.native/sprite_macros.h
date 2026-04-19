//
// :.:.:.:.:.
// GWC.Native
// v0.3.1
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// sprite_macros.h
//  Licenza MIT
//

#pragma once

#ifndef GWC_SPRITE_MACROS_H
#define GWC_SPRITE_MACROS_H

#include "COLOR.h"

#include "SpriteHost.clr.hpp"

#ifndef CC_SPRITE_VOID_C
#define CC_SPRITE_VOID_C(sprite) \
    SpriteHost* host = static_cast<SpriteHost*>(sprite->sprite); \
    \
    if (host->isNull()) \
    { \
        return; \
    }
#endif // !CC_SPRITE_VOID_C

#ifndef CC_SPRITE_BOOL_C
#define CC_SPRITE_BOOL_C(sprite) \
    SpriteHost* host = static_cast<SpriteHost*>(sprite->sprite); \
    \
    if (host->isNull()) \
    { \
        return false; \
    }
#endif // !CC_SPRITE_BOOL_C

#ifndef CC_SPRITE_INT_C
#define CC_SPRITE_INT_C(sprite) \
    SpriteHost* host = static_cast<SpriteHost*>(sprite->sprite); \
    \
    if (host->isNull()) \
    { \
        return -1; \
    }
#endif // !CC_SPRITE_INT_C



#ifndef CCI_SPRITE_VOID_C
#define CCI_SPRITE_VOID_C(sprite, target) \
    CC_SPRITE_VOID_C(sprite) \
    \
    host->invoke()->target;
#endif // !CCI_SPRITE_VOID_C

#ifndef CCI_SPRITE_BOOL_C
#define CCI_SPRITE_BOOL_C(sprite, target) \
    CC_SPRITE_BOOL_C(sprite) \
    \
    return host->invoke()->target;
#endif // !CCI_SPRITE_BOOL_C

#ifndef CCI_SPRITE_INT_C
#define CCI_SPRITE_INT_C(sprite, target) \
    CC_SPRITE_INT_C(sprite) \
    \
    return host->invoke()->target;
#endif // !CCI_SPRITE_INT_C



#ifndef CCI_SPRITE_GET_COLOR_C
#define CCI_SPRITE_GET_COLOR_C(sprite, target) \
    if (sprite == NULL) \
    { \
        return color_new(0, 0, 0, 0); \
    } \
    \
    SpriteHost* host = static_cast<SpriteHost*>(sprite->sprite); \
    \
    if (host->isNull()) \
    { \
        throw gcnew NullReferenceException(""); \
    } \
    \
    Drawing::Color^ managedBorderColor = host->invoke()->target; \
    \
    Color* nativeColor = color_new( \
        (int)managedBorderColor->A, \
        (int)managedBorderColor->R, \
        (int)managedBorderColor->G, \
        (int)managedBorderColor->B \
    ); \
    \
    return nativeColor;
#endif // !CCI_SPRITE_GET_COLOR_C

#ifndef CCI_SPRITE_SET_COLOR_C
#define CCI_SPRITE_SET_COLOR_C(sprite, target, color) \
    if (sprite == NULL || color == NULL) \
    { \
        return; \
    } \
    \
    SpriteHost* host = static_cast<SpriteHost*>(sprite->sprite); \
    \
    if (host->isNull()) \
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
    host->invoke()->target = managedColor;
#endif // !CCI_SPRITE_SET_COLOR_C

#endif // !GWC_SPRITE_MACROS_H
