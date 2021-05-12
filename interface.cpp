#include "main.hpp"

#include "graphics.hpp"
#include "interface.hpp"
#include "input.hpp"

namespace dui
{
    //Collapsing header GFX Module variables
    static Color4f clear_color_input;
    static int viewport_input[4];

    void init_gfx_header()
    {
        clear_color_input = Color4f::from_Color4b(gfx::clear_color);
        memcpy(&viewport_input, gfx::main_viewport.as_array(), sizeof(int) * 4);
    }

    void draw_gfx_header()
    {
        if (ImGui::CollapsingHeader("GFX Module"))
        {
            if(ImGui::ColorEdit4("Clear Color", (float*) &clear_color_input))
            {
                gfx::set_clear_color(clear_color_input.to_Color4b());
            }

            if(ImGui::InputInt4("Viewport Rect (x,y,w,h)", (int*) viewport_input))
            {
                gfx::set_main_viewport(Rect4i::from_array((int*)viewport_input));
            }
        }
    }

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
    
    //
    void init()
    {
        init_gfx_header();
        init_input_header();
    }

    void draw()
    {
        if(debug_mode)
        {    
            draw_gfx_header();
            draw_input_header();
        }
    } 

    void quit()
    {
        
    }
}
