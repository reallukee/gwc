//
// :.:.:.:.:.
// GWC.Native
// v0.3.2
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
// :.:.:.:.:.
// Benvenuto!
// :.:.:.:.:.
//
// Grazie per aver scelto GWC <3.
//
// Questo è l'header dell'API C di GWC.
//
// Versione API attesa:
//  [0.3.2]
// Versione MINIMA API attesa:
//  [0.2.1]
//
// Assicurati di utilizzare versioni compatibili
// dei binari e dei file di intestazione.
//

#define GWC_VERSION_INCLUDE     "032"
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
