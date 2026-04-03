//
// :.:.:.:.:.
// GWC.Native
// v0.2.0
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// export.hpp
//  Licenza MIT
//

#pragma once

#ifndef GWC_EXPORT_HPP
#define GWC_EXPORT_HPP

#ifdef __cplusplus

#define GWC_CPP_EXTERN extern

#ifdef GWC_LIBRARY
#define GWC_CPP_DLL __declspec(dllexport)

#define GWC_CPP_API GWC_CPP_DLL
#else
#define GWC_CPP_DLL __declspec(dllimport)

#define GWC_CPP_API GWC_CPP_DLL
#endif // GWC_LIBRARY

#endif // __cplusplus

#endif // !GWC_EXPORT_HPP
