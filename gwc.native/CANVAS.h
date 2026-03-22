//
// :.:.:.:.:.
// GWC.Native
// v0.1.0
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// CANVAS.h
//  Licenza MIT
//

#pragma once

#ifndef GWC_CANVAS_H
#define GWC_CANVAS_H

#include "header.h"

typedef struct CANVAS CANVAS;

GWC_C_EXTERN
GWC_C_API
CANVAS* canvas_new(
    int width, int height);

GWC_C_EXTERN
GWC_C_API
void canvas_delete(
    CANVAS* canvas);

GWC_C_EXTERN
GWC_C_API
bool canvas_isInitialized(
    CANVAS* canvas);



GWC_C_EXTERN
GWC_C_API
bool canvas_drawBorderRectangle(
    CANVAS* canvas, int x, int y, int width, int height);

GWC_C_EXTERN
GWC_C_API
bool canvas_drawFillRectangle(
    CANVAS* canvas, int x, int y, int width, int height);

#endif // !GWC_CANVAS_H
