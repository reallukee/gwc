//
// :.:.:.:.:.
// GWC.Native
// v0.1.1
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// COLOR.h
//  Licenza MIT
//

#pragma once

#ifndef GWC_COLOR_H
#define GWC_COLOR_H

#include "header.h"

typedef struct COLOR COLOR;



GWC_C_EXTERN
GWC_C_API
COLOR* color_new(
    int alpha, int red, int green, int blue);

GWC_C_EXTERN
GWC_C_API
void color_delete(
    COLOR* color);



GWC_C_EXTERN
GWC_C_API
int color_getAlpha(
    const COLOR* color);

GWC_C_EXTERN
GWC_C_API
void color_setAlpha(
    COLOR* color, int value);

GWC_C_EXTERN
GWC_C_API
int color_getRed(
    const COLOR* color);

GWC_C_EXTERN
GWC_C_API
void color_setRed(
    COLOR* color, int value);

GWC_C_EXTERN
GWC_C_API
int color_getGreen(
    const COLOR* color);

GWC_C_EXTERN
GWC_C_API
void color_setGreen(
    COLOR* color, int value);

GWC_C_EXTERN
GWC_C_API
int color_getBlue(
    const COLOR* color);

GWC_C_EXTERN
GWC_C_API
void color_setBlue(
    COLOR* color, int value);

#endif // !GWC_COLOR_H
