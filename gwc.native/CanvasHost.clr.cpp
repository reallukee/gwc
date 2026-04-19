//
// :.:.:.:.:.
// GWC.Native
// v0.3.1
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// CanvasHost.clr.cpp
//  Licenza MIT
//

#include "CanvasHost.clr.hpp"

#ifdef __cplusplus_cli

namespace Reallukee
{
namespace GWC
{
namespace Interop
{
    CanvasHost::CanvasHost(int width, int height)
    {
        canvas = gcnew Canvas(width, height);
    }

    CanvasHost::CanvasHost()
    {
        canvas = gcnew Canvas();
    }

    CanvasHost::~CanvasHost()
    {
        Canvas^ unwrapCanvas = canvas;

        if (unwrapCanvas != nullptr)
        {
            return;
        }

        canvas = nullptr;
    }



    bool CanvasHost::isNull()
    {
        Canvas^ unwrapCanvas = canvas;

        return unwrapCanvas == nullptr;
    }



    Canvas^ CanvasHost::invoke()
    {
        Canvas^ unwrapCanvas = canvas;

        if (unwrapCanvas == nullptr)
        {
            return nullptr;
        }

        return canvas;
    }
}
}
}

#endif // __cplusplus_cli
