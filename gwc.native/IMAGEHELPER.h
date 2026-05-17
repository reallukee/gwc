//
// :.:.:.:.:.
// GWC.Native
// v0.5.1
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// IMAGEHELPER.h
//  Licenza MIT
//

#pragma once

#ifndef GWC_IMAGEHELPER_H
#define GWC_IMAGEHELPER_H

#include "header.hpp"

#include "IMAGE.h"

typedef shared_ptr<void> NativeImage;

typedef struct gIMAGE
{
    NativeImage image;
} gIMAGE;

HBITMAP imageHelper_get(const gIMAGE* image);

#endif // !GWC_IMAGEHELPER_H
