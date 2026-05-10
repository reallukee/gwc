//
// :.:.:.:.:.
// GWC.Native
// v0.5.0
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// ICON.h
//  Licenza MIT
//

#pragma once

#ifndef GWC_ICON_H
#define GWC_ICON_H

#include "header.h"

typedef struct gICON gICON;

GWC_C_API gICON* icon_new   (const char* path);
GWC_C_API void   icon_delete(gICON* icon);

GWC_C_API bool  icon_isLoaded(const gICON* icon);
GWC_C_API void  icon_release (const gICON* icon);
GWC_C_API HICON icon_get     (const gICON* icon);

#endif // !GWC_ICON_H
