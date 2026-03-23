//
// :.:.:.:.:.
// GWC.Native
// v0.1.0
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

#include "COLOR.h"

typedef struct WINDOW WINDOW;



GWC_C_EXTERN
GWC_C_API
WINDOW* window_new(
    int width, int height);

GWC_C_EXTERN
GWC_C_API
void window_delete(
    WINDOW* window);



GWC_C_EXTERN
GWC_C_API
bool window_isInitialized(
    const WINDOW* window);



GWC_C_EXTERN
GWC_C_API
int window_getRefreshRate();

GWC_C_EXTERN
GWC_C_API
void window_setRefreshRate(
    int value);

GWC_C_EXTERN
GWC_C_API
int window_getDutyCycle();

GWC_C_EXTERN
GWC_C_API
void window_setDutyCycle(
    int value);

GWC_C_EXTERN
GWC_C_API
double window_getFrameTime();

GWC_C_EXTERN
GWC_C_API
double window_getUtilFrameTime();



GWC_C_EXTERN
GWC_C_API
bool window_open(
    const WINDOW* window);

GWC_C_EXTERN
GWC_C_API
bool window_shutdown(
    const WINDOW* window);

GWC_C_EXTERN
GWC_C_API
bool window_isOpen(
    const WINDOW* window);

GWC_C_EXTERN
GWC_C_API
bool window_isShutdown(
    const WINDOW* window);



GWC_C_EXTERN
GWC_C_API
COLOR* window_getBorderColor(
    const WINDOW* window);

GWC_C_EXTERN
GWC_C_API
void window_setBorderColor(
    const WINDOW* window, const COLOR* color);

GWC_C_EXTERN
GWC_C_API
COLOR* window_getFillColor(
    const WINDOW* window);

GWC_C_EXTERN
GWC_C_API
void window_setFillColor(
    const WINDOW* window, const COLOR* color);



GWC_C_EXTERN
GWC_C_API
bool window_drawBorderRectangle(
    const WINDOW* window, int x, int y, int width, int height);

GWC_C_EXTERN
GWC_C_API
bool window_drawFillRectangle(
    const WINDOW* window, int x, int y, int width, int height);

#endif // !GWC_WINDOW_H
