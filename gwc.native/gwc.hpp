//
// :.:.:.:.:.
// GWC.Native
// v0.1.1
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
//  0.1.1
//

#define _GWC_VERSION     "011"
#define _GWC_MIN_VERSION "011"

#include "Color.hpp"
#include "Render.hpp"
#include "Canvas.hpp"
#include "Window.hpp"

namespace gwc
{
    GWC_CPP_EXTERN GWC_CPP_API const char GWC_VERSION[];
    GWC_CPP_EXTERN GWC_CPP_API const char GWC_MIN_VERSION[];
}

#endif // __cplusplus

#endif // !GWC_API_HPP
