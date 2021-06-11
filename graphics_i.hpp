#pragma once

#include "graphics.hpp"

#include "interface.hpp"

namespace gfx_interface
{
	Color4f clear_color_input;
	int viewport_input[4];

    void init()
    {
    	clear_color_input = Color4f::from_Color4rgba(gfx::clear_color);
        memcpy(&viewport_input, gfx::main_viewport.as_array(), sizeof(int) * 4);
    }

    void draw()
    {
        if (ImGui::CollapsingHeader("GFX Module"))
        {
            if(ImGui::ColorEdit4("Clear Color", (float*) &clear_color_input))
            {
                gfx::set_clear_color(clear_color_input.to_Color4rgba());
            }

            if(ImGui::InputInt4("Viewport Rect (x,y,w,h)", (int*) viewport_input))
            {
                gfx::set_main_viewport(Rect4i::from_array((int*)viewport_input));
            }
        }
    }

    void quit()
    {

    }
}