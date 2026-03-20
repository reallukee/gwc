//
// GWC.Native
//
//  Version : 0.1.0
//  MIT License
//  main.cpp
//

#include "..\gwc.native\gwc.hpp"

#include <conio.h>

using namespace gwc;

int main(int argc, const char* argv[])
{
    Window* window = new Window();

    window->open();

    if (window->isOpen())
    {
        window->drawFillRectangle(50, 50, 100, 100);
        window->drawBorderRectangle(50, 50, 100, 100);

        _getch();

        window->shutdown();
    }

    delete window;

    return 0;
}
