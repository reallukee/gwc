//
// :.:.:.:.:.
// GWC.Native
// v0.2.0
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
// Ciao!
//
// Questo è l'header dell'API C++ di GWC!
// La versione attesa dell'API è:
//
//  0.2.0
//

#define GWC_VERSION_INCLUDE     "020"
#define GWC_MIN_VERSION_INCLUDE "020"

#include "types.hpp"
#include "Color.hpp"
#include "Point.hpp"
#include "Render.hpp"
#include "Canvas.hpp"
#include "Window.hpp"

namespace gwc
{
    GWC_CPP_EXTERN GWC_CPP_DLL const char GWC_VERSION[];
    GWC_CPP_EXTERN GWC_CPP_DLL const char GWC_MIN_VERSION[];
}

#endif // __cplusplus

#endif // !GWC_API_HPP
