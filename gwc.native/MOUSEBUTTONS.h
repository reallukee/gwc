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
    gMOUSEBUTTONS_NONE     = 0,
    gMOUSEBUTTONS_LEFT     = 1048576,
    gMOUSEBUTTONS_RIGHT    = 2097152,
    gMOUSEBUTTONS_MIDDLE   = 4194304,
    gMOUSEBUTTONS_XBUTTON1 = 8388608,
    gMOUSEBUTTONS_XBUTTON2 = 16777216
} gMOUSEBUTTONS;

#endif // !GWC_MOUSEBUTTONS_H
