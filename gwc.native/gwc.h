//
// :.:.:.:.:.
// GWC.Native
// v0.3.0
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// gwc.h
//  Licenza MIT
//

#pragma once

#ifndef GWC_API_H
#define GWC_API_H

//
// Ciao!
//
// Questo è l'header dell'API C di GWC!
// La versione attesa dell'API è:
//
//  0.3.0
//

#define GWC_VERSION_INCLUDE     "030"
#define GWC_MIN_VERSION_INCLUDE "021"

#include "types.h"
#include "COLOR.h"
#include "POINT.h"
#include "KEYS.h"
#include "MOUSEBUTTONS.h"
#include "RENDER.h"
#include "SPRITE.h"
#include "CANVAS.h"
#include "WINDOW.h"

GWC_C_EXTERN GWC_C_DLL const char GWC_VERSION[];
GWC_C_EXTERN GWC_C_DLL const char GWC_MIN_VERSION[];

#endif // !GWC_API_H
