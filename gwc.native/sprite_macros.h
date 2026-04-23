//
// :.:.:.:.:.
// GWC.Native
// v0.3.2
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

#include "macros.h"

#include "COLOR.h"

#include "SpriteHost.clr.hpp"

#ifndef CC_SPRITE_VOID_C
#define CC_SPRITE_VOID_C(sprite) \
    CC_VOID_C(SpriteHost, sprite)
#endif // !CC_SPRITE_VOID_C

#ifndef CC_SPRITE_BOOL_C
#define CC_SPRITE_BOOL_C(sprite) \
    CC_BOOL_C(SpriteHost, sprite)
#endif // !CC_SPRITE_BOOL_C

#ifndef CC_SPRITE_INT_C
#define CC_SPRITE_INT_C(sprite) \
    CC_INT_C(SpriteHost, sprite)
#endif // !CC_SPRITE_INT_C



#ifndef CCI_SPRITE_VOID_C
#define CCI_SPRITE_VOID_C(sprite, target) \
    CCI_VOID_C(SpriteHost, sprite, target)
#endif // !CCI_SPRITE_VOID_C

#ifndef CCI_SPRITE_BOOL_C
#define CCI_SPRITE_BOOL_C(sprite, target) \
    CCI_BOOL_C(SpriteHost, sprite, target)
#endif // !CCI_SPRITE_BOOL_C

#ifndef CCI_SPRITE_INT_C
#define CCI_SPRITE_INT_C(sprite, target) \
    CCI_INT_C(SpriteHost, sprite, target)
#endif // !CCI_SPRITE_INT_C



#ifndef CCI_SPRITE_GET_COLOR_C
#define CCI_SPRITE_GET_COLOR_C(sprite, target) \
    CCI_GET_COLOR_C(SpriteHost, sprite, target, color)
#endif // !CCI_SPRITE_GET_COLOR_C

#ifndef CCI_SPRITE_SET_COLOR_C
#define CCI_SPRITE_SET_COLOR_C(sprite, target, color) \
    CCI_SET_COLOR_C(SpriteHost, sprite, target, color)
#endif // !CCI_SPRITE_SET_COLOR_C

#endif // !GWC_SPRITE_MACROS_H
