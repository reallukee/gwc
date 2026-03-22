//
// :.:.:.:.:.
// GWC.Native
// v0.1.0
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// header.clr.hpp
//  Licenza MIT
//

#pragma once

#ifndef GWC_HEADER_CLR_HPP
#define GWC_HEADER_CLR_HPP

#ifdef __cplusplus_cli

#include <msclr\appdomain.h>
#include <msclr\auto_gcroot.h>
#include <msclr\auto_handle.h>
#include <msclr\lock.h>
#include <msclr\event.h>
#include <msclr\marshal.h>
#include <msclr\marshal_cppstd.h>
#include <msclr\marshal_windows.h>

using namespace msclr::interop;

using namespace System;
using namespace System::Runtime::InteropServices;

using namespace Reallukee::GWC;

#endif // __cplusplus_cli

#endif // !GWC_HEADER_CLR_HPP
