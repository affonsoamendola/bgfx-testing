#pragma once

#include "interface.hpp"

#include "resource.hpp"

namespace resource_interface
{
    bool show_manager = false;

    void init()
    {

    }

    void draw()
    {
        if(ImGui::Button("Show/Hide Resource Manager"))
        {
            show_manager = !show_manager;
        }

        if (show_manager)
        {
            ImGui::Begin("Resource Manager");

            if (ImGui::BeginTable("table1", 4))
            {
                ImGui::TableSetupColumn("Name");
                ImGui::TableSetupColumn("Hash ID");
                ImGui::TableSetupColumn("Size (Bytes)");
                ImGui::TableSetupColumn("Pointer");
                ImGui::TableHeadersRow();

                for(uint32_t i = 0; i < resource::MAX_RESOURCES; i++)
                {
                    //
                    resource::ResourceHandle current = resource::resource_pile[i];

                    ImGui::TableNextRow();

                    if(resource::resource_pile[i].id == 0) break;

                    ImGui::TableSetColumnIndex(0);
                    ImGui::Text("%s", current.name_str.c_str());

                    ImGui::TableSetColumnIndex(1);
                    ImGui::Text("%X", current.id);

                    ImGui::TableSetColumnIndex(2);
                    ImGui::Text("%d", current.length);

                    ImGui::TableSetColumnIndex(3);
                    ImGui::Text("%p", current.content); 
                }
                ImGui::EndTable();
                ImGui::Text("Free Resources = %d", resource::MAX_RESOURCES - resource::free_index); 

                static char buf1[64] = ""; ImGui::InputText("File",     buf1, 64);
                static char buf2[64] = ""; ImGui::InputText("String ID",     buf2, 64);

                if(ImGui::Button("Load Resource"))
                {
                    resource::load_resource(buf2, buf1, NULL);
                }

                ImGui::SameLine();

                if(ImGui::Button("Destroy Resource"))
                {
                    resource::destroy_resource(buf2);
                }
            }

            ImGui::End();
        }  
    }

    void quit()
    {
        
    }
}