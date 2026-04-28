//
// :.:.:.:.:.
// GWC.Native
// v0.3.3
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// RECTANGLE.h
//  Licenza MIT
//

#pragma once

#ifndef GWC_RECTANGLE_H
#define GWC_RECTANGLE_H

#include "header.h"

typedef struct gRECTANGLE gRECTANGLE;

GWC_C_API gRECTANGLE* rectangle_new   (int x, int y, int width, int height);
GWC_C_API void        rectangle_delete(gRECTANGLE* rectangle);

GWC_C_API int  rectangle_getX     (const gRECTANGLE* rectangle);
GWC_C_API void rectangle_setX     (gRECTANGLE* rectangle, int value);
GWC_C_API int  rectangle_getY     (const gRECTANGLE* rectangle);
GWC_C_API void rectangle_setY     (gRECTANGLE* rectangle, int value);
GWC_C_API int  rectangle_getWidth (const gRECTANGLE* rectangle);
GWC_C_API void rectangle_setWidth (gRECTANGLE* rectangle, int value);
GWC_C_API int  rectangle_getHeight(const gRECTANGLE* rectangle);
GWC_C_API void rectangle_setHeight(gRECTANGLE* rectangle, int value);

GWC_C_API bool rectangle_equal   (const gRECTANGLE* rectangle, const gRECTANGLE* other);
GWC_C_API bool rectangle_notequal(const gRECTANGLE* rectangle, const gRECTANGLE* other);

#endif // !GWC_RECTANGLE_H
