// $projectname$
//  $gwc_identifier$ $gwc_version$
//  https://github.com/reallukee/gwc

#include <gwc.hpp>

#include <iostream>

using namespace gwc;

using namespace std;

int main(int argc, const char* argv[])
{
    cout << "Welcome in $projectname$!" << endl;
    cout << "Using GWC v" << GWC_VERSION << endl;
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
        int key = -1;

        bool keyDown = window->consumeKeyDown(key);

        if (keyDown)
        {
            if (key == 27)
            {
                loop = false;

                continue;
            }

            cout << "Pressed: " << key << endl;

            window->setBorderColor(Color(100, 0, 128, 0));
            window->setFillColor(Color(100, 0, 255, 0));

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

    return 0;
}
