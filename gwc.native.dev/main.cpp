//
// :.:.:.:.:.
// GWC.Native
// v0.5.0
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// main.cpp
//  Licenza MIT
//

#include <gwc.hpp>

using namespace gwc;

int main(int argc, const char* argv[])
{
    Render::init();

    Window* window = new Window(800, 600);

    window->open();

    if (!window->isInitialized())
    {
        delete window;

        Render::shutdown();

        return 1;
    }

    gImage myBitmap1 = gImage("..\\assets\\playground\\albert_the_rock.bmp");
    gImage myBitmap2 = gImage("..\\assets\\playground\\albert_the_rock_with_cacatus.bmp");
    gImage myBitmap3 = gImage("..\\assets\\playground\\albert_the_rock_nostalgia.bmp");

    window->drawImage(100, 100, myBitmap1);
    window->drawImage(200, 100, myBitmap2);
    window->drawImage(300, 100, myBitmap3);

    bool loop = true;

    while (window->isOpen() && loop)
    {
        window->wait(100);
    }

    if (window->isOpen())
    {
        window->close();
    }

    delete window;

    Render::shutdown();

    exit(0);

    return 0;
}
