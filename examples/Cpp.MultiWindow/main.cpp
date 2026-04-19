// Cpp.MultiWindow
//  GWC.Native >=0.3.0

#include <iostream>

#include <gwc.hpp>

#include <conio.h>

using namespace std;

using namespace gwc;

int main(int argc, const char* argv[])
{
    Window* window_1 = new Window(800, 600);
    Window* window_2 = new Window(800, 600);
    Window* window_3 = new Window(800, 600);

    window_1->open();
    window_2->open();
    window_3->open();

    if (!window_1->isInitialized() ||
        !window_2->isInitialized() ||
        !window_3->isInitialized())
    {
        delete window_1;
        delete window_2;
        delete window_3;

        return 1;
    }

    _getch();

    window_1->shutdown();
    window_2->shutdown();
    window_3->shutdown();

    delete window_1;
    delete window_2;
    delete window_3;

    exit(0);

    return 0;
}
