//
// :.:.:.:.:.
// GWC.Native
// v0.3.3
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// SIZE.h
//  Licenza MIT
//

#pragma once

#ifndef GWC_SIZE_H
#define GWC_SIZE_H

#include "header.h"

typedef struct gSIZE gSIZE;

GWC_C_API gSIZE* size_new   (int width, int height);
GWC_C_API void   size_delete(gSIZE* size);

GWC_C_API int  size_getWidth (const gSIZE* size);
GWC_C_API void size_setWidth (gSIZE* size, int value);
GWC_C_API int  size_getHeight(const gSIZE* size);
GWC_C_API void size_setHeight(gSIZE* size, int value);

GWC_C_API bool size_equal   (const gSIZE* size, const gSIZE* other);
GWC_C_API bool size_notequal(const gSIZE* size, const gSIZE* other);

#endif // !GWC_SIZE_H
