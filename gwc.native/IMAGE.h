//
// :.:.:.:.:.
// GWC.Native
// v0.5.0
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// IMAGE.h
//  Licenza MIT
//

#pragma once

#ifndef GWC_IMAGE_H
#define GWC_IMAGE_H

#include "header.h"

typedef struct gIMAGE gIMAGE;

GWC_C_API gIMAGE* image_new   (const char* path);
GWC_C_API void    image_delete(gIMAGE* image);

GWC_C_API bool    image_isLoaded(const gIMAGE* image);
GWC_C_API void    image_release (const gIMAGE* image);
GWC_C_API HBITMAP image_get     (const gIMAGE* image);

#endif // !GWC_IMAGE_H
