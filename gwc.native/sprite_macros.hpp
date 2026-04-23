//
// :.:.:.:.:.
// GWC.Native
// v0.3.2
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

#include "macros.hpp"

#include "Color.hpp"

#include "SpriteHost.clr.hpp"

#ifndef CC_SPRITE_VOID_CPP
#define CC_SPRITE_VOID_CPP(sprite) \
    CC_VOID_CPP(SpriteHost, sprite)
#endif // !CC_SPRITE_VOID_CPP

#ifndef CC_SPRITE_BOOL_CPP
#define CC_SPRITE_BOOL_CPP(sprite) \
    CC_BOOL_CPP(SpriteHost, sprite)
#endif // !CC_SPRITE_BOOL_CPP

#ifndef CC_SPRITE_INT_CPP
#define CC_SPRITE_INT_CPP(sprite) \
    CC_INT_CPP(SpriteHost, sprite)
#endif // !CC_SPRITE_INT_CPP



#ifndef CCI_SPRITE_VOID_CPP
#define CCI_SPRITE_VOID_CPP(sprite, target) \
    CCI_VOID_CPP(SpriteHost, sprite, target)
#endif // !CCI_SPRITE_VOID_CPP

#ifndef CCI_SPRITE_BOOL_CPP
#define CCI_SPRITE_BOOL_CPP(sprite, target) \
    CCI_BOOL_CPP(SpriteHost, sprite, target)
#endif // !CCI_SPRITE_BOOL_CPP

#ifndef CCI_SPRITE_INT_CPP
#define CCI_SPRITE_INT_CPP(sprite, target) \
    CCI_INT_CPP(SpriteHost, sprite, target)
#endif // !CCI_SPRITE_INT_CPP



#ifndef CCI_SPRITE_GET_COLOR_CPP
#define CCI_SPRITE_GET_COLOR_CPP(sprite, target) \
    CCI_GET_COLOR_CPP(SpriteHost, sprite, target, color)
#endif // !CCI_SPRITE_GET_COLOR_CPP

#ifndef CCI_SPRITE_SET_COLOR_CPP
#define CCI_SPRITE_SET_COLOR_CPP(sprite, target, color) \
    CCI_SET_COLOR_CPP(SpriteHost, sprite, target, color)
#endif // !CCI_SPRITE_SET_COLOR_CPP

#endif // __cplusplus

#endif // !GWC_SPRITE_MACROS_HPP
