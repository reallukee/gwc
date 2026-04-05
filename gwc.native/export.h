//
// :.:.:.:.:.
// GWC.Native
// v0.2.0
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// export.h
//  Licenza MIT
//

#pragma once

#ifndef GWC_EXPORT_H
#define GWC_EXPORT_H

#ifdef __cplusplus
    #define GWC_C_EXTERN extern "C"
#else
    #define GWC_C_EXTERN extern
#endif // __cplusplus

#ifdef GWC_LIBRARY
    #define GWC_C_DLL __declspec(dllexport)

    #define GWC_C_API GWC_C_EXTERN GWC_C_DLL
#else
    #define GWC_C_DLL __declspec(dllimport)

    #define GWC_C_API GWC_C_EXTERN GWC_C_DLL
#endif // GWC_LIBRARY


#endif // !GWC_EXPORT_H
