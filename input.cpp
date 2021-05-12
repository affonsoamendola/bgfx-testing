#include "main.hpp"

#include "input.hpp"

namespace input
{
    const uint8_t* key_state;

    void init() //Needs to be initted after sdli
    {
        SDL_PumpEvents();
        key_state = SDL_GetKeyboardState(NULL); //Set key_state to point to the internal SDL keystate array
    
        register_default_keybindings(); //Registers the default keybindings #see input_keybindings.cpp
    }

    void quit()
    {
        
    }

    void update()
    {
        SDL_Event current_event;
        while (SDL_PollEvent(&current_event) != 0)  //Process all events triggered this frame
        {
            ImGui_ImplSDL2_ProcessEvent(&current_event);

            if (current_event.type == SDL_QUIT) //If quit requested, quit;
            {
                software_running = false;
                break;
            }

            if(current_event.type == SDL_KEYDOWN)
            {
                if( current_event.key.keysym.scancode == SDL_SCANCODE_D &&
                    current_event.key.keysym.mod & KMOD_CTRL)
                {
                    debug_mode = !debug_mode;
                }
            }
        }
    }

    bool get_key(SDL_Scancode scancode)
    {
        return key_state[scancode];
    }
}