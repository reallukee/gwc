//
// :.:.:.:.:.:.:.:
// GWC.Native.Abst
// v0.5.0
// :.:.:.:.:.:.:.:
//
// https://github.com/reallukee/gwc
//
// WNDMGR.h
//  Licenza MIT
//

#pragma once

#ifndef GWC_ABST_WNDMGR_H
#define GWC_ABST_WNDMGR_H

#include "header.h"

#include <types.h>

GWC_ABST_C_API void wndmgr_init    ();
GWC_ABST_C_API void wndmgr_shutdown();

GWC_ABST_C_API bool wndmgr_setCurrent(int id);
GWC_ABST_C_API int  wndmgr_getCurrent();

GWC_ABST_C_API int  wndmgr_alloc(int width, int height, bool select);
GWC_ABST_C_API void wndmgr_free ();

GWC_ABST_C_API bool wndmgr_isInitialized();

GWC_ABST_C_API bool wndmgr_open ();
GWC_ABST_C_API bool wndmgr_close();

GWC_ABST_C_API bool wndmgr_isOpen ();
GWC_ABST_C_API bool wndmgr_isClose();

GWC_ABST_C_API void wndmgr_wait(int milliseconds);

#endif // !GWC_ABST_WNDMGR_H
