//
// :.:.:.:.:.
// GWC.Native
// v0.3.3
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
    CCI_GET_COLOR_CPP(SpriteHost, sprite, target)
#endif // !CCI_SPRITE_GET_COLOR_CPP

#ifndef CCI_SPRITE_SET_COLOR_CPP
#define CCI_SPRITE_SET_COLOR_CPP(sprite, target, color) \
    CCI_SET_COLOR_CPP(SpriteHost, sprite, target, color)
#endif // !CCI_SPRITE_SET_COLOR_CPP



#ifndef CCI_SPRITE_GET_POINT_CPP
#define CCI_SPRITE_GET_POINT_CPP(sprite, target) \
    CCI_GET_POINT_CPP(SpriteHost, sprite, target)
#endif // !CCI_SPRITE_GET_POINT_CPP

#ifndef CCI_SPRITE_SET_POINT_CPP
#define CCI_SPRITE_SET_POINT_CPP(sprite, target, point) \
    CCI_SET_POINT_CPP(SpriteHost, sprite, target, point)
#endif // !CCI_SPRITE_SET_POINT_CPP



#ifndef CCI_SPRITE_GET_SIZE_CPP
#define CCI_SPRITE_GET_SIZE_CPP(sprite, target) \
    CCI_GET_SIZE_CPP(SpriteHost, sprite, target)
#endif // !CCI_SPRITE_GET_SIZE_CPP

#ifndef CCI_SPRITE_SET_SIZE_CPP
#define CCI_SPRITE_SET_SIZE_CPP(sprite, target, size) \
    CCI_SET_SIZE_CPP(SpriteHost, sprite, target, size)
#endif // !CCI_SPRITE_SET_SIZE_CPP



#ifndef CCI_SPRITE_GET_RECTANGLE_CPP
#define CCI_SPRITE_GET_RECTANGLE_CPP(sprite, target) \
    CCI_GET_RECTANGLE_CPP(SpriteHost, sprite, target)
#endif // !CCI_SPRITE_GET_RECTANGLE_CPP

#ifndef CCI_SPRITE_SET_RECTANGLE_CPP
#define CCI_SPRITE_SET_RECTANGLE_CPP(sprite, target, rectangle) \
    CCI_SET_RECTANGLE_CPP(SpriteHost, sprite, target, rectangle)
#endif // !CCI_SPRITE_SET_RECTANGLE_CPP

#endif // __cplusplus

#endif // !GWC_SPRITE_MACROS_HPP
