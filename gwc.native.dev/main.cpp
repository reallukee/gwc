//
// :.:.:.:.:.
// GWC.Native
// v0.6.1
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// main.cpp
//  Licenza MIT
//

#include <gwc.hpp>

using namespace gwc;

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

int loop(Window* window);

int main(int argc, const char* argv[])
{
    Render::init();

    Window* window = new Window(800, 600);

    window->open();

    if (!window->isInitialized())
    {
        delete window;

        Render::shutdown();

        return EXIT_FAILURE;
    }

    int result = loop(window);

    if (window->isOpen())
    {
        window->close();
    }

    delete window;

    Render::shutdown();

    return result == EXIT_FAILURE ? result : EXIT_SUCCESS;
}

int x = 0;
int y = 0;
int vx = 15;
int vy = 10;
int r = 50;

void update()
{
    x = x + vx;
    y = y + vy;

    if (x < 0)
    {
        x = 0;
        vx = -vx;
    }

    if (x + 2 * r > 800)
    {
        x = 800 - 2 * r;
        vx = -vx;
    }

    if (y < 0)
    {
        y = 0;
        vy = -vy;
    }

    if (y + 2 * r > 600)
    {
        y = 600 - 2 * r;
        vy = -vy;
    }
}

float cr = 255;
float cg = 0;
float cb = 0;

float cvr = 1.2f;
float cvg = 0.8f;
float cvb = 1.6f;

void render(Canvas* canvas, Window* window)
{
    canvas->clear(gColor(255, 0, 0, 0));

    cr += cvr;
    cg += cvg;
    cb += cvb;

    if (cr > 255 || cr < 0)
    {
        cvr = -cvr;
    }

    if (cg > 255 || cg < 0)
    {
        cvg = -cvg;
    }

    if (cb > 255 || cb < 0)
    {
        cvb = -cvb;
    }

    if (cr < 0) cr = 0; if (cr > 255) cr = 255;
    if (cg < 0) cg = 0; if (cg > 255) cg = 255;
    if (cb < 0) cb = 0; if (cb > 255) cb = 255;

    canvas->setFillColor(gColor(255, (int)cr, (int)cg, (int)cb));
    canvas->setBorderColor(gColor(255, (int)cr, (int)cg, (int)cb));

    canvas->drawFillCircle(r, r, r);

    canvas->render();

    window->clear(gColor(255, 0, 0, 0));

    window->drawCanvas(x, y, canvas);
}

int loop(Window* window)
{
    Canvas* canvas = new Canvas(r * 2, r * 2);

    if (!canvas->isInitialized())
    {
        delete canvas;

        return EXIT_FAILURE;
    }

    bool loop = true;

    while (window->isOpen() && loop)
    {
        gKeys modifiers = gKeys::None;
        gKeys key = gKeys::None;

        bool keyDown = window->consumeKeyDown(
            modifiers,
            key
        );

        if (keyDown)
        {
            if (key == gKeys::Escape)
            {
                loop = false;

                continue;
            }
        }

        bool exit = window->isKeyDownInBuffer(
            gKeys::None,
            gKeys::Escape
        );

        if (exit)
        {
            loop = false;

            continue;
        }

        update();

        render(canvas, window);

        window->wait(16);
    }

    delete canvas;

    return EXIT_SUCCESS;
}
