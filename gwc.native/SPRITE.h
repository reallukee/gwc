//
// :.:.:.:.:.
// GWC.Native
// v0.3.1
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// SPRITE.h
//  Licenza MIT
//

#pragma once

#ifndef GWC_SPRITE_H
#define GWC_SPRITE_H

#include "header.h"
#include "types.h"
#include "COLOR.h"

typedef struct SPRITE SPRITE;

typedef SPRITE SRI;

GWC_C_API SPRITE* sprite_new   (int width, int height);
GWC_C_API void    sprite_delete(SPRITE* sprite);

GWC_C_API bool sprite_isInitialized(const SPRITE* sprite);

GWC_C_API Color* sprite_getBorderColor(const SPRITE* sprite);
GWC_C_API void   sprite_setBorderColor(const SPRITE* sprite, const Color* color);
GWC_C_API Color* sprite_getFillColor  (const SPRITE* sprite);
GWC_C_API void   sprite_setFillColor  (const SPRITE* sprite, const Color* color);

GWC_C_API int sprite_getWidth (const SPRITE* sprite);
GWC_C_API int sprite_getHeight(const SPRITE* sprite);

GWC_C_API bool sprite_drawBorderSquare(const SPRITE* sprite, int x, int y, int side);
GWC_C_API bool sprite_drawFillSquare  (const SPRITE* sprite, int x, int y, int side);

GWC_C_API bool sprite_drawBorderRectangle(const SPRITE* sprite, int x, int y, int width, int height);
GWC_C_API bool sprite_drawFillRectangle  (const SPRITE* sprite, int x, int y, int width, int height);

GWC_C_API bool sprite_drawBorderCircle(const SPRITE* sprite, int x, int y, int radius);
GWC_C_API bool sprite_drawFillCircle  (const SPRITE* sprite, int x, int y, int radius);

GWC_C_API bool sprite_drawBorderEllipse(const SPRITE* sprite, int x, int y, int width, int height);
GWC_C_API bool sprite_drawFillEllipse  (const SPRITE* sprite, int x, int y, int width, int height);

GWC_C_API void sprite_render(const SPRITE* sprite);

#endif // !GWC_SPRITE_H
