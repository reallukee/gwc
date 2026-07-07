//
// :.:.:.:.:.:.:.:
// GWC.Native.Abst
// v0.6.1
// :.:.:.:.:.:.:.:
//
// https://github.com/reallukee/gwc
//
// main.cpp
//  Licenza MIT
//

#include <gwc.hpp>

using namespace gwc;

#include <gwc_abst.hpp>

using namespace gwc_abst;

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

int loop();

int main(int argc, const char* argv[])
{
    Render::init(); // Inizializzo Render
    WndMgr::init(); // Inizializzo Window Manager
    CnvMgr::init(); // Inizializzo canvas Manager

    WindowId window = WndMgr::alloc(800, 600, true);

    WndMgr::open();

    if (!WndMgr::isInitialized())
    {
        Render::shutdown();
        WndMgr::shutdown();
        CnvMgr::shutdown();

        return EXIT_FAILURE;
    }

    int result = loop();

    if (WndMgr::isOpen())
    {
        WndMgr::close();
    }

    Render::shutdown();
    WndMgr::shutdown();
    CnvMgr::shutdown();

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

void render(CnvId canvas)
{
    CnvMgr::clear(gColor(255, 0, 0, 0));

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

    CnvMgr::setFillColor(gColor(255, (int)cr, (int)cg, (int)cb));
    CnvMgr::setBorderColor(gColor(255, (int)cr, (int)cg, (int)cb));

    CnvMgr::drawFillCircle(r, r, r);

    CnvMgr::render();

    WndMgr::clear(gColor(255, 0, 0, 0));

    WndMgr::drawCanvas(x, y, canvas);
}

int loop()
{
    CanvasId canvas = CnvMgr::alloc(r * 2, r * 2, true);

    if (!CnvMgr::isInitialized())
    {
        CnvMgr::free();

        return EXIT_FAILURE;
    }

    bool loop = true;

    while (WndMgr::isOpen() && loop)
    {
        gKeys modifiers = gKeys::None;
        gKeys key = gKeys::None;

        bool keyDown = WndMgr::consumeKeyDown(
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

        bool exit = WndMgr::isKeyDownInBuffer(
            gKeys::None,
            gKeys::Escape
        );

        if (exit)
        {
            loop = false;

            continue;
        }

        update();

        render(canvas);

        WndMgr::wait(16);
    }

    return EXIT_SUCCESS;
}
