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

#pragma unmanaged

#include "header.h"

#include <types.h>

typedef int WND_ID;

typedef WND_ID WINDOW_ID;

GWC_ABST_C_API void wndmgr_init    ();
GWC_ABST_C_API void wndmgr_shutdown();

GWC_ABST_C_API bool   wndmgr_setCurrent(WND_ID id);
GWC_ABST_C_API WND_ID wndmgr_getCurrent();

GWC_ABST_C_API WND_ID wndmgr_alloc(int width, int height, bool select);
GWC_ABST_C_API void   wndmgr_free ();

GWC_ABST_C_API bool wndmgr_isInitialized();

GWC_ABST_C_API bool wndmgr_open ();
GWC_ABST_C_API bool wndmgr_close();

GWC_ABST_C_API bool wndmgr_isOpen ();
GWC_ABST_C_API bool wndmgr_isClose();

GWC_ABST_C_API bool wndmgr_suspend();
GWC_ABST_C_API bool wndmgr_resume ();

GWC_ABST_C_API bool wndmgr_isSuspend();
GWC_ABST_C_API bool wndmgr_isResume ();

GWC_ABST_C_API void wndmgr_wait(int milliseconds);

GWC_ABST_C_API void wndmgr_skip(int frames);

GWC_ABST_C_API bool wndmgr_show();
GWC_ABST_C_API bool wndmgr_hide();

GWC_ABST_C_API int wndmgr_getWindowWidth ();
GWC_ABST_C_API int wndmgr_getWindowHeight();
GWC_ABST_C_API int wndmgr_getRenderWidth ();
GWC_ABST_C_API int wndmgr_getRenderHeight();

GWC_ABST_C_API bool wndmgr_isKeyDownAvailable ();
GWC_ABST_C_API void wndmgr_flushKeyDown       ();
GWC_ABST_C_API bool wndmgr_consumeKeyDown     (gKEYS* modifiers, gKEYS* key);
GWC_ABST_C_API bool wndmgr_discardKeyDown     ();
GWC_ABST_C_API bool wndmgr_isKeyDownLost      ();
GWC_ABST_C_API bool wndmgr_isKeyDownBufferFull();

GWC_ABST_C_API bool wndmgr_isKeyUpAvailable ();
GWC_ABST_C_API void wndmgr_flushKeyUp       ();
GWC_ABST_C_API bool wndmgr_consumeKeyUp     (gKEYS* modifiers, gKEYS* key);
GWC_ABST_C_API bool wndmgr_discardKeyUp     ();
GWC_ABST_C_API bool wndmgr_isKeyUpLost      ();
GWC_ABST_C_API bool wndmgr_isKeyUpBufferFull();

GWC_ABST_C_API bool wndmgr_isMouseDownAvailable ();
GWC_ABST_C_API void wndmgr_flushMouseDown       ();
GWC_ABST_C_API bool wndmgr_consumeMouseDown     (gPOINT** location, gMOUSEBUTTONS* button);
GWC_ABST_C_API bool wndmgr_discardMouseDown     ();
GWC_ABST_C_API bool wndmgr_isMouseDownLost      ();
GWC_ABST_C_API bool wndmgr_isMouseDownBufferFull();

GWC_ABST_C_API bool wndmgr_isMouseUpAvailable ();
GWC_ABST_C_API void wndmgr_flushMouseUp       ();
GWC_ABST_C_API bool wndmgr_consumeMouseUp     (gPOINT** location, gMOUSEBUTTONS* button);
GWC_ABST_C_API bool wndmgr_discardMouseUp     ();
GWC_ABST_C_API bool wndmgr_isMouseUpLost      ();
GWC_ABST_C_API bool wndmgr_isMouseUpBufferFull();

GWC_ABST_C_API int wndmgr_getCanvasWidth ();
GWC_ABST_C_API int wndmgr_getCanvasHeight();

GWC_ABST_C_API gCOLOR* wndmgr_getBorderColor();
GWC_ABST_C_API void    wndmgr_setBorderColor(const gCOLOR* color);
GWC_ABST_C_API gCOLOR* wndmgr_getFillColor  ();
GWC_ABST_C_API void    wndmgr_setFillColor  (const gCOLOR* color);

GWC_ABST_C_API bool wndmgr_drawBorderSquare(int x, int y, int side);
GWC_ABST_C_API bool wndmgr_drawFillSquare  (int x, int y, int side);

GWC_ABST_C_API bool wndmgr_drawBorderRectangle(int x, int y, int width, int height);
GWC_ABST_C_API bool wndmgr_drawFillRectangle  (int x, int y, int width, int height);

GWC_ABST_C_API bool wndmgr_drawBorderCircle(int x, int y, int radius);
GWC_ABST_C_API bool wndmgr_drawFillCircle  (int x, int y, int radius);

GWC_ABST_C_API bool wndmgr_drawBorderEllipse(int x, int y, int width, int height);
GWC_ABST_C_API bool wndmgr_drawFillEllipse  (int x, int y, int width, int height);

GWC_ABST_C_API bool wndmgr_drawImage(int x, int y, gIMAGE* image);
GWC_ABST_C_API bool wndmgr_drawIcon (int x, int y, gICON* icon);

#endif // !GWC_ABST_WNDMGR_H
