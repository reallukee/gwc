//
// :.:.:.:.:.
// GWC.Native
// v0.5.1
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// ICONHELPER.h
//  Licenza MIT
//

#pragma once

#ifndef GWC_ICONHELPER_H
#define GWC_ICONHELPER_H

#include "header.hpp"

#include "ICON.h"

typedef shared_ptr<void> NativeIcon;

typedef struct gICON
{
    NativeIcon icon;
} gICON;

HICON iconHelper_get(const gICON* icon);

#endif // !GWC_ICONHELPER_H
