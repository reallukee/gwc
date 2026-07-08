// $projectname$
//  $gwc_identifier$ $gwc_version$
//  https://github.com/reallukee/gwc

#include <gwc.hpp>

using namespace gwc;

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

void loop(Window* window);

int main(int argc, const char* argv[])
{
    cout << "Welcome in $projectname$!" << endl;
    cout << "Using GWC v" << GWC_FRIENDLY_VERSION << endl;
    cout << endl;

    Render::init();

    Window* window = new Window(800, 600);

    window->open();

    if (!window->isInitialized())
    {
        delete window;

        Render::shutdown();

        return EXIT_FAILURE;
    }

    loop(window);

    if (window->isOpen())
    {
        window->close();
    }

    delete window;

    Render::shutdown();

    return EXIT_SUCCESS;
}

void loop(Window* window)
{
    bool loop = true;

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
        }

        bool exit = window->isKeyDownInBuffer(gKeys::None, gKeys::Escape);

        if (exit)
        {
            loop = false;

            continue;
        }

        window->wait(16);
    }
}
