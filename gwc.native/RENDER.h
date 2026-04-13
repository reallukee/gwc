//
// :.:.:.:.:.
// GWC.Native
// v0.2.0
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// RENDER.h
//  Licenza MIT
//

#pragma once

#ifndef GWC_RENDER_H
#define GWC_RENDER_H

#include "header.h"

GWC_C_API int  render_getRefreshRate       ();
GWC_C_API void render_setRefreshRate       (int value);
GWC_C_API void render_setDefaultRefreshRate();

GWC_C_API int  render_getDutyCycle       ();
GWC_C_API void render_setDutyCycle       (int value);
GWC_C_API void render_setDefaultDutyCycle();

GWC_C_API double render_getFrameTime    ();
GWC_C_API double render_getUtilFrameTime();

#endif // !GWC_RENDER_H
