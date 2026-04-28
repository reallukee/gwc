//
// :.:.:.:.:.
// GWC.Native
// v0.3.3
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// CANVAS.h
//  Licenza MIT
//

#pragma once

#ifndef GWC_CANVAS_H
#define GWC_CANVAS_H

#include "header.h"

#include "types.h"

typedef struct CANVAS CANVAS;

typedef CANVAS CNV;

GWC_C_API CANVAS* canvas_new   (int width, int height);
GWC_C_API void    canvas_delete(CANVAS* canvas);

GWC_C_API bool canvas_isInitialized(const CANVAS* canvas);

GWC_C_API gCOLOR* canvas_getBorderColor(const CANVAS* canvas);
GWC_C_API void    canvas_setBorderColor(const CANVAS* canvas, const gCOLOR* color);
GWC_C_API gCOLOR* canvas_getFillColor  (const CANVAS* canvas);
GWC_C_API void    canvas_setFillColor(const CANVAS* canvas, const gCOLOR* color);

GWC_C_API gRECTANGLE* canvas_bounds  (const CANVAS* canvas);
GWC_C_API gSIZE*      canvas_size    (const CANVAS* canvas);
GWC_C_API gPOINT*     canvas_location(const CANVAS* canvas);

GWC_C_API int canvas_getWidth (const CANVAS* canvas);
GWC_C_API int canvas_getHeight(const CANVAS* canvas);

GWC_C_API bool canvas_drawBorderSquare(const CANVAS* canvas, int x, int y, int side);
GWC_C_API bool canvas_drawFillSquare  (const CANVAS* canvas, int x, int y, int side);

GWC_C_API bool canvas_drawBorderRectangle(const CANVAS* canvas, int x, int y, int width, int height);
GWC_C_API bool canvas_drawFillRectangle  (const CANVAS* canvas, int x, int y, int width, int height);

GWC_C_API bool canvas_drawBorderCircle(const CANVAS* canvas, int x, int y, int radius);
GWC_C_API bool canvas_drawFillCircle  (const CANVAS* canvas, int x, int y, int radius);

GWC_C_API bool canvas_drawBorderEllipse(const CANVAS* canvas, int x, int y, int width, int height);
GWC_C_API bool canvas_drawFillEllipse  (const CANVAS* canvas, int x, int y, int width, int height);

GWC_C_API void canvas_render(const CANVAS* canvas);

#endif // !GWC_CANVAS_H
