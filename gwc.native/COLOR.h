//
// :.:.:.:.:.
// GWC.Native
// v0.2.0
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

typedef struct Color Color;

GWC_C_API Color* color_new   (int alpha, int red, int green, int blue);
GWC_C_API void   color_delete(Color* color);

GWC_C_API int  color_getAlpha(const Color* color);
GWC_C_API void color_setAlpha(Color* color, int value);
GWC_C_API int  color_getRed  (const Color* color);
GWC_C_API void color_setRed  (Color* color, int value);
GWC_C_API int  color_getGreen(const Color* color);
GWC_C_API void color_setGreen(Color* color, int value);
GWC_C_API int  color_getBlue (const Color* color);
GWC_C_API void color_setBlue (Color* color, int value);

GWC_C_API bool color_equal   (const Color* color, const Color* other);
GWC_C_API bool color_notequal(const Color* color, const Color* other);

#endif // !GWC_COLOR_H
