//
// :.:.:.:.:.
// GWC.Native
// v0.2.0
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// RENDER.c
//  Licenza MIT
//

#include "gwc.clr.hpp"

#include "RENDER.h"

int render_getRefreshRate()
{
    return GWC::Render::RefreshRate;
}

void render_setRefreshRate(int value)
{
    GWC::Render::RefreshRate = value;
}

void render_setDefaultRefreshRate()
{
    GWC::Render::SetDefaultRefreshRate();
}



int render_getDutyCycle()
{
    return GWC::Render::DutyCycle;
}

void render_setDutyCycle(int value)
{
    GWC::Render::DutyCycle = value;
}

void render_setDefaultDutyCycle()
{
    GWC::Render::SetDefaultDutyCycle();
}



double render_getFrameTime()
{
    return GWC::Render::FrameTime;
}

double render_getUtilFrameTime()
{
    return GWC::Render::UtilFrameTime;
}
