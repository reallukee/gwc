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
 * Nome file : CANVAS.h
 *
 * Titolo    : CANVAS
 * Sommario  : Canvas
 *
 * Autore    : Luca Pollicino
 *             (https://github.com/reallukee)
 * Versione  : v0.6.3
 *             NOTA BENE: Campo INDICATIVO!
 * Licenza   : MIT
 */

#pragma once

#ifndef GWC_CANVAS_H
#define GWC_CANVAS_H

#include "types.h"

typedef struct CANVAS CANVAS;
typedef struct SPRITE SPRITE;

typedef CANVAS CNV;

GWC_C_API CANVAS* canvas_new   (int width, int height);
GWC_C_API void    canvas_delete(CANVAS* canvas);

GWC_C_API bool canvas_isInitialized(const CANVAS* canvas);

GWC_C_API gCOLOR* canvas_getBorderColor(const CANVAS* canvas);
GWC_C_API void    canvas_setBorderColor(const CANVAS* canvas, const gCOLOR* color);
GWC_C_API gCOLOR* canvas_getFillColor  (const CANVAS* canvas);
GWC_C_API void    canvas_setFillColor  (const CANVAS* canvas, const gCOLOR* color);
GWC_C_API gCOLOR* canvas_getBackColor  (const CANVAS* canvas);
GWC_C_API void    canvas_setBackColor  (const CANVAS* canvas, const gCOLOR* color);

GWC_C_API gRECTANGLE* canvas_bounds  (const CANVAS* canvas);
GWC_C_API gSIZE*      canvas_size    (const CANVAS* canvas);
GWC_C_API gPOINT*     canvas_location(const CANVAS* canvas);

GWC_C_API int canvas_getWidth (const CANVAS* canvas);
GWC_C_API int canvas_getHeight(const CANVAS* canvas);

GWC_C_API bool canvas_clear     (const CANVAS* canvas);
GWC_C_API bool canvas_clearArea (const CANVAS* canvas, int x, int y, int width, int height);
GWC_C_API bool canvas_clearF    (const CANVAS* canvas);
GWC_C_API bool canvas_clearAreaF(const CANVAS* canvas, float x, float y, float width, float height);

GWC_C_API bool canvas_drawCanvas (const CANVAS* canvas, int x, int y, const CANVAS* canvas_);
GWC_C_API bool canvas_drawCanvasF(const CANVAS* canvas, float x, float y, const CANVAS* canvas_);

GWC_C_API bool canvas_drawSprite (const CANVAS* canvas, int x, int y, const SPRITE* sprite);
GWC_C_API bool canvas_drawSpriteF(const CANVAS* canvas, float x, float y, const SPRITE* sprite);

GWC_C_API bool canvas_drawBorderSquare (const CANVAS* canvas, int x, int y, int side);
GWC_C_API bool canvas_drawBorderSquareF(const CANVAS* canvas, float x, float y, float side);
GWC_C_API bool canvas_drawFillSquare   (const CANVAS* canvas, int x, int y, int side);
GWC_C_API bool canvas_drawFillSquareF  (const CANVAS* canvas, float x, float y, float side);

GWC_C_API bool canvas_drawBorderRectangle (const CANVAS* canvas, int x, int y, int width, int height);
GWC_C_API bool canvas_drawBorderRectangleF(const CANVAS* canvas, float x, float y, float width, float height);
GWC_C_API bool canvas_drawFillRectangle   (const CANVAS* canvas, int x, int y, int width, int height);
GWC_C_API bool canvas_drawFillRectangleF  (const CANVAS* canvas, float x, float y, float width, float height);

GWC_C_API bool canvas_drawBorderCircle (const CANVAS* canvas, int x, int y, int radius);
GWC_C_API bool canvas_drawBorderCircleF(const CANVAS* canvas, float x, float y, float radius);
GWC_C_API bool canvas_drawFillCircle   (const CANVAS* canvas, int x, int y, int radius);
GWC_C_API bool canvas_drawFillCircleF  (const CANVAS* canvas, float x, float y, float radius);

GWC_C_API bool canvas_drawBorderEllipse (const CANVAS* canvas, int x, int y, int width, int height);
GWC_C_API bool canvas_drawBorderEllipseF(const CANVAS* canvas, float x, float y, float width, float height);
GWC_C_API bool canvas_drawFillEllipse   (const CANVAS* canvas, int x, int y, int width, int height);
GWC_C_API bool canvas_drawFillEllipseF  (const CANVAS* canvas, float x, float y, float width, float height);

GWC_C_API bool canvas_drawImage (const CANVAS* canvas, int x, int y, gIMAGE* image);
GWC_C_API bool canvas_drawImageF(const CANVAS* canvas, float x, float y, gIMAGE* image);
GWC_C_API bool canvas_drawIcon  (const CANVAS* canvas, int x, int y, gICON* icon);
GWC_C_API bool canvas_drawIconF (const CANVAS* canvas, float x, float y, gICON* icon);

GWC_C_API void canvas_render(const CANVAS* canvas);

#endif // !GWC_CANVAS_H
