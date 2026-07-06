//
// :.:.:.:.:.
// GWC.Native
// v0.6.1
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// CANVASHELPER.h
//  Licenza MIT
//

#pragma once

#ifndef GWC_CANVASHELPER_H
#define GWC_CANVASHELPER_H

#include "CanvasHost.clr.hpp"

using namespace Reallukee::GWC::Interop;

typedef struct CANVAS CANVAS;

CanvasHost* canvasHelper_get(const CANVAS* canvas);

#endif // !GWC_CANVASHELPER_H
