//
// :.:.:.:.:.
// GWC.Native
// v0.4.0
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
//  [0.4.0]
// Versione MINIMA API attesa:
//  [0.4.0]
//
// Assicurati di utilizzare versioni compatibili
// dei binari e dei file di intestazione.
//

#define GWC_VERSION_INCLUDE              040
#define GWC_MIN_VERSION_INCLUDE          040

#define GWC_FRIENDLY_VERSION_INCLUDE     "0.4.0"
#define GWC_FRIENDLY_MIN_VERSION_INCLUDE "0.4.0"

#include "types.h"

#include "RENDER.h"

#include "SPRITE.h"
#include "CANVAS.h"
#include "WINDOW.h"

GWC_C_EXTERN GWC_C_DLL const int  GWC_VERSION;
GWC_C_EXTERN GWC_C_DLL const int  GWC_MIN_VERSION;

GWC_C_EXTERN GWC_C_DLL const char GWC_FRIENDLY_VERSION[];
GWC_C_EXTERN GWC_C_DLL const char GWC_FRIENDLY_MIN_VERSION[];

#endif // !GWC_API_H
