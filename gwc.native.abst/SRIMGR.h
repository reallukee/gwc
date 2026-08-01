/*
 * :.:.:.:.:.:.:.:.
 * GWC
 * Graphical Window
 * for Console Apps
 * :.:.:.:.:.:.:.:.
 *
 * GWC Native Abst
 *
 * A Graphics Library
 *
 * https://github.com/reallukee/gwc
 *
 * Nome file : SRIMGR.h
 *
 * Titolo    : SRIMGR
 * Sommario  : SriMgr
 *
 * Autore    : Luca Pollicino
 *             (https://github.com/reallukee)
 * Versione  : v0.6.3
 *             NOTA BENE: Campo INDICATIVO!
 * Licenza   : MIT
 */

#pragma once

#ifndef GWC_ABST_SRIMGR_H
#define GWC_ABST_SRIMGR_H

#pragma unmanaged

#include "header.h"

#include "types.h"

#include "CNVMGR.h"

GWC_ABST_C_API void srimgr_init    ();
GWC_ABST_C_API void srimgr_shutdown();

GWC_ABST_C_API bool   srimgr_setCurrent(SRI_ID id);
GWC_ABST_C_API SRI_ID srimgr_getCurrent();

GWC_ABST_C_API SRI_ID srimgr_alloc(int width, int height, bool select);
GWC_ABST_C_API void   srimgr_free ();

GWC_ABST_C_API bool srimgr_isInitialized();

GWC_ABST_C_API gCOLOR* srimgr_getBorderColor();
GWC_ABST_C_API void    srimgr_setBorderColor(const gCOLOR* color);
GWC_ABST_C_API gCOLOR* srimgr_getFillColor  ();
GWC_ABST_C_API void    srimgr_setFillColor  (const gCOLOR* color);
GWC_ABST_C_API gCOLOR* srimgr_getBackColor  ();
GWC_ABST_C_API void    srimgr_setBackColor  (const gCOLOR* color);

GWC_ABST_C_API gRECTANGLE* srimgr_bounds  ();
GWC_ABST_C_API gSIZE*      srimgr_size    ();
GWC_ABST_C_API gPOINT*     srimgr_location();

GWC_ABST_C_API int srimgr_getWidth ();
GWC_ABST_C_API int srimgr_getHeight();

GWC_ABST_C_API bool srimgr_clear     ();
GWC_ABST_C_API bool srimgr_clearArea (int x, int y, int width, int height);
GWC_ABST_C_API bool srimgr_clearF    ();
GWC_ABST_C_API bool srimgr_clearAreaF(float x, float y, float width, float height);

GWC_ABST_C_API bool srimgr_drawCanvas (int x, int y, CNV_ID canvasId);
GWC_ABST_C_API bool srimgr_drawCanvasF(float x, float y, CNV_ID canvasId);

GWC_ABST_C_API bool srimgr_drawSprite (int x, int y, SRI_ID spriteId);
GWC_ABST_C_API bool srimgr_drawSpriteF(float x, float y, const SRI_ID spriteId);

GWC_ABST_C_API bool srimgr_drawBorderSquare (int x, int y, int side);
GWC_ABST_C_API bool srimgr_drawBorderSquareF(float x, float y, float side);
GWC_ABST_C_API bool srimgr_drawFillSquare   (int x, int y, int side);
GWC_ABST_C_API bool srimgr_drawFillSquareF  (float x, float y, float side);

GWC_ABST_C_API bool srimgr_drawBorderRectangle (int x, int y, int width, int height);
GWC_ABST_C_API bool srimgr_drawBorderRectangleF(float x, float y, float width, float height);
GWC_ABST_C_API bool srimgr_drawFillRectangle   (int x, int y, int width, int height);
GWC_ABST_C_API bool srimgr_drawFillRectangleF  (float x, float y, float width, float height);

GWC_ABST_C_API bool srimgr_drawBorderCircle (int x, int y, int radius);
GWC_ABST_C_API bool srimgr_drawBorderCircleF(float x, float y, float radius);
GWC_ABST_C_API bool srimgr_drawFillCircle   (int x, int y, int radius);
GWC_ABST_C_API bool srimgr_drawFillCircleF  (float x, float y, float radius);

GWC_ABST_C_API bool srimgr_drawBorderEllipse (int x, int y, int width, int height);
GWC_ABST_C_API bool srimgr_drawBorderEllipseF(float x, float y, float width, float height);
GWC_ABST_C_API bool srimgr_drawFillEllipse   (int x, int y, int width, int height);
GWC_ABST_C_API bool srimgr_drawFillEllipseF  (float x, float y, float width, float height);

GWC_ABST_C_API bool srimgr_drawImage (int x, int y, gIMAGE* image);
GWC_ABST_C_API bool srimgr_drawImageF(float x, float y, gIMAGE* image);
GWC_ABST_C_API bool srimgr_drawIcon  (int x, int y, gICON* icon);
GWC_ABST_C_API bool srimgr_drawIconF (float x, float y, gICON* icon);

GWC_ABST_C_API void srimgr_render();

#endif // !GWC_ABST_SRIMGR_H
