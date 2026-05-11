// Cpp.KeyDown
//  GWC.Native >=0.4.0

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

    bool loop = true;

    gPoint location;
    gMouseButtons button = gMouseButtons::None;

    while (window->isOpen() && loop)
    {
        bool mouseDown = window->consumeMouseDown(location, button);

        if (mouseDown)
        {
            int x = location.getX();
            int y = location.getY();

            cout << "Location : " << x << ", " << y << endl;
            cout << "Button   : " << static_cast<int>(button) << endl;
            cout << endl;

            if (button == gMouseButtons::Middle)
            {
                loop = false;
            }
        }

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
