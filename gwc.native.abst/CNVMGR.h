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
 * Nome file : CNVMGR.h
 *
 * Titolo    : CNVMGR
 * Sommario  : CnvMgr
 *
 * Autore    : Luca Pollicino
 *             (https://github.com/reallukee)
 * Versione  : v0.6.3
 *             NOTA BENE: Campo INDICATIVO!
 * Licenza   : MIT
 */

#pragma once

#ifndef GWC_ABST_CNVMGR_H
#define GWC_ABST_CNVMGR_H

#pragma unmanaged

#include "header.h"

#include "types.h"

#include "SRIMGR.h"

GWC_ABST_C_API void cnvmgr_init    ();
GWC_ABST_C_API void cnvmgr_shutdown();

GWC_ABST_C_API bool   cnvmgr_setCurrent(CNV_ID id);
GWC_ABST_C_API CNV_ID cnvmgr_getCurrent();

GWC_ABST_C_API CNV_ID cnvmgr_alloc(int width, int height, bool select);
GWC_ABST_C_API void   cnvmgr_free ();

GWC_ABST_C_API bool cnvmgr_isInitialized();

GWC_ABST_C_API gCOLOR* cnvmgr_getBorderColor();
GWC_ABST_C_API void    cnvmgr_setBorderColor(const gCOLOR* color);
GWC_ABST_C_API gCOLOR* cnvmgr_getFillColor  ();
GWC_ABST_C_API void    cnvmgr_setFillColor  (const gCOLOR* color);
GWC_ABST_C_API gCOLOR* cnvmgr_getBackColor  ();
GWC_ABST_C_API void    cnvmgr_setBackColor  (const gCOLOR* color);

GWC_ABST_C_API gRECTANGLE* cnvmgr_bounds  ();
GWC_ABST_C_API gSIZE*      cnvmgr_size    ();
GWC_ABST_C_API gPOINT*     cnvmgr_location();

GWC_ABST_C_API int cnvmgr_getWidth ();
GWC_ABST_C_API int cnvmgr_getHeight();

GWC_ABST_C_API bool cnvmgr_clear     ();
GWC_ABST_C_API bool cnvmgr_clearArea (int x, int y, int width, int height);
GWC_ABST_C_API bool cnvmgr_clearF    ();
GWC_ABST_C_API bool cnvmgr_clearAreaF(float x, float y, float width, float height);

GWC_ABST_C_API bool cnvmgr_drawCanvas (int x, int y, CNV_ID canvasId);
GWC_ABST_C_API bool cnvmgr_drawCanvasF(float x, float y, CNV_ID canvasId);

GWC_ABST_C_API bool cnvmgr_drawSprite (int x, int y, SRI_ID spriteId);
GWC_ABST_C_API bool cnvmgr_drawSpriteF(float x, float y, const SRI_ID spriteId);

GWC_ABST_C_API bool cnvmgr_drawBorderSquare (int x, int y, int side);
GWC_ABST_C_API bool cnvmgr_drawBorderSquareF(float x, float y, float side);
GWC_ABST_C_API bool cnvmgr_drawFillSquare   (int x, int y, int side);
GWC_ABST_C_API bool cnvmgr_drawFillSquareF  (float x, float y, float side);

GWC_ABST_C_API bool cnvmgr_drawBorderRectangle (int x, int y, int width, int height);
GWC_ABST_C_API bool cnvmgr_drawBorderRectangleF(float x, float y, float width, float height);
GWC_ABST_C_API bool cnvmgr_drawFillRectangle   (int x, int y, int width, int height);
GWC_ABST_C_API bool cnvmgr_drawFillRectangleF  (float x, float y, float width, float height);

GWC_ABST_C_API bool cnvmgr_drawBorderCircle (int x, int y, int radius);
GWC_ABST_C_API bool cnvmgr_drawBorderCircleF(float x, float y, float radius);
GWC_ABST_C_API bool cnvmgr_drawFillCircle   (int x, int y, int radius);
GWC_ABST_C_API bool cnvmgr_drawFillCircleF  (float x, float y, float radius);

GWC_ABST_C_API bool cnvmgr_drawBorderEllipse (int x, int y, int width, int height);
GWC_ABST_C_API bool cnvmgr_drawBorderEllipseF(float x, float y, float width, float height);
GWC_ABST_C_API bool cnvmgr_drawFillEllipse   (int x, int y, int width, int height);
GWC_ABST_C_API bool cnvmgr_drawFillEllipseF  (float x, float y, float width, float height);

GWC_ABST_C_API bool cnvmgr_drawImage (int x, int y, gIMAGE* image);
GWC_ABST_C_API bool cnvmgr_drawImageF(float x, float y, gIMAGE* image);
GWC_ABST_C_API bool cnvmgr_drawIcon  (int x, int y, gICON* icon);
GWC_ABST_C_API bool cnvmgr_drawIconF (float x, float y, gICON* icon);

GWC_ABST_C_API void cnvmgr_render();

#endif // !GWC_ABST_CNVMGR_H
