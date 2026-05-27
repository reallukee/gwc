//
// :.:.:.:.:.
// GWC.Native
// v0.6.0
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// main.cpp
//  Licenza MIT
//

#include <gwc.hpp>

using namespace gwc;

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

void loop(Window* window);

int main(int argc, const char* argv[])
{
    Render::init();

    Window* window = new Window(800, 600);

    window->open();

    if (!window->isInitialized())
    {
        delete window;

        Render::shutdown();

        return EXIT_FAILURE;
    }

    loop(window);

    if (window->isOpen())
    {
        window->close();
    }

    delete window;

    Render::shutdown();

    return EXIT_SUCCESS;
}

void loop(Window* window)
{
    bool loop = true;

    while (window->isOpen() && loop)
    {
        gKeys modifiers = gKeys::None;
        gKeys key = gKeys::None;

        bool keyDown = window->consumeKeyDown(modifiers, key);

        if (keyDown)
        {
            if (key == gKeys::Escape)
            {
                loop = false;

                continue;
            }
        }

        bool exit = window->isKeyDownInBuffer(gKeys::None, gKeys::Escape);

        if (exit)
        {
            loop = false;

            continue;
        }

        window->wait(100);
    }
}
