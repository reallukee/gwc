//
// :.:.:.:.:.
// GWC.Native
// v0.3.0
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// SpriteHandler.clr.hpp
//  Licenza MIT
//

#pragma once

#ifndef GWC_SPRITEHANDLER_CLR_HPP
#define GWC_SPRITEHANDLER_CLR_HPP

#ifdef __cplusplus_cli

#include "header.clr.hpp"

namespace Reallukee
{
    namespace GWC
    {
        namespace Interop
        {
            public ref class SpriteHandler abstract
            {

            public:

                static IntPtr  Alloc(int width, int height);
                static IntPtr  Alloc();

                static bool    Free(IntPtr handle);

                static bool    IsNull(IntPtr handle);

                static Sprite^ Invoke(IntPtr handle);

            private:

                SpriteHandler();
                ~SpriteHandler();

            };
        }
    }
}

#endif // __cplusplus_cli

#endif // !GWC_SPRITEHANDLER_CLR_HPP
