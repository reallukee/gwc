// $projectname$
//  $gwc_identifier$ $gwc_version$
//  https://github.com/reallukee/gwc

#include <gwc.hpp>

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace gwc;

using namespace std;

gColor generateRandomColor();

int main(int argc, const char* argv[])
{
    cout << "Welcome in $projectname$!" << endl;
    cout << "Using GWC v" << GWC_FRIENDLY_VERSION << endl;
    cout << endl;

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
        window->close();
    }

    delete window;

    return 0;
}

gColor generateRandomColor()
{
    srand((unsigned int)time(NULL));

    int alpha = rand() % 100 + 1;
    int red   = rand() % 255 + 1;
    int blue  = rand() % 255 + 1;
    int green = rand() % 255 + 1;

    gColor color = gColor(alpha, red, green, blue);

    return color;
}
