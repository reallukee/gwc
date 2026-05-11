//
// :.:.:.:.:.:.:.:
// GWC.Native.Abst
// v0.2.0
// :.:.:.:.:.:.:.:
//
// https://github.com/reallukee/gwc
//
// export.h
//  Licenza MIT
//

#pragma once

#ifndef GWC_ABST_EXPORT_H
#define GWC_ABST_EXPORT_H

#ifdef __cplusplus
    #define GWC_ABST_C_EXTERN extern "C"
#else
    #define GWC_ABST_C_EXTERN extern
#endif // __cplusplus

#ifdef GWC_ABST_LIBRARY
    #define GWC_ABST_C_DLL __declspec(dllexport)

    #define GWC_ABST_C_API GWC_ABST_C_EXTERN GWC_ABST_C_DLL
#else
    #define GWC_ABST_C_DLL __declspec(dllimport)

    #define GWC_ABST_C_API GWC_ABST_C_EXTERN GWC_ABST_C_DLL
#endif // GWC_ABST_LIBRARY

#endif // !GWC_ABST_EXPORT_H
