//
// :.:.:.:.:.
// GWC.Native
// v0.5.0
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// Render.cpp
//  Licenza MIT
//

#include "gwc.clr.hpp"

#include "Render.hpp"

#include <gdiplus.h>

#ifdef __cplusplus

namespace gwc
{
    static ULONG_PTR token = 0;

    bool Render::init()
    {
        if (token != 0)
        {
            return true;
        }

        Gdiplus::GdiplusStartupInput input;

        Gdiplus::Status status = Gdiplus::GdiplusStartup(
            &token,
            &input,
            nullptr
        );

        if (status != Gdiplus::Status::Ok)
        {
            token = 0;

            return false;
        }

        return true;
    }

    void Render::shutdown()
    {
        if (token != 0)
        {
            Gdiplus::GdiplusShutdown(token);

            token = 0;
        }
    }



    int Render::getRefreshRate()
    {
        return GWC::Render::RefreshRate;
    }

    void Render::setRefreshRate(int value)
    {
        GWC::Render::RefreshRate = value;
    }

    void Render::setDefaultRefreshRate()
    {
        GWC::Render::SetDefaultRefreshRate();
    }



    int Render::getDutyCycle()
    {
        return GWC::Render::DutyCycle;
    }

    void Render::setDutyCycle(int value)
    {
        GWC::Render::DutyCycle = value;
    }

    void Render::setDefaultDutyCycle()
    {
        GWC::Render::SetDefaultDutyCycle();
    }



    double Render::getFrameTime()
    {
        return GWC::Render::FrameTime;
    }

    double Render::getUtilFrameTime()
    {
        return GWC::Render::UtilFrameTime;
    }



    Render::Render() { }

    Render::~Render() { }
}

#endif // __cplusplus
