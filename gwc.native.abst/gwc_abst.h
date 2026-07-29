//
// :.:.:.:.:.:.:.:
// GWC.Native.Abst
// v0.6.3
// :.:.:.:.:.:.:.:
//
// https://github.com/reallukee/gwc
//
// gwc_abst.h
//  Licenza MIT
//

#pragma once

#ifndef GWC_ABST_API_H
#define GWC_ABST_API_H

//
// :.:.:.:.:.
// Benvenuto!
// :.:.:.:.:.
//
// Grazie per aver scelto GWC <3.
//
// Questo è l'header dell'API C di GWC Abst.
//
// Versione API attesa:
//  [0.6.3]
// Versione MINIMA API attesa:
//  [0.6.3]
//
// Assicurati di utilizzare versioni compatibili
// dei binari e dei file di intestazione.
//
// GWC.Native.Abst richiede:
//  GWC.Native:
//   [0.6.3]
//  GWC:
//   [0.6.3]
//

#define GWC_ABST_VERSION_INCLUDE              63
#define GWC_ABST_MIN_VERSION_INCLUDE          63

#define GWC_ABST_FRIENDLY_VERSION_INCLUDE     "0.6.3"
#define GWC_ABST_FRIENDLY_MIN_VERSION_INCLUDE "0.6.3"

#include "header.h"

#include "types.h"

#include "SRIMGR.h"
#include "CNVMGR.h"
#include "WNDMGR.h"

GWC_ABST_C_EXTERN GWC_ABST_C_DLL const int  GWC_ABST_VERSION;
GWC_ABST_C_EXTERN GWC_ABST_C_DLL const int  GWC_ABST_MIN_VERSION;

GWC_ABST_C_EXTERN GWC_ABST_C_DLL const char GWC_ABST_FRIENDLY_VERSION[];
GWC_ABST_C_EXTERN GWC_ABST_C_DLL const char GWC_ABST_FRIENDLY_MIN_VERSION[];

#endif // !GWC_ABST_API_H
