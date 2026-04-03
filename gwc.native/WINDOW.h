//
// :.:.:.:.:.
// GWC.Native
// v0.2.0
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// WINDOW.h
//  Licenza MIT
//

#pragma once

#ifndef GWC_WINDOW_H
#define GWC_WINDOW_H

#include "header.h"
#include "types.h"
#include "COLOR.h"

typedef struct WINDOW WINDOW;

GWC_C_API WINDOW* window_new   (int width, int height);
GWC_C_API void    window_delete(WINDOW* window);

GWC_C_API bool window_isInitialized(const WINDOW* window);

GWC_C_API bool window_open    (const WINDOW* window);
GWC_C_API bool window_shutdown(const WINDOW* window);

GWC_C_API bool window_isOpen    (const WINDOW* window);
GWC_C_API bool window_isShutdown(const WINDOW* window);

GWC_C_API COLOR* window_getBorderColor(const WINDOW* window);
GWC_C_API void   window_setBorderColor(const WINDOW* window, const COLOR* color);
GWC_C_API COLOR* window_getFillColor  (const WINDOW* window);
GWC_C_API void   window_setFillColor  (const WINDOW* window, const COLOR* color);

GWC_C_API void window_wait(const WINDOW* window, int milliseconds);

GWC_C_API int window_getWindowWidth (const WINDOW* window);
GWC_C_API int window_getWindowHeight(const WINDOW* window);
GWC_C_API int window_getRenderWidth (const WINDOW* window);
GWC_C_API int window_getRenderHeight(const WINDOW* window);

GWC_C_API bool window_isKeyDownAvailable(const WINDOW* window);
GWC_C_API void window_resetKeyDown      (const WINDOW* window);
GWC_C_API bool window_consumeKeyDown    (const WINDOW* window, int* key);
GWC_C_API bool window_discardKeyDown    (const WINDOW* window);
GWC_C_API void window_waitKeyDown       (const WINDOW* window);

GWC_C_API bool window_isKeyUpAvailable(const WINDOW* window);
GWC_C_API void window_resetKeyUp      (const WINDOW* window);
GWC_C_API bool window_consumeKeyUp    (const WINDOW* window, int* key);
GWC_C_API bool window_discardKeyUp    (const WINDOW* window);
GWC_C_API void window_waitKeyUp       (const WINDOW* window);

GWC_C_API int window_getCanvasWidth (const WINDOW* window);
GWC_C_API int window_getCanvasHeight(const WINDOW* window);

GWC_C_API bool window_drawBorderSquare(const WINDOW* window, int x, int y, int side);
GWC_C_API bool window_drawFillSquare  (const WINDOW* window, int x, int y, int side);

GWC_C_API bool window_drawBorderRectangle(const WINDOW* window, int x, int y, int width, int height);
GWC_C_API bool window_drawFillRectangle  (const WINDOW* window, int x, int y, int width, int height);

#endif // !GWC_WINDOW_H
