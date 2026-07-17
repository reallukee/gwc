//
// :.:.:.:.:.:.:.:
// GWC.Native.Abst
// v0.6.2
// :.:.:.:.:.:.:.:
//
// https://github.com/reallukee/gwc
//
// gwc_abst.hpp
//  Licenza MIT
//

#pragma once

#ifndef GWC_ABST_API_HPP
#define GWC_ABST_API_HPP

#ifdef __cplusplus

//
// :.:.:.:.:.
// Benvenuto!
// :.:.:.:.:.
//
// Grazie per aver scelto GWC <3.
//
// Questo è l'header dell'API C++ di GWC Abst.
//
// Versione API attesa:
//  [0.6.2]
// Versione MINIMA API attesa:
//  [0.6.2]
//
// Assicurati di utilizzare versioni compatibili
// dei binari e dei file di intestazione.
//
// GWC.Native.Abst richiede:
//  GWC.Native:
//   [0.6.2]
//  GWC:
//   [0.6.2]
//

#define GWC_ABST_VERSION_INCLUDE              62
#define GWC_ABST_MIN_VERSION_INCLUDE          62

#define GWC_ABST_FRIENDLY_VERSION_INCLUDE     "0.6.2"
#define GWC_ABST_FRIENDLY_MIN_VERSION_INCLUDE "0.6.2"

#include "header.hpp"

#include "types.hpp"

#include "SriMgr.hpp"
#include "CnvMgr.hpp"
#include "WndMgr.hpp"

namespace gwc_abst
{
    GWC_ABST_CPP_EXTERN GWC_ABST_CPP_DLL const int  GWC_ABST_VERSION;
    GWC_ABST_CPP_EXTERN GWC_ABST_CPP_DLL const int  GWC_ABST_MIN_VERSION;

    GWC_ABST_CPP_EXTERN GWC_ABST_CPP_DLL const char GWC_ABST_FRIENDLY_VERSION[];
    GWC_ABST_CPP_EXTERN GWC_ABST_CPP_DLL const char GWC_ABST_FRIENDLY_MIN_VERSION[];
}

#endif // __cplusplus

#endif // !GWC_ABST_API_HPP
