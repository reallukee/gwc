//
// :.:.:.:.:.
// GWC.Native
// v0.4.0
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
    Render::setDefaultRefreshRate();
    Render::setDefaultDutyCycle();

    Window* window = new Window(800, 600);

    window->open();

    if (!window->isInitialized())
    {
        delete window;

        return 1;
    }

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

    exit(0);

    return 0;
}
