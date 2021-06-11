#pragma once

#include "interface.hpp"

namespace engine_interface
{
    void init()
    {

    }

    void draw()
    {
        if (ImGui::CollapsingHeader("Main Engine Module"))
        {
            ImGui::Text("Current fps : %f",         1.0f/timer::delta_time);
            ImGui::Text("Current frame_time : %f",  timer::delta_time);
        }
    }

    void quit()
    {
        
    }
}