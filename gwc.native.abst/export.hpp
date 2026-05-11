//
// :.:.:.:.:.:.:.:
// GWC.Native.Abst
// v0.2.0
// :.:.:.:.:.:.:.:
//
// https://github.com/reallukee/gwc
//
// export.hpp
//  Licenza MIT
//

#pragma once

#ifndef GWC_ABST_EXPORT_HPP
#define GWC_ABST_EXPORT_HPP

#ifdef __cplusplus

#define GWC_ABST_CPP_EXTERN extern

#ifdef GWC_ABST_LIBRARY
    #define GWC_ABST_CPP_DLL __declspec(dllexport)

    #define GWC_ABST_CPP_API GWC_ABST_CPP_DLL
#else
    #define GWC_ABST_CPP_DLL __declspec(dllimport)

    #define GWC_ABST_CPP_API GWC_ABST_CPP_DLL
#endif // GWC_ABST_LIBRARY

#endif // __cplusplus

#endif // !GWC_ABST_EXPORT_HPP
