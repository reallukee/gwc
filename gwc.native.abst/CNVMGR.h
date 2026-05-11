//
// :.:.:.:.:.:.:.:
// GWC.Native.Abst
// v0.5.0
// :.:.:.:.:.:.:.:
//
// https://github.com/reallukee/gwc
//
// CNVMGR.h
//  Licenza MIT
//

#pragma once

#ifndef GWC_ABST_CNVMGR_H
#define GWC_ABST_CNVMGR_H

#include "header.h"

#include <types.h>

GWC_ABST_C_API void cnvmgr_init    ();
GWC_ABST_C_API void cnvmgr_shutdown();

GWC_ABST_C_API bool cnvmgr_setCurrent(int id);
GWC_ABST_C_API int  cnvmgr_getCurrent();

GWC_ABST_C_API int  cnvmgr_alloc(int width, int height, bool select);
GWC_ABST_C_API void cnvmgr_free ();

GWC_ABST_C_API bool cnvmgr_isInitialized();

#endif // !GWC_ABST_CNVMGR_H
