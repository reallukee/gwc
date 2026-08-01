/*
 * :.:.:.:.:.:.:.:.
 * GWC
 * Graphical Window
 * for Console Apps
 * :.:.:.:.:.:.:.:.
 *
 * GWC Native Abst
 *
 * A Graphics Library
 *
 * https://github.com/reallukee/gwc
 *
 * Nome file : WNDMGR.h
 *
 * Titolo    : WNDMGR
 * Sommario  : WndMgr
 *
 * Autore    : Luca Pollicino
 *             (https://github.com/reallukee)
 * Versione  : v0.6.3
 *             NOTA BENE: Campo INDICATIVO!
 * Licenza   : MIT
 */

#pragma once

#ifndef GWC_ABST_WNDMGR_H
#define GWC_ABST_WNDMGR_H

#pragma unmanaged

#include "header.h"

#include "types.h"

#include "SRIMGR.h"
#include "CNVMGR.h"

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
GWC_ABST_C_API bool wndmgr_isKeyUpAvailable   ();
GWC_ABST_C_API void wndmgr_flushKeyDown       ();
GWC_ABST_C_API void wndmgr_flushKeyUp         ();
GWC_ABST_C_API bool wndmgr_consumeKeyDown     (gKEYS* modifiers, gKEYS* key);
GWC_ABST_C_API bool wndmgr_consumeKeyUp       (gKEYS* modifiers, gKEYS* key);
GWC_ABST_C_API bool wndmgr_discardKeyDown     ();
GWC_ABST_C_API bool wndmgr_discardKeyUp       ();
GWC_ABST_C_API bool wndmgr_isKeyDownInBuffer  (gKEYS modifiers, gKEYS key);
GWC_ABST_C_API bool wndmgr_isKeyUpInBuffer    (gKEYS modifiers, gKEYS key);
GWC_ABST_C_API bool wndmgr_isKeyDownLost      ();
GWC_ABST_C_API bool wndmgr_isKeyUpLost        ();
GWC_ABST_C_API int  wndmgr_keyDownBufferLength();
GWC_ABST_C_API int  wndmgr_keyUpBufferLength  ();

GWC_ABST_C_API bool wndmgr_isMouseDownAvailable ();
GWC_ABST_C_API bool wndmgr_isMouseUpAvailable   ();
GWC_ABST_C_API void wndmgr_flushMouseDown       ();
GWC_ABST_C_API void wndmgr_flushMouseUp         ();
GWC_ABST_C_API bool wndmgr_consumeMouseDown     (gPOINT** location, gMOUSEBUTTONS* button);
GWC_ABST_C_API bool wndmgr_consumeMouseUp       (gPOINT** location, gMOUSEBUTTONS* button);
GWC_ABST_C_API bool wndmgr_discardMouseDown     ();
GWC_ABST_C_API bool wndmgr_discardMouseUp       ();
GWC_ABST_C_API bool wndmgr_isMouseDownInBuffer  (gPOINT* location, gMOUSEBUTTONS button);
GWC_ABST_C_API bool wndmgr_isMouseUpInBuffer    (gPOINT* location, gMOUSEBUTTONS button);
GWC_ABST_C_API bool wndmgr_isMouseDownLost      ();
GWC_ABST_C_API bool wndmgr_isMouseUpLost        ();
GWC_ABST_C_API int  wndmgr_mouseDownBufferLength();
GWC_ABST_C_API int  wndmgr_mouseUpBufferLength  ();

GWC_ABST_C_API int wndmgr_getCanvasWidth ();
GWC_ABST_C_API int wndmgr_getCanvasHeight();

GWC_ABST_C_API gCOLOR* wndmgr_getBorderColor();
GWC_ABST_C_API void    wndmgr_setBorderColor(const gCOLOR* color);
GWC_ABST_C_API gCOLOR* wndmgr_getFillColor  ();
GWC_ABST_C_API void    wndmgr_setFillColor  (const gCOLOR* color);
GWC_ABST_C_API gCOLOR* wndmgr_getBackColor  ();
GWC_ABST_C_API void    wndmgr_setBackColor  (const gCOLOR* color);

GWC_ABST_C_API bool wndmgr_clear     ();
GWC_ABST_C_API bool wndmgr_clearArea (int x, int y, int width, int height);
GWC_ABST_C_API bool wndmgr_clearF    ();
GWC_ABST_C_API bool wndmgr_clearAreaF(float x, float y, float width, float height);

GWC_ABST_C_API bool wndmgr_drawCanvas (int x, int y, CNV_ID canvasId);
GWC_ABST_C_API bool wndmgr_drawCanvasF(float x, float y, CNV_ID canvasId);

GWC_ABST_C_API bool wndmgr_drawSprite (int x, int y, SRI_ID spriteId);
GWC_ABST_C_API bool wndmgr_drawSpriteF(float x, float y, const SRI_ID spriteId);

GWC_ABST_C_API bool wndmgr_drawBorderSquare (int x, int y, int side);
GWC_ABST_C_API bool wndmgr_drawBorderSquareF(float x, float y, float side);
GWC_ABST_C_API bool wndmgr_drawFillSquare   (int x, int y, int side);
GWC_ABST_C_API bool wndmgr_drawFillSquareF  (float x, float y, float side);

GWC_ABST_C_API bool wndmgr_drawBorderRectangle (int x, int y, int width, int height);
GWC_ABST_C_API bool wndmgr_drawBorderRectangleF(float x, float y, float width, float height);
GWC_ABST_C_API bool wndmgr_drawFillRectangle   (int x, int y, int width, int height);
GWC_ABST_C_API bool wndmgr_drawFillRectangleF  (float x, float y, float width, float height);

GWC_ABST_C_API bool wndmgr_drawBorderCircle (int x, int y, int radius);
GWC_ABST_C_API bool wndmgr_drawBorderCircleF(float x, float y, float radius);
GWC_ABST_C_API bool wndmgr_drawFillCircle   (int x, int y, int radius);
GWC_ABST_C_API bool wndmgr_drawFillCircleF  (float x, float y, float radius);

GWC_ABST_C_API bool wndmgr_drawBorderEllipse (int x, int y, int width, int height);
GWC_ABST_C_API bool wndmgr_drawBorderEllipseF(float x, float y, float width, float height);
GWC_ABST_C_API bool wndmgr_drawFillEllipse   (int x, int y, int width, int height);
GWC_ABST_C_API bool wndmgr_drawFillEllipseF  (float x, float y, float width, float height);

GWC_ABST_C_API bool wndmgr_drawImage (int x, int y, gIMAGE* image);
GWC_ABST_C_API bool wndmgr_drawImageF(float x, float y, gIMAGE* image);
GWC_ABST_C_API bool wndmgr_drawIcon  (int x, int y, gICON* icon);
GWC_ABST_C_API bool wndmgr_drawIconF (float x, float y, gICON* icon);

#endif // !GWC_ABST_WNDMGR_H
