//
// :.:.:.:.:.
// GWC.Native
// v0.3.0
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

#ifndef CC_SPRITE_VOID_C
#define CC_SPRITE_VOID_C(sprite) \
    CLRSprite nativeHandle = sprite->sprite; \
    \
    IntPtr managedHandle = IntPtr(nativeHandle); \
    \
    if (SpriteHandler::IsNull(managedHandle)) \
    { \
        return; \
    }
#endif // !CC_SPRITE_VOID_C

#ifndef CC_SPRITE_BOOL_C
#define CC_SPRITE_BOOL_C(sprite) \
    CLRSprite nativeHandle = sprite->sprite; \
    \
    IntPtr managedHandle = IntPtr(nativeHandle); \
    \
    if (SpriteHandler::IsNull(managedHandle)) \
    { \
        return false; \
    }
#endif // !CC_SPRITE_BOOL_C

#ifndef CC_SPRITE_INT_C
#define CC_SPRITE_INT_C(sprite) \
    CLRSprite nativeHandle = sprite->sprite; \
    \
    IntPtr managedHandle = IntPtr(nativeHandle); \
    \
    if (SpriteHandler::IsNull(managedHandle)) \
    { \
        return -1; \
    }
#endif // !CC_SPRITE_INT_C



#ifndef CCI_SPRITE_VOID_C
#define CCI_SPRITE_VOID_C(sprite, target) \
    CC_SPRITE_VOID_C(sprite) \
    \
    SpriteHandler::Invoke(managedHandle)->target;
#endif // !CCI_SPRITE_VOID_C

#ifndef CCI_SPRITE_BOOL_C
#define CCI_SPRITE_BOOL_C(sprite, target) \
    CC_SPRITE_BOOL_C(sprite) \
    \
    return SpriteHandler::Invoke(managedHandle)->target;
#endif // !CCI_SPRITE_BOOL_C

#ifndef CCI_SPRITE_INT_C
#define CCI_SPRITE_INT_C(sprite, target) \
    CC_SPRITE_INT_C(sprite) \
    \
    return SpriteHandler::Invoke(managedHandle)->target;
#endif // !CCI_SPRITE_INT_C



#ifndef CCI_SPRITE_GET_COLOR_C
#define CCI_SPRITE_GET_COLOR_C(sprite, target) \
    if (sprite == NULL) \
    { \
        return color_new(0, 0, 0, 0); \
    } \
    \
    CLRSprite nativeHandle = sprite->sprite; \
    \
    IntPtr managedHandle = IntPtr(nativeHandle); \
    \
    if (SpriteHandler::IsNull(managedHandle)) \
    { \
        throw gcnew NullReferenceException(""); \
    } \
    \
    Drawing::Color^ managedBorderColor = SpriteHandler::Invoke(managedHandle)->target; \
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
    CLRSprite nativeHandle = sprite->sprite; \
    \
    IntPtr managedHandle = IntPtr(nativeHandle); \
    \
    if (SpriteHandler::IsNull(managedHandle)) \
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
    SpriteHandler::Invoke(managedHandle)->BorderColor = managedColor;
#endif // !CCI_SPRITE_SET_COLOR_C

#endif // !GWC_SPRITE_MACROS_H
