//
// GWC.Native
//
//  Version : 0.1.0
//  MIT License
//  main.cpp
//

#include "..\gwc.native\gwc.hpp"

#include <conio.h>

#include <iostream>

using namespace gwc;

using namespace std;

int main(int argc, const char* argv[])
{
    Window* window = new Window(800, 600);

    window->open();

    if (!window->isInitialized())
    {
        delete window;

        return 1;
    }

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
