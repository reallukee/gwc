//
// :.:.:.:.:.
// GWC.Native
// v0.2.0
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// main.cpp
//  Licenza MIT
//

#include <gwc.hpp>

#include <iostream>

using namespace gwc;

using namespace std;

void showInfo(Window* window);

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

    cout << "Press \"ESC\" to exit..." << endl;

    while (window->isOpen() && loop)
    {
        int key = -1;

        bool keyDown = window->consumeKeyDown(key);

        if (keyDown)
        {
            if (key == 27)
            {
                loop = false;

                continue;
            }

            if (key == 73)
            {
                showInfo(window);

                continue;
            }

            cout << "Pressed: " << key << endl;

            window->setBorderColor(Color(100, 0, 128, 0));
            window->setFillColor  (Color(100, 0, 255, 0));

            window->drawFillRectangle  (50, 50, 100, 100);
            window->drawBorderRectangle(50, 50, 100, 100);
        }

        window->wait(100);
    }

    if (window->isOpen())
    {
        window->shutdown();
    }

    delete window;

    return 0;
}

void showInfo(Window* window)
{
    cout << "Window Width  : " << window->getWindowWidth() << endl;
    cout << "Window Height : " << window->getCanvasHeight() << endl;
    cout << "Render Width  : " << window->getRenderWidth() << endl;
    cout << "Render Height : " << window->getRenderHeight() << endl;
    cout << "Canvas Width  : " << window->getCanvasWidth() << endl;
    cout << "Canvas Height : " << window->getCanvasHeight() << endl;
}
