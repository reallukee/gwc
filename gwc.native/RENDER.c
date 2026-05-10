//
// :.:.:.:.:.
// GWC.Native
// v0.5.0
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// RENDER.c
//  Licenza MIT
//

#include "gwc.clr.hpp"

#include "RENDER.h"

static ULONG_PTR token = 0;

bool render_init()
{
    if (token != 0)
    {
        return true;
    }

    Gdiplus::GdiplusStartupInput input;

    Gdiplus::Status status = Gdiplus::GdiplusStartup(
        &token,
        &input,
        NULL
    );

    if (status != Gdiplus::Status::Ok)
    {
        token = 0;

        return false;
    }

    return true;
}

void render_shutdown()
{
    if (token != 0)
    {
        Gdiplus::GdiplusShutdown(token);

        token = 0;
    }
}



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
