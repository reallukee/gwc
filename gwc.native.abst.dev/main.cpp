//
// :.:.:.:.:.:.:.:
// GWC.Native.Abst
// v0.5.0
// :.:.:.:.:.:.:.:
//
// https://github.com/reallukee/gwc
//
// main.cpp
//  Licenza MIT
//

#include <gwc.hpp>

using namespace gwc;

#include <gwc_abst.hpp>

using namespace gwc_abst;

int main(int argc, const char* argv[])
{
    Render::init();
    WNDMgr::init();

    WNDMgr::alloc(800, 600, true);

    WNDMgr::open();

    if (!WNDMgr::isInitialized())
    {
        Render::shutdown();
        WNDMgr::shutdown();

        return 1;
    }

    bool loop = true;

    while (WNDMgr::isOpen() && loop)
    {
        WNDMgr::wait(100);
    }

    if (WNDMgr::isOpen())
    {
        WNDMgr::close();
    }

    Render::shutdown();
    WNDMgr::shutdown();

    exit(0);

    return 0;
}
