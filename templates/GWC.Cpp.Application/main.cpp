// $projectname$
//  $gwc_identifier$ $gwc_version$
//  https://github.com/reallukee/gwc

#include <gwc.hpp>

#include <conio.h>

#include <iostream>

using namespace gwc;

using namespace std;

int main(int argc, const char* argv[])
{
    cout << "Welcome in $projectname$!" << endl;
    cout << "Using $gwc_identifier$ $gwc_version$!" << endl;
    cout << endl;

    Render::setRefreshRate(60);
    Render::setDutyCycle(80);

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
