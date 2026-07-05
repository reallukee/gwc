//
// :.:.:.:.:.
// GWC.Native
// v0.6.1
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
//  [0.6.1]
// Versione MINIMA API attesa:
//  [0.6.0]
//
// Assicurati di utilizzare versioni compatibili
// dei binari e dei file di intestazione.
//
// GWC.Native richiede:
//  GWC:
//   [0.6.1]
//

#define GWC_VERSION_INCLUDE              061
#define GWC_MIN_VERSION_INCLUDE          060

#define GWC_FRIENDLY_VERSION_INCLUDE     "0.6.1"
#define GWC_FRIENDLY_MIN_VERSION_INCLUDE "0.6.0"

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
