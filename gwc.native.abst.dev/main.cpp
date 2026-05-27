//
// :.:.:.:.:.:.:.:
// GWC.Native.Abst
// v0.6.0
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

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

void loop();

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

        return EXIT_FAILURE;
    }

    loop();

    if (WndMgr::isOpen())
    {
        WndMgr::close();
    }

    Render::shutdown();
    WndMgr::shutdown();

    return EXIT_SUCCESS;
}

void loop()
{
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

        bool exit = WndMgr::isKeyDownInBuffer(gKeys::None, gKeys::Escape);

        if (exit)
        {
            loop = false;

            continue;
        }

        WndMgr::wait(100);
    }
}
