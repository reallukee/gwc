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
    WndMgr::init();

    WindowId window = WndMgr::alloc(800, 600, true);

    WndMgr::open();

    if (!WndMgr::isInitialized())
    {
        Render::shutdown();
        WndMgr::shutdown();

        return 1;
    }

    bool loop = true;

    while (WndMgr::isOpen() && loop)
    {
        gKeys modifiers = gKeys::None;
        gKeys key = gKeys::None;

        bool keyDown = WndMgr::consumeKeyDown(modifiers, key);

        if (keyDown)
        {
            if (key == gKeys::Escape)
            {
                loop = false;

                continue;
            }
        }

        WndMgr::wait(100);
    }

    if (WndMgr::isOpen())
    {
        WndMgr::close();
    }

    Render::shutdown();
    WndMgr::shutdown();

    exit(0);

    return 0;
}
