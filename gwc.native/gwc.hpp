/*
 * :.:.:.:.:.:.:.:.
 * GWC
 * Graphical Window
 * for Console Apps
 * :.:.:.:.:.:.:.:.
 *
 * GWC Native
 *
 * A Graphics Library
 *
 * https://github.com/reallukee/gwc
 *
 * Nome file : gwc.hpp
 *
 * Titolo    : GWC
 * Sommario  : GWC
 *
 * Autore    : Luca Pollicino
 *             (https://github.com/reallukee)
 * Versione  : v0.7.0
 *             NOTA BENE: Campo INDICATIVO!
 * Licenza   : MIT
 */

#pragma once

#ifndef GWC_API_HPP
#define GWC_API_HPP

#ifdef __cplusplus

//
// :.:.:.:.:.
// Benvenuto!
// :.:.:.:.:.
//
// Grazie per aver scelto GWC <3.
//
// Questo è l'header dell'API C++ di GWC.
//
// Versione API attesa:
//  [0.7.0]
// Versione MINIMA API attesa:
//  [0.7.0]
//
// Assicurati di utilizzare versioni compatibili
// dei binari e dei file di intestazione.
//
// GWC.Native richiede:
//  GWC:
//   [0.7.0]
//

#define GWC_VERSION_INCLUDE              70
#define GWC_MIN_VERSION_INCLUDE          70

#define GWC_FRIENDLY_VERSION_INCLUDE     "0.7.0"
#define GWC_FRIENDLY_MIN_VERSION_INCLUDE "0.7.0"

#include "types.hpp"

#include "Render.hpp"

#include "Sprite.hpp"
#include "Canvas.hpp"
#include "Window.hpp"

namespace gwc
{
    GWC_CPP_EXTERN GWC_CPP_DLL const long GWC_VERSION;
    GWC_CPP_EXTERN GWC_CPP_DLL const long GWC_MIN_VERSION;

    GWC_CPP_EXTERN GWC_CPP_DLL const char GWC_FRIENDLY_VERSION[];
    GWC_CPP_EXTERN GWC_CPP_DLL const char GWC_FRIENDLY_MIN_VERSION[];
}

#endif // __cplusplus

#endif // !GWC_API_HPP
