//
// :.:.:.:.:.
// GWC.Native
// v0.3.0
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// main.cpp
//  Licenza MIT
//

#include <gwc.hpp>

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace gwc;

using namespace std;

Color generateRandomColor();

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
        Keys modifiers = Keys::None;
        Keys key = Keys::None;

        bool keyDown = window->consumeKeyDown(modifiers, key);

        if (keyDown)
        {
            if (key == Keys::Escape)
            {
                loop = false;

                continue;
            }

            cout << "Pressed: " << static_cast<int>(modifiers) << ", " << static_cast<int>(key) << endl;

            window->setBorderColor(generateRandomColor());
            window->setFillColor(generateRandomColor());

            window->drawFillRectangle(50, 50, 100, 100);
            window->drawBorderRectangle(50, 50, 100, 100);
        }

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

Color generateRandomColor()
{
    srand((unsigned int)time(NULL));

    int alpha = rand() % 100 + 1;
    int red   = rand() % 255 + 1;
    int blue  = rand() % 255 + 1;
    int green = rand() % 255 + 1;

    Color color = Color(alpha, red, green, blue);

    return color;
}
