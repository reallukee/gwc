//
// :.:.:.:.:.:.:.:
// GWC.Native.Abst
// v0.5.0
// :.:.:.:.:.:.:.:
//
// https://github.com/reallukee/gwc
//
// SRIMGR.h
//  Licenza MIT
//

#pragma once

#ifndef GWC_ABST_SRIMGR_H
#define GWC_ABST_SRIMGR_H

#include "header.h"

#include <types.h>

GWC_ABST_C_API void srimgr_init    ();
GWC_ABST_C_API void srimgr_shutdown();

GWC_ABST_C_API bool srimgr_setCurrent(int id);
GWC_ABST_C_API int  srimgr_getCurrent();

GWC_ABST_C_API int  srimgr_alloc(int width, int height, bool select);
GWC_ABST_C_API void srimgr_free ();

GWC_ABST_C_API bool srimgr_isInitialized();

#endif // !GWC_ABST_SRIMGR_H
