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

#include <gdiplus.h>

using namespace Gdiplus;

typedef shared_ptr<void> NativeImage;

typedef struct gIMAGE
{
    NativeImage image;
} gIMAGE;

Bitmap* imageHelper_get(const gIMAGE* image);

#endif // !GWC_IMAGEHELPER_H
