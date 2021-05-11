#pragma once

#include "color.hpp"
#include "rect.hpp"

namespace gfx
{   
    extern Color4b clear_color;
    inline void set_clear_color(const Color4b& t_color) { clear_color = t_color; }
    
    extern Rect4i main_viewport;
    inline void set_main_viewport(const Rect4i& t_rect) { main_viewport = t_rect; }

    void render();

    void init();
    void quit();
}