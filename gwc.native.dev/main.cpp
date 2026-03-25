//
// :.:.:.:.:.
// GWC.Native
// v0.1.0
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// main.cpp
//  Licenza MIT
//

#include <gwc.hpp>

#include <conio.h>

#include <iostream>

using namespace gwc;

using namespace std;

int main(int argc, const char* argv[])
{
    Window::setRefreshRate(60);
    Window::setDutyCycle(80);

    Window* window = new Window(800, 600);

    window->open();

    if (!window->isInitialized())
    {
        delete window;

        return 1;
    }

    window->setFillColor(Color(100, 0, 255, 0));
    window->setBorderColor(Color(100, 0, 128, 0));

    if (window->isOpen())
    {
        window->drawFillRectangle(50, 50, 100, 100);
        window->drawBorderRectangle(50, 50, 100, 100);

        cout << "Press any key to exit..." << endl;

        _getch();

        window->shutdown();
    }
    else
    {
        cout << "Oh :(" << endl;
    }

    delete window;

    return 0;
}
