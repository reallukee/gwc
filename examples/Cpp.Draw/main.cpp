// Cpp.Draw
//  GWC.Native >=0.5.0

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

    window->setFillColor(gColor(255, 255, 255, 0));
    window->drawFillSquare(100, 100, 100);

    window->setFillColor(gColor(255, 255, 0, 128));
    window->drawFillCircle(150, 150, 50);

    gImage image = gImage("gwc.bmp");
    window->drawImage(100, 300, image);

    gIcon icon = gIcon("gwc.ico");
    window->drawIcon(200, 300, icon);

    while (window->isOpen() && !window->isKeyDownAvailable())
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
