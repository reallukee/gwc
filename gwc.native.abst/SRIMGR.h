//
// :.:.:.:.:.:.:.:
// GWC.Native.Abst
// v0.5.0
// :.:.:.:.:.:.:.:
//
// https://github.com/reallukee/gwc
//
// SRIMGR.h
//  Licenza MIT
//

#pragma once

#ifndef GWC_ABST_SRIMGR_H
#define GWC_ABST_SRIMGR_H

#pragma unmanaged

#include "header.h"

#include <types.h>

typedef int SRI_ID;

typedef SRI_ID SPRITE_ID;

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

GWC_ABST_C_API gRECTANGLE* srimgr_bounds  ();
GWC_ABST_C_API gSIZE*      srimgr_size    ();
GWC_ABST_C_API gPOINT*     srimgr_location();

GWC_ABST_C_API int srimgr_getWidth ();
GWC_ABST_C_API int srimgr_getHeight();

GWC_ABST_C_API bool srimgr_drawBorderSquare(int x, int y, int side);
GWC_ABST_C_API bool srimgr_drawFillSquare  (int x, int y, int side);

GWC_ABST_C_API bool srimgr_drawBorderRectangle(int x, int y, int width, int height);
GWC_ABST_C_API bool srimgr_drawFillRectangle  (int x, int y, int width, int height);

GWC_ABST_C_API bool srimgr_drawBorderCircle(int x, int y, int radius);
GWC_ABST_C_API bool srimgr_drawFillCircle  (int x, int y, int radius);

GWC_ABST_C_API bool srimgr_drawBorderEllipse(int x, int y, int width, int height);
GWC_ABST_C_API bool srimgr_drawFillEllipse  (int x, int y, int width, int height);

GWC_ABST_C_API bool srimgr_drawImage(int x, int y, gIMAGE* image);
GWC_ABST_C_API bool srimgr_drawIcon (int x, int y, gICON* icon);

GWC_ABST_C_API void srimgr_render();

#endif // !GWC_ABST_SRIMGR_H
