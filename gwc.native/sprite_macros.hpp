//
// :.:.:.:.:.
// GWC.Native
// v0.3.1
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

#include "SpriteHost.clr.hpp"

#ifndef CC_SPRITE_VOID_CPP
#define CC_SPRITE_VOID_CPP(sprite) \
    SpriteHost* host= static_cast<SpriteHost*>(sprite); \
    \
    if (host->isNull()) \
    { \
        return; \
    }
#endif // !CC_SPRITE_VOID_CPP

#ifndef CC_SPRITE_BOOL_CPP
#define CC_SPRITE_BOOL_CPP(sprite) \
    SpriteHost* host= static_cast<SpriteHost*>(sprite); \
    \
    if (host->isNull()) \
    { \
        return false; \
    }
#endif // !CC_SPRITE_BOOL_CPP

#ifndef CC_SPRITE_INT_CPP
#define CC_SPRITE_INT_CPP(sprite) \
    SpriteHost* host= static_cast<SpriteHost*>(sprite); \
    \
    if (host->isNull()) \
    { \
        return -1; \
    }
#endif // !CC_SPRITE_INT_CPP



#ifndef CCI_SPRITE_VOID_CPP
#define CCI_SPRITE_VOID_CPP(sprite, target) \
    CC_SPRITE_VOID_CPP(sprite) \
    \
    host->invoke()->target;
#endif // !CCI_SPRITE_VOID_CPP

#ifndef CCI_SPRITE_BOOL_CPP
#define CCI_SPRITE_BOOL_CPP(sprite, target) \
    CC_SPRITE_BOOL_CPP(sprite) \
    \
    return host->invoke()->target;
#endif // !CCI_SPRITE_BOOL_CPP

#ifndef CCI_SPRITE_INT_CPP
#define CCI_SPRITE_INT_CPP(sprite, target) \
    CC_SPRITE_INT_CPP(sprite) \
    \
    return host->invoke()->target;
#endif // !CCI_SPRITE_INT_CPP



#ifndef CCI_SPRITE_GET_COLOR_CPP
#define CCI_SPRITE_GET_COLOR_CPP(sprite, target) \
    SpriteHost* host = static_cast<SpriteHost*>(sprite); \
    \
    if (host->isNull()) \
    { \
        throw gcnew NullReferenceException(""); \
    } \
    \
    Drawing::Color^ managedBorderColor = host->invoke()->target; \
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
    SpriteHost* host = static_cast<SpriteHost*>(sprite); \
    \
    if (host->isNull()) \
    { \
        throw gcnew NullReferenceException(""); \
    } \
    \
    Color nativeColor = color; \
    \
    Drawing::Color managedColor = Drawing::Color::FromArgb( \
        nativeColor.getAlpha(), \
        nativeColor.getRed  (), \
        nativeColor.getGreen(), \
        nativeColor.getBlue () \
    ); \
    \
    host->invoke()->target = managedColor;
#endif // !CCI_SPRITE_SET_COLOR_CPP

#endif // __cplusplus

#endif // !GWC_SPRITE_MACROS_HPP
