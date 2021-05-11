#include "main.hpp"

#include "graphics.hpp"

namespace gfx
{
    Color4b clear_color = 0xFFA500FF;
    Rect4i main_viewport;

    void init()
    {
        Vector2i resolution = sdli::get_window_resolution();
    
        main_viewport = {0, 0, resolution.x, resolution.y};
    }

    void render()
    {
        bgfx::setViewRect(0, main_viewport.x, main_viewport.y, main_viewport.w, main_viewport.h);
        bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, clear_color, 1.0f, 0);

        bgfx::touch(0);

        //Render stuff here

        bgfx::frame();
    }

    void quit()
    {

    }
}