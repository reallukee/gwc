//
// :.:.:.:.:.
// GWC.Native
// v0.5.0
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// Icon.hpp
//  Licenza MIT
//

#pragma once

#ifndef GWC_ICON_HPP
#define GWC_ICON_HPP

#ifdef __cplusplus

#include "header.hpp"

namespace gwc
{
    class GWC_CPP_API gIcon sealed
    {

    public:

        gIcon (const char* path);
        gIcon (string path);
        gIcon ();
        ~gIcon();

        gIcon(gIcon&& other) noexcept;
        gIcon& operator=(gIcon&& other) noexcept;

        gIcon(const gIcon&) = delete;
        gIcon& operator=(const gIcon&) = delete;

        bool load  (const char* path);
        bool load  (string path);
        void unload();

        bool isLoaded  () const;
        bool isUnloaded() const;

        HICON get() const;

    private:

        HICON icon;

    };
}

#endif // __cplusplus

#endif // !GWC_ICON_HPP
