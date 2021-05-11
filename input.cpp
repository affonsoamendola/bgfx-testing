#include "main.hpp"

#include "input.hpp"

namespace input
{
    void update()
    {
        SDL_Event currentEvent;
        while (SDL_PollEvent(&currentEvent) != 0) 
        {
            ImGui_ImplSDL2_ProcessEvent(&currentEvent);

            if (currentEvent.type == SDL_QUIT) 
            {
                software_running = false;
                break;
            }

            if(currentEvent.type == SDL_KEYDOWN)
            {
                if( currentEvent.key.keysym.scancode == SDL_SCANCODE_D &&
                    currentEvent.key.keysym.mod & KMOD_CTRL)
                {
                    debug_mode = !debug_mode;
                }
            }
        }
    }
}