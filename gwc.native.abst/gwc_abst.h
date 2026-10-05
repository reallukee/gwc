/*
 * :.:.:.:.:.:.:.:.
 * GWC
 * Graphical Window
 * for Console Apps
 * :.:.:.:.:.:.:.:.
 *
 * GWC Native Abst
 *
 * A Graphics Library
 *
 * https://github.com/reallukee/gwc
 *
 * Nome file : gwc_abst.h
 *
 * Titolo    : GWC_ABST
 * Sommario  : GWC_ABST
 *
 * Autore    : Luca Pollicino
 *             (https://github.com/reallukee)
 * Versione  : v0.7.0
 *             NOTA BENE: Campo INDICATIVO!
 * Licenza   : MIT
 */

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
//  [0.7.0]
// Versione MINIMA API attesa:
//  [0.7.0]
//
// Assicurati di utilizzare versioni compatibili
// dei binari e dei file di intestazione.
//
// GWC.Native.Abst richiede:
//  GWC.Native:
//   [0.7.0]
//  GWC:
//   [0.7.0]
//

#define GWC_ABST_VERSION_INCLUDE              70
#define GWC_ABST_MIN_VERSION_INCLUDE          70

#define GWC_ABST_FRIENDLY_VERSION_INCLUDE     "0.7.0"
#define GWC_ABST_FRIENDLY_MIN_VERSION_INCLUDE "0.7.0"

#include "header.h"

#include "types.h"

#include "SRIMGR.h"
#include "CNVMGR.h"
#include "WNDMGR.h"

GWC_ABST_C_EXTERN GWC_ABST_C_DLL const long GWC_ABST_VERSION;
GWC_ABST_C_EXTERN GWC_ABST_C_DLL const long GWC_ABST_MIN_VERSION;

GWC_ABST_C_EXTERN GWC_ABST_C_DLL const char GWC_ABST_FRIENDLY_VERSION[];
GWC_ABST_C_EXTERN GWC_ABST_C_DLL const char GWC_ABST_FRIENDLY_MIN_VERSION[];

#endif // !GWC_ABST_API_H
