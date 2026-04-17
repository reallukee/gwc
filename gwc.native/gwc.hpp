//
// :.:.:.:.:.
// GWC.Native
// v0.3.0
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
//  0.3.0
//

#define GWC_VERSION_INCLUDE     "030"
#define GWC_MIN_VERSION_INCLUDE "021"

#include "types.hpp"
#include "Color.hpp"
#include "Point.hpp"
#include "Keys.hpp"
#include "MouseButtons.hpp"
#include "Render.hpp"
#include "Sprite.hpp"
#include "Canvas.hpp"
#include "Window.hpp"

namespace gwc
{
    GWC_CPP_EXTERN GWC_CPP_DLL const char GWC_VERSION[];
    GWC_CPP_EXTERN GWC_CPP_DLL const char GWC_MIN_VERSION[];
}

#endif // __cplusplus

#endif // !GWC_API_HPP
