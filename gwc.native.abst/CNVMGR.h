//
// :.:.:.:.:.:.:.:
// GWC.Native.Abst
// v0.6.1
// :.:.:.:.:.:.:.:
//
// https://github.com/reallukee/gwc
//
// CNVMGR.h
//  Licenza MIT
//

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

GWC_ABST_C_API gRECTANGLE* cnvmgr_bounds  ();
GWC_ABST_C_API gSIZE*      cnvmgr_size    ();
GWC_ABST_C_API gPOINT*     cnvmgr_location();

GWC_ABST_C_API int cnvmgr_getWidth ();
GWC_ABST_C_API int cnvmgr_getHeight();

GWC_ABST_C_API bool cnvmgr_clear(const gCOLOR* color);

GWC_ABST_C_API bool cnvmgr_drawCanvas(int x, int y, CNV_ID canvasId);
GWC_ABST_C_API bool cnvmgr_drawSprite(int x, int y, SRI_ID spriteId);

GWC_ABST_C_API bool cnvmgr_drawBorderSquare(int x, int y, int side);
GWC_ABST_C_API bool cnvmgr_drawFillSquare  (int x, int y, int side);

GWC_ABST_C_API bool cnvmgr_drawBorderRectangle(int x, int y, int width, int height);
GWC_ABST_C_API bool cnvmgr_drawFillRectangle  (int x, int y, int width, int height);

GWC_ABST_C_API bool cnvmgr_drawBorderCircle(int x, int y, int radius);
GWC_ABST_C_API bool cnvmgr_drawFillCircle  (int x, int y, int radius);

GWC_ABST_C_API bool cnvmgr_drawBorderEllipse(int x, int y, int width, int height);
GWC_ABST_C_API bool cnvmgr_drawFillEllipse  (int x, int y, int width, int height);

GWC_ABST_C_API bool cnvmgr_drawImage(int x, int y, gIMAGE* image);
GWC_ABST_C_API bool cnvmgr_drawIcon (int x, int y, gICON* icon);

GWC_ABST_C_API void cnvmgr_render();

#endif // !GWC_ABST_CNVMGR_H
