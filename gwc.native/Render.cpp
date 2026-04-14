//
// :.:.:.:.:.
// GWC.Native
// v0.3.0
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// Render.cpp
//  Licenza MIT
//

#include "gwc.clr.hpp"

#include "Render.hpp"

#ifdef __cplusplus

namespace gwc
{
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
