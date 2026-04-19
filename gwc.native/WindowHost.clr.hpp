//
// :.:.:.:.:.
// GWC.Native
// v0.3.1
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// WindowHost.clr.hpp
//  Licenza MIT
//

#pragma once

#ifndef GWC_WINDOWHOST_CLR_HPP
#define GWC_WINDOWHOST_CLR_HPP

#ifdef __cplusplus_cli

#include "header.clr.hpp"

namespace Reallukee
{
namespace GWC
{
namespace Interop
{
    class WindowHost sealed
    {

    public:

        WindowHost (int width, int height);
        WindowHost ();
        ~WindowHost();

        bool    isNull();

        Window^ invoke();

    private:

        gcroot<Window^> window;

    };
}
}
}

#endif // __cplusplus_cli

#endif // !GWC_WINDOWHOST_CLR_HPP
