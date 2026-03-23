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

#include "COLOR.h"

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
    const CANVAS* canvas);



GWC_C_EXTERN
GWC_C_API
COLOR* canvas_getBorderColor(
    const CANVAS* canvas);

GWC_C_EXTERN
GWC_C_API
void canvas_setBorderColor(
    const CANVAS* canvas, const COLOR* color);

GWC_C_EXTERN
GWC_C_API
COLOR* canvas_getFillColor(
    const CANVAS* canvas);

GWC_C_EXTERN
GWC_C_API
void canvas_setFillColor(
    const CANVAS* canvas, const COLOR* color);



GWC_C_EXTERN
GWC_C_API
bool canvas_drawBorderRectangle(
    const CANVAS* canvas, int x, int y, int width, int height);

GWC_C_EXTERN
GWC_C_API
bool canvas_drawFillRectangle(
    const CANVAS* canvas, int x, int y, int width, int height);

#endif // !GWC_CANVAS_H
