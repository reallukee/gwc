// Cpp.KeyDown
//  GWC.Native >=0.3.3

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

    gKeys modifiers = gKeys::None;
    gKeys key = gKeys::None;

    while (window->isOpen() && loop)
    {
        bool keyDown = window->consumeKeyDown(modifiers, key);

        if (keyDown)
        {
            cout << "Modifiers : " << static_cast<int>(modifiers) << endl;
            cout << "Key       : " << static_cast<int>(key) << endl;
            cout << endl;

            if (modifiers == gKeys::Control && key == gKeys::Q)
            {
                loop = false;
            }
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
