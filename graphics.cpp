#include "main.hpp"

#include "graphics.hpp"

#pragma GCC diagnostic push 
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#pragma GCC diagnostic pop

namespace gfx
{
    Color4rgba clear_color;
    Rect4i main_viewport;

    //Render Cube

    struct PosColorVertex
    {
        float x;
        float y;
        float z;
        uint32_t color; //In ABGR
    };

    //Render Cube

    void init()
    {
        Vector2i resolution = sdli::get_window_resolution();
    
        main_viewport = {0, 0, resolution.x, resolution.y};
        clear_color.value = 0xFFA500FF;
    }

    void render()
    {
        bgfx::setViewRect(0, main_viewport.x, main_viewport.y, main_viewport.w, main_viewport.h);
        bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, clear_color.value, 1.0f, 0);

        bgfx::touch(0);

        //Render stuff here

        bgfx::frame();
    }

    void quit()
    {

    }
}