//
// :.:.:.:.:.
// GWC.Native
// v0.3.1
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// WindowHost.clr.cpp
//  Licenza MIT
//

#include "WindowHost.clr.hpp"

#ifdef __cplusplus_cli

namespace Reallukee
{
namespace GWC
{
namespace Interop
{
    WindowHost::WindowHost(int width, int height)
    {
        window = gcnew Window(width, height);
    }

    WindowHost::WindowHost()
    {
        window = gcnew Window();
    }

    WindowHost::~WindowHost()
    {
        Window^ unwrapWindow = window;

        if (unwrapWindow != nullptr)
        {
            return;
        }

        window = nullptr;
    }



    bool WindowHost::isNull()
    {
        Window^ unwrapWindow = window;

        return unwrapWindow == nullptr;
    }



    Window^ WindowHost::invoke()
    {
        Window^ unwrapWindow = window;

        if (unwrapWindow == nullptr)
        {
            return nullptr;
        }

        return window;
    }
}
}
}

#endif // __cplusplus_cli
