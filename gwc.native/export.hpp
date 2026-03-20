//
// GWC.Native
//
//  Version : 0.1.0
//  MIT License
//  export.hpp
//

#pragma once

#ifndef GWC_EXPORT_HPP
#define GWC_EXPORT_HPP

#ifdef __cplusplus

#define GWC_CPP_EXTERN extern

#ifdef GWC_LIBRARY
#define GWC_CPP_API __declspec(dllexport)
#else
#define GWC_CPP_API __declspec(dllimport)
#endif // GWC_LIBRARY

#endif // __cplusplus

#endif // !GWC_EXPORT_HPP
