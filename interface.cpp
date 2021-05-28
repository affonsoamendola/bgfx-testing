#include <list>

#include "main.hpp"

#include "interface.hpp"

namespace dui
{
    std::list<InterfaceModule> modules;

    //Collapsing header Engine variables
/*
    void init_engine_header()
    {

    }

    void draw_engine_header()
    {
        if (ImGui::CollapsingHeader("Main Engine Module"))
        {
            ImGui::Text("Current fps : %f",         1.0f/timer::delta_time);
            ImGui::Text("Current frame_time : %f",  timer::delta_time);
        }
    }

    //Collapsing header GFX Module variables
    

    //Collapsing header Input Module variables
    static int softkey_choice_index = 0;
    static input::Softkey softkey_choice;
    static int scancode_choice_index = 0;
    static SDL_Scancode sdl_key_choice; 

    static const char* scan_names[input::LEN_SCANNAMES];

    void init_input_header()
    {
        for(int i = 0; i < input::LEN_SCANNAMES; i++)
        {
            scan_names[i] = input::SDL_SCANNAMES[i].name;
        }

        softkey_choice = (input::Softkey) softkey_choice_index;
        sdl_key_choice = input::SDL_SCANNAMES[0].code;
    }

    void draw_input_header()
    {
        if (ImGui::CollapsingHeader("Input Module"))
        {   
            if(ImGui::Combo("Softkey",     &softkey_choice_index, input::SOFTKEY_NAME, input::SOFTKEY_LENGTH))
            {
                softkey_choice = (input::Softkey) softkey_choice_index;
            }

            if(ImGui::Combo("SDL_Keycode", &scancode_choice_index, scan_names, input::LEN_SCANNAMES))           
            {
                sdl_key_choice = input::SDL_SCANNAMES[scancode_choice_index].code;
            }

            if(ImGui::Button("Register Keybinding"))
            {
                input::register_keybinding(softkey_choice, sdl_key_choice);
            }
            ImGui::SameLine();
            if(ImGui::Button("Un-Register Keybinding"))
            {
                input::unregister_keybinding(softkey_choice, sdl_key_choice);
            }

            ImGui::Separator();
            if (ImGui::CollapsingHeader("Registered Keybindings"))
            {
                for(uint32_t i = 0; i < input::get_keybindings_length(); i++)
                {
                    input::SoftkeyPair pair = input::get_keybinding(i);

                    ImGui::Text(input::get_softkey_name(pair.softkey));
                    ImGui::SameLine();
                    ImGui::Text("  :  ");
                    ImGui::SameLine();
                    ImGui::Text(input::get_scancode_name(pair.scancode));
                }
            }

            if (ImGui::CollapsingHeader("Triggered Softkeys"))
            {
                for(uint32_t i = 0; i < input::get_keybindings_length(); i++)
                {
                    input::SoftkeyPair pair = input::get_keybinding(i);

                    if(input::get_key(pair.scancode))
                    {
                       ImGui::Text(input::get_softkey_name(pair.softkey)); 
                    }
                }
            }
        }
    }

    //Collapsing header Resource Module variables
    void init_resource_header()
    {

    }   

    void draw_resource_header()
    {
        if (ImGui::CollapsingHeader("Loaded Resources"))
        {
            if (ImGui::BeginTable("table1", 4))
            {
                ImGui::TableSetupColumn("Name");
                ImGui::TableSetupColumn("Hash ID");
                ImGui::TableSetupColumn("Size (Bytes)");
                ImGui::TableSetupColumn("Pointer");
                ImGui::TableHeadersRow();

                for(uint32_t i = 0; i < resource::MAX_RESOURCES; i++)
                {
                    //if(resource::resource_pile[i].id == 0) break;

                    resource::Resource current = resource::resource_pile[i];

                    ImGui::TableNextRow();
                    
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
                ImGui::Text("Free index = %d", resource::free_index); 

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
        }   
    }
*/

    //
    void push_module(const InterfaceModule& t_module)
    {
        modules.push_back(t_module);
    }

    void init()
    {
        for(auto it = modules.begin(); it != modules.end(); it++)
        {
            it->init();   
        }
    }

    void draw()
    {
        if(debug_mode)
        {    
            for(auto it = modules.begin(); it != modules.end(); it++)
            {
                it->draw();   
            }

            ImGui::ShowDemoWindow();
        }

    } 

    void quit()
    {
        for(auto it = modules.begin(); it != modules.end(); it++)
        {
            it->quit();   
        }
    }
}
