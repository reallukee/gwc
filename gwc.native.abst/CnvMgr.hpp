//
// :.:.:.:.:.:.:.:
// GWC.Native.Abst
// v0.5.0
// :.:.:.:.:.:.:.:
//
// https://github.com/reallukee/gwc
//
// CnvMgr.hpp
//  Licenza MIT
//

#pragma once

#ifndef GWC_ABST_CNVMGR_HPP
#define GWC_ABST_CNVMGR_HPP

#ifdef __cplusplus

#include "header.hpp"

#include <types.hpp>

using namespace gwc;

namespace gwc_abst
{
    class GWC_ABST_CPP_API CnvMgr sealed
    {

    public:

        static void init    ();
        static void shutdown();

        static bool setCurrent(int id);
        static int  getCurrent();

        static int  alloc(int width, int height, bool select);
        static int  alloc(bool select);
        static void free ();

        static bool isInitialized();

    private:

        CnvMgr ();
        ~CnvMgr();

    };

    typedef CnvMgr CanvasManager;
}

#endif // __cplusplus

#endif // !GWC_ABST_CNVMGR_HPP
