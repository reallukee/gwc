//
// :.:.:.:.:.
// GWC.Native
// v0.3.3
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// MOUSEBUTTONS.h
//  Licenza MIT
//

#pragma once

#ifndef GWC_MOUSEBUTTONS_H
#define GWC_MOUSEBUTTONS_H

#include "header.h"

typedef enum gMOUSEBUTTONS
{
    MOUSEBUTTONS_NONE     = 0,
    MOUSEBUTTONS_LEFT     = 1048576,
    MOUSEBUTTONS_RIGHT    = 2097152,
    MOUSEBUTTONS_MIDDLE   = 4194304,
    MOUSEBUTTONS_XBUTTON1 = 8388608,
    MOUSEBUTTONS_XBUTTON2 = 16777216
} gMOUSEBUTTONS;

#endif // !GWC_MOUSEBUTTONS_H
