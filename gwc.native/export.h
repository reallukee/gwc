//
// :.:.:.:.:.
// GWC.Native
// v0.1.0
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
    #define GWC_C_API __declspec(dllexport)
#else
    #define GWC_C_API __declspec(dllimport)
#endif // GWC_LIBRARY

#endif // !GWC_EXPORT_H
