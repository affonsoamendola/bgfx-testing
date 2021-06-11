#pragma once

#include "interface.hpp"

#include "input.hpp"

namespace input_interface
{
    int softkey_choice_index = 0;
    input::Softkey softkey_choice;
    
    int scancode_choice_index = 0;
    SDL_Scancode sdl_key_choice; 

    const char* scan_names[input::LEN_SCANNAMES];

    bool show_manager = false;

    void init()
    {
        for(int i = 0; i < input::LEN_SCANNAMES; i++)
        {
            scan_names[i] = input::SDL_SCANNAMES[i].name;
        }

        softkey_choice = (input::Softkey) softkey_choice_index;
        sdl_key_choice = input::SDL_SCANNAMES[0].code;
    }

    void draw()
    {
        if(ImGui::Button("Show/Hide Input Manager"))
        {
            show_manager = !show_manager;
        }
     
        if(show_manager)
        {
            ImGui::Begin("Input Manager");

            if (ImGui::BeginTable("input_manager_list", 2))
            {   
                ImGui::TableSetupColumn("Action");
                ImGui::TableSetupColumn("Button");
                ImGui::TableHeadersRow();

                for(uint32_t i = 0; i < input::get_keybindings_length(); i++)
                {
                    input::SoftkeyPair pair = input::get_keybinding(i);

                    ImGui::TableNextRow();
                    
                    ImGui::TableSetColumnIndex(0);
                    if(input::get_softkey(pair.softkey))
                    {
                        ImGui::TextColored({0.0f, 1.0f, 0.0f, 1.0f}, "%s", input::get_softkey_name(pair.softkey));   
                    }
                    else
                    {
                        ImGui::Text("%s", input::get_softkey_name(pair.softkey));
                    }

                    ImGui::TableSetColumnIndex(1);
                    if(input::get_key(pair.scancode))
                    {
                        ImGui::TextColored({0.0f, 1.0f, 0.0f, 1.0f}, "%s", input::get_scancode_name(pair.scancode));
                    }
                    else
                    {
                        ImGui::Text("%s", input::get_scancode_name(pair.scancode));
                    }

                }

                ImGui::EndTable();
            }

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

            ImGui::End();
        }
    }

    void quit()
    {
        
    }
}