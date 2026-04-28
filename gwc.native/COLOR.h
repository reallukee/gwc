//
// :.:.:.:.:.
// GWC.Native
// v0.3.3
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// COLOR.h
//  Licenza MIT
//

#pragma once

#ifndef GWC_COLOR_H
#define GWC_COLOR_H

#include "header.h"

typedef struct gCOLOR gCOLOR;

GWC_C_API gCOLOR* color_new   (int alpha, int red, int green, int blue);
GWC_C_API void    color_delete(gCOLOR* color);

GWC_C_API int  color_getAlpha(const gCOLOR* color);
GWC_C_API void color_setAlpha(gCOLOR* color, int value);
GWC_C_API int  color_getRed  (const gCOLOR* color);
GWC_C_API void color_setRed  (gCOLOR* color, int value);
GWC_C_API int  color_getGreen(const gCOLOR* color);
GWC_C_API void color_setGreen(gCOLOR* color, int value);
GWC_C_API int  color_getBlue (const gCOLOR* color);
GWC_C_API void color_setBlue (gCOLOR* color, int value);

GWC_C_API bool color_equal   (const gCOLOR* color, const gCOLOR* other);
GWC_C_API bool color_notequal(const gCOLOR* color, const gCOLOR* other);

#endif // !GWC_COLOR_H
