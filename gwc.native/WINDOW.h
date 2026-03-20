//
// GWC.Native
//
//  Version : 0.1.0
//  MIT License
//  WINDOW.h
//

#pragma once

#ifndef GWC_WINDOW_H
#define GWC_WINDOW_H

#include "header.h"

typedef struct WINDOW WINDOW;

GWC_C_EXTERN GWC_C_API WINDOW* window_new   ();
GWC_C_EXTERN GWC_C_API void    window_delete(WINDOW* window);

GWC_C_EXTERN GWC_C_API bool window_open    (WINDOW* window);
GWC_C_EXTERN GWC_C_API bool window_shutdown(WINDOW* window);

GWC_C_EXTERN GWC_C_API bool window_isOpen    (WINDOW* window);
GWC_C_EXTERN GWC_C_API bool window_isShutdown(WINDOW* window);

GWC_C_EXTERN GWC_C_API bool window_drawBorderRectangle(WINDOW* window, int x, int y, int width, int height);
GWC_C_EXTERN GWC_C_API bool window_drawFillRectangle  (WINDOW* window, int x, int y, int width, int height);

#endif // !GWC_WINDOW_H
