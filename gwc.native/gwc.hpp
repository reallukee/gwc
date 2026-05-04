//
// :.:.:.:.:.
// GWC.Native
// v0.4.0
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// gwc.hpp
//  Licenza MIT
//

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

#include "types.hpp"

#include "Render.hpp"

#include "Sprite.hpp"
#include "Canvas.hpp"
#include "Window.hpp"

namespace gwc
{
    GWC_CPP_EXTERN GWC_CPP_DLL const int  GWC_VERSION;
    GWC_CPP_EXTERN GWC_CPP_DLL const int  GWC_MIN_VERSION;

    GWC_CPP_EXTERN GWC_CPP_DLL const char GWC_FRIENDLY_VERSION[];
    GWC_CPP_EXTERN GWC_CPP_DLL const char GWC_FRIENDLY_MIN_VERSION[];
}

#endif // __cplusplus

#endif // !GWC_API_HPP
