//
// :.:.:.:.:.
// GWC.Native
// v0.3.0
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// sprite_macros.hpp
//  Licenza MIT
//

#pragma once

#ifndef GWC_SPRITE_MACROS_HPP
#define GWC_SPRITE_MACROS_HPP

#ifdef __cplusplus

#include "Color.hpp"

#ifndef CC_SPRITE_VOID_CPP
#define CC_SPRITE_VOID_CPP(sprite) \
    CLRSprite nativeHandle = sprite; \
    \
    IntPtr managedHandle = IntPtr(nativeHandle); \
    \
    if (SpriteHandler::IsNull(managedHandle)) \
    { \
        return; \
    }
#endif // !CC_SPRITE_VOID_CPP

#ifndef CC_SPRITE_BOOL_CPP
#define CC_SPRITE_BOOL_CPP(sprite) \
    CLRSprite nativeHandle = sprite; \
    \
    IntPtr managedHandle = IntPtr(nativeHandle); \
    \
    if (SpriteHandler::IsNull(managedHandle)) \
    { \
        return false; \
    }
#endif // !CC_SPRITE_BOOL_CPP

#ifndef CC_SPRITE_INT_CPP
#define CC_SPRITE_INT_CPP(sprite) \
    CLRSprite nativeHandle = sprite; \
    \
    IntPtr managedHandle = IntPtr(nativeHandle); \
    \
    if (SpriteHandler::IsNull(managedHandle)) \
    { \
        return -1; \
    }
#endif // !CC_SPRITE_INT_CPP



#ifndef CCI_SPRITE_VOID_CPP
#define CCI_SPRITE_VOID_CPP(sprite, target) \
    CC_SPRITE_VOID_CPP(sprite) \
    \
    SpriteHandler::Invoke(managedHandle)->target;
#endif // !CCI_SPRITE_VOID_CPP

#ifndef CCI_SPRITE_BOOL_CPP
#define CCI_SPRITE_BOOL_CPP(sprite, target) \
    CC_SPRITE_BOOL_CPP(sprite) \
    \
    return SpriteHandler::Invoke(managedHandle)->target;
#endif // !CCI_SPRITE_BOOL_CPP

#ifndef CCI_SPRITE_INT_CPP
#define CCI_SPRITE_INT_CPP(sprite, target) \
    CC_SPRITE_INT_CPP(sprite) \
    \
    return SpriteHandler::Invoke(managedHandle)->target;
#endif // !CCI_SPRITE_INT_CPP



#ifndef CCI_SPRITE_GET_COLOR_CPP
#define CCI_SPRITE_GET_COLOR_CPP(sprite, target) \
    CLRSprite nativeHandle = sprite; \
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
    Color nativeColor = Color( \
        (int)managedBorderColor->A, \
        (int)managedBorderColor->R, \
        (int)managedBorderColor->G, \
        (int)managedBorderColor->B \
    ); \
    \
    return nativeColor;
#endif // !CCI_SPRITE_GET_COLOR_CPP

#ifndef CCI_SPRITE_SET_COLOR_CPP
#define CCI_SPRITE_SET_COLOR_CPP(sprite, target, color) \
    CLRSprite nativeHandle = sprite; \
    \
    IntPtr managedHandle = IntPtr(nativeHandle); \
    \
    if (SpriteHandler::IsNull(managedHandle)) \
    { \
        throw gcnew NullReferenceException(""); \
    } \
    \
    Color nativeColor = color; \
    \
    Drawing::Color managedColor = Drawing::Color::FromArgb( \
        nativeColor.getAlpha(), \
        nativeColor.getRed(), \
        nativeColor.getGreen(), \
        nativeColor.getBlue() \
    ); \
    \
    SpriteHandler::Invoke(managedHandle)->BorderColor = managedColor;
#endif // !CCI_SPRITE_SET_COLOR_CPP

#endif // __cplusplus

#endif // !GWC_SPRITE_MACROS_HPP
