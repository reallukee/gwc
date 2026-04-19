// Cpp.Draw
//  GWC.Native >=0.3.0

#include <iostream>

#include <gwc.hpp>

using namespace std;

using namespace gwc;

int main(int argc, const char* argv[])
{
    Window* window = new Window(800, 600);

    window->open();

    if (!window->isInitialized())
    {
        delete window;

        return 1;
    }

    window->setFillColor(Color(100, 255, 255, 0));
    window->drawFillSquare(100, 100, 100);

    window->setFillColor(Color(100, 255, 0, 128));
    window->drawFillCircle(150, 150, 50);

    while (window->isOpen() && !window->isKeyDownAvailable())
    {
        window->wait(100);
    }

    if (window->isOpen())
    {
        window->shutdown();
    }

    delete window;

    exit(0);

    return 0;
}
