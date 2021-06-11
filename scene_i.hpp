#pragma once

#include "interface.hpp"

#include "graphics.hpp"

namespace scene_interface
{
	bool show_manager = false;

    void init()
    {

    }

    void draw()
    {
    	if(ImGui::Button("Show/Hide Scene Manager"))
    	{
    		show_manager = !show_manager;
    	}

    	if(show_manager)
    	{
	    	ImGui::Begin("Scene Manager");
	    	
	    	if (ImGui::BeginTable("input_manager_list", 1))
            {   
                ImGui::TableSetupColumn("Object");
                ImGui::TableHeadersRow();

                for(uint32_t i = 0; i < gfx::scene.objects.size(); i++)
                {
                    ImGui::TableNextRow();
                    
                    ImGui::TableSetColumnIndex(0);

                }

                ImGui::EndTable();
            }
           
	    	ImGui::End();    		
    	}
    }

    void quit()
    {
        
    }
}