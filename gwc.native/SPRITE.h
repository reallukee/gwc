/*
 * :.:.:.:.:.:.:.:.
 * GWC
 * Graphical Window
 * for Console Apps
 * :.:.:.:.:.:.:.:.
 *
 * GWC Native
 *
 * A Graphics Library
 *
 * https://github.com/reallukee/gwc
 *
 * Nome file : SPRITE.h
 *
 * Titolo    : SPRITE
 * Sommario  : Sprite
 *
 * Autore    : Luca Pollicino
 *             (https://github.com/reallukee)
 * Versione  : v0.6.3
 *             NOTA BENE: Campo INDICATIVO!
 * Licenza   : MIT
 */

#pragma once

#ifndef GWC_SPRITE_H
#define GWC_SPRITE_H

#include "types.h"

typedef struct SPRITE SPRITE;
typedef struct CANVAS CANVAS;

typedef SPRITE SRI;

GWC_C_API SPRITE* sprite_new   (int width, int height);
GWC_C_API void    sprite_delete(SPRITE* sprite);

GWC_C_API bool sprite_isInitialized(const SPRITE* sprite);

GWC_C_API gCOLOR* sprite_getBorderColor(const SPRITE* sprite);
GWC_C_API void    sprite_setBorderColor(const SPRITE* sprite, const gCOLOR* color);
GWC_C_API gCOLOR* sprite_getFillColor  (const SPRITE* sprite);
GWC_C_API void    sprite_setFillColor  (const SPRITE* sprite, const gCOLOR* color);
GWC_C_API gCOLOR* sprite_getBackColor  (const SPRITE* sprite);
GWC_C_API void    sprite_setBackColor  (const SPRITE* sprite, const gCOLOR* color);

GWC_C_API gRECTANGLE* sprite_bounds  (const SPRITE* sprite);
GWC_C_API gSIZE*      sprite_size    (const SPRITE* sprite);
GWC_C_API gPOINT*     sprite_location(const SPRITE* sprite);

GWC_C_API int sprite_getWidth (const SPRITE* sprite);
GWC_C_API int sprite_getHeight(const SPRITE* sprite);

GWC_C_API bool sprite_clear     (const SPRITE* sprite);
GWC_C_API bool sprite_clearArea (const SPRITE* sprite, int x, int y, int width, int height);
GWC_C_API bool sprite_clearF    (const SPRITE* sprite);
GWC_C_API bool sprite_clearAreaF(const SPRITE* sprite, float x, float y, float width, float height);

GWC_C_API bool sprite_drawCanvas (const SPRITE* sprite, int x, int y, const CANVAS* canvas);
GWC_C_API bool sprite_drawCanvasF(const SPRITE* sprite, float x, float y, const CANVAS* canvas);

GWC_C_API bool sprite_drawSprite (const SPRITE* sprite, int x, int y, const SPRITE* sprite_);
GWC_C_API bool sprite_drawSpriteF(const SPRITE* sprite, float x, float y, const SPRITE* sprite_);

GWC_C_API bool sprite_drawBorderSquare (const SPRITE* sprite, int x, int y, int side);
GWC_C_API bool sprite_drawBorderSquareF(const SPRITE* sprite, float x, float y, float side);
GWC_C_API bool sprite_drawFillSquare   (const SPRITE* sprite, int x, int y, int side);
GWC_C_API bool sprite_drawFillSquareF  (const SPRITE* sprite, float x, float y, float side);

GWC_C_API bool sprite_drawBorderRectangle (const SPRITE* sprite, int x, int y, int width, int height);
GWC_C_API bool sprite_drawBorderRectangleF(const SPRITE* sprite, float x, float y, float width, float height);
GWC_C_API bool sprite_drawFillRectangle   (const SPRITE* sprite, int x, int y, int width, int height);
GWC_C_API bool sprite_drawFillRectangleF  (const SPRITE* sprite, float x, float y, float width, float height);

GWC_C_API bool sprite_drawBorderCircle (const SPRITE* sprite, int x, int y, int radius);
GWC_C_API bool sprite_drawBorderCircleF(const SPRITE* sprite, float x, float y, float radius);
GWC_C_API bool sprite_drawFillCircle   (const SPRITE* sprite, int x, int y, int radius);
GWC_C_API bool sprite_drawFillCircleF  (const SPRITE* sprite, float x, float y, float radius);

GWC_C_API bool sprite_drawBorderEllipse (const SPRITE* sprite, int x, int y, int width, int height);
GWC_C_API bool sprite_drawBorderEllipseF(const SPRITE* sprite, float x, float y, float width, float height);
GWC_C_API bool sprite_drawFillEllipse   (const SPRITE* sprite, int x, int y, int width, int height);
GWC_C_API bool sprite_drawFillEllipseF  (const SPRITE* sprite, float x, float y, float width, float height);

GWC_C_API bool sprite_drawImage (const SPRITE* sprite, int x, int y, gIMAGE* image);
GWC_C_API bool sprite_drawImageF(const SPRITE* sprite, float x, float y, gIMAGE* image);
GWC_C_API bool sprite_drawIcon  (const SPRITE* sprite, int x, int y, gICON* icon);
GWC_C_API bool sprite_drawIconF (const SPRITE* sprite, float x, float y, gICON* icon);

GWC_C_API void sprite_render(const SPRITE* sprite);

#endif // !GWC_SPRITE_H
