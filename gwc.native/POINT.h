//
// :.:.:.:.:.
// GWC.Native
// v0.2.0
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

typedef struct Point Point;

GWC_C_API Point* point_new   (int x, int y);
GWC_C_API void   point_delete(Point* Point);

GWC_C_API int  point_getX(const Point* point);
GWC_C_API void point_setX(Point* point, int value);
GWC_C_API int  point_getY(const Point* point);
GWC_C_API void point_setY(Point* point, int value);

GWC_C_API bool point_equal   (const Point* point, const Point* other);
GWC_C_API bool point_notequal(const Point* point, const Point* other);

#endif // !GWC_POINT_H
