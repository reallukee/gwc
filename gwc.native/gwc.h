//
// :.:.:.:.:.
// GWC.Native
// v0.1.0
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
//  0.1.0
//

#define _GWC_VERSION     "010"
#define _GWC_MIN_VERSION "010"

#include "COLOR.h"
#include "CANVAS.h"
#include "WINDOW.h"

GWC_C_EXTERN GWC_C_API const char GWC_VERSION[];
GWC_C_EXTERN GWC_C_API const char GWC_MIN_VERSION[];

#endif // !GWC_API_H
