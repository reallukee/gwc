//
// :.:.:.:.:.
// GWC.Native
// v0.6.1
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// SPRITEHELPER.h
//  Licenza MIT
//

#pragma once

#ifndef GWC_SPRITEHELPER_H
#define GWC_SPRITEHELPER_H

#include "SpriteHost.clr.hpp"

using namespace Reallukee::GWC::Interop;

typedef struct SPRITE SPRITE;

SpriteHost* spriteHelper_get(const SPRITE* sprite);

#endif // !GWC_SPRITEHELPER_H
