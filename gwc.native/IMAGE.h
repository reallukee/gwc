//
// :.:.:.:.:.
// GWC.Native
// v0.5.1
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
GWC_C_API gIMAGE* image_newA  (const char* path);
GWC_C_API gIMAGE* image_newW  (const wchar_t* path);
GWC_C_API void    image_delete(gIMAGE* image);

GWC_C_API bool image_load  (gIMAGE* image, const char* path);
GWC_C_API bool image_loadA (gIMAGE* image, const char* path);
GWC_C_API bool image_loadW (gIMAGE* image, const wchar_t* path);
GWC_C_API void image_unload(gIMAGE* image);

GWC_C_API bool image_isLoaded  (const gIMAGE* image);
GWC_C_API bool image_isUnloaded(const gIMAGE* image);

#endif // !GWC_IMAGE_H
