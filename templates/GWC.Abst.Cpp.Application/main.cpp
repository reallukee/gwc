// $projectname$
//  $gwc_identifier$ $gwc_version$
//  https://github.com/reallukee/gwc

#include <gwc.hpp>

using namespace gwc;

#include <gwc_abst.hpp>

using namespace gwc_abst;

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

void loop();

int main(int argc, const char* argv[])
{
    cout << "Welcome in $projectname$!" << endl;
    cout << "Using GWC v" << GWC_FRIENDLY_VERSION << endl;
    cout << endl;

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

        WndMgr::wait(16);
    }
}
