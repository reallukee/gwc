//
// :.:.:.:.:.
// GWC.Native
// v0.3.3
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// POINT.h
//  Licenza MIT
//

#pragma once

#ifndef GWC_POINT_H
#define GWC_POINT_H

#include "header.h"

typedef struct gPOINT gPOINT;

GWC_C_API gPOINT* point_new   (int x, int y);
GWC_C_API void    point_delete(gPOINT* point);

GWC_C_API int  point_getX(const gPOINT* point);
GWC_C_API void point_setX(gPOINT* point, int value);
GWC_C_API int  point_getY(const gPOINT* point);
GWC_C_API void point_setY(gPOINT* point, int value);

GWC_C_API bool point_equal   (const gPOINT* point, const gPOINT* other);
GWC_C_API bool point_notequal(const gPOINT* point, const gPOINT* other);

#endif // !GWC_POINT_H
