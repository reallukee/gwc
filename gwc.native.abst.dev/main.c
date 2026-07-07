//
// :.:.:.:.:.:.:.:
// GWC.Native.Abst
// v0.6.1
// :.:.:.:.:.:.:.:
//
// https://github.com/reallukee/gwc
//
// main.c
//  Licenza MIT
//

#include <gwc.h>

#include <gwc_abst.h>

/*

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

int loop();

int main(int argc, const char* argv[])
{
    render_init(); // Inizializzo Render
    wndmgr_init(); // Inizializzo Window Manager
    cnvmgr_init(); // Inizializzo canvas Manager

    WINDOW_ID window = wndmgr_alloc(800, 600, true);

    wndmgr_open();

    if (!wndmgr_isInitialized())
    {
        render_shutdown();
        wndmgr_shutdown();
        cnvmgr_shutdown();

        return EXIT_FAILURE;
    }

    int result = loop();

    if (wndmgr_isOpen())
    {
        wndmgr_close();
    }

    render_shutdown();
    wndmgr_shutdown();
    cnvmgr_shutdown();

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

void render(CNV_ID canvas)
{
    gCOLOR* color = NULL;

    color = color_new(255, 0, 0, 0);
    cnvmgr_clear(color);
    color_delete(color);

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

    color = color_new(255, (int)cr, (int)cg, (int)cb);
    cnvmgr_setFillColor(color);
    color_delete(color);
    color = color_new(255, (int)cr, (int)cg, (int)cb);
    cnvmgr_setBorderColor(color);
    color_delete(color);

    cnvmgr_drawFillCircle(r, r, r);

    cnvmgr_render();

    color = color_new(255, 0, 0, 0);
    wndmgr_clear(color);
    color_delete(color);

    wndmgr_drawCanvas(x, y, canvas);
}

int loop()
{
    CNV_ID canvas = cnvmgr_alloc(r * 2, r * 2, true);

    if (!cnvmgr_isInitialized())
    {
        cnvmgr_free();

        return EXIT_FAILURE;
    }

    bool loop = true;

    while (wndmgr_isOpen() && loop)
    {
        gKEYS modifiers = gKEYS_NONE;
        gKEYS key = gKEYS_NONE;

        bool keyDown = wndmgr_consumeKeyDown(
            &modifiers,
            &key
        );

        if (keyDown)
        {
            if (key == gKEYS_ESCAPE)
            {
                loop = false;

                continue;
            }
        }

        bool exit = wndmgr_isKeyDownInBuffer(
            gKEYS_NONE,
            gKEYS_ESCAPE
        );

        if (exit)
        {
            loop = false;

            continue;
        }

        update();

        render(canvas);

        wndmgr_wait(16);
    }

    return EXIT_SUCCESS;
}

*/
