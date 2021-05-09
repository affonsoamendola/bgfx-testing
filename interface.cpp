#include "main.hpp"

#include "graphics.hpp"
#include "interface.hpp"

Color4f clear_color_4f = {0};

void draw_gui()
{
    ImGui_Implbgfx_NewFrame();
    ImGui_ImplSDL2_NewFrame(window);
    ImGui::NewFrame();

    if(debug_mode)
    {     
        //Render stuff here
        if(ImGui::ColorEdit4("Clear Color", (float*)&clear_color_4f))
        {
            clear_color = clear_color_4f.to_Color32rgba();
        }
        
    }

    ImGui::Render();
    ImGui_Implbgfx_RenderDrawLists(ImGui::GetDrawData());
}