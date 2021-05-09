#include "main.hpp"

#include "graphics.hpp"
#include "interface.hpp"

Color32rgba clear_color;

void render()
{
    bgfx::setViewRect(0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, clear_color, 1.0f, 0);

    bgfx::touch(0);

    //Render stuff here

    bgfx::frame();
    
    draw_gui();
}

