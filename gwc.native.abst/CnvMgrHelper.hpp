//
// :.:.:.:.:.:.:.:
// GWC.Native.Abst
// v0.6.1
// :.:.:.:.:.:.:.:
//
// https://github.com/reallukee/gwc
//
// CnvMgrHelper.hpp
//  Licenza MIT
//

#pragma once

#ifndef GWC_ABST_CNVMGRHELPER_HPP
#define GWC_ABST_CNVMGRHELPER_HPP

#ifdef __cplusplus

#include "header.hpp"

#include "types.hpp"

#include <Canvas.hpp>

using namespace gwc;

namespace gwc_abst
{
    class CnvMgrHelper sealed
    {

    public:

        static Canvas* get(CanvasId id);

    private:

        CnvMgrHelper () = default;
        ~CnvMgrHelper() = default;

    };
}

#endif // __cplusplus

#endif // !GWC_ABST_CNVMGRHELPER_HPP
