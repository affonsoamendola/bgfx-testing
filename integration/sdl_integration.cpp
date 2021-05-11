#include "main.hpp"

#include "sdl_integration.hpp"

namespace sdli
{
    Vector2i window_resolution = {1300, 700};
    Vector2i get_window_resolution() { return window_resolution; }
    
    SDL_Window*     window = NULL;
    SDL_DisplayMode display_mode;

    SDL_SysWMinfo   wm_info;

    void init()
    {
        if( SDL_Init(SDL_INIT_VIDEO) < 0 ) //Initialize SDL
        {
            printf("SDL could not be initialized! SDL Error : %s\n", SDL_GetError());
            exit(EXIT_FAILURE); //Exit in case something goes wrong
        }

        SDL_GetDesktopDisplayMode(0, &display_mode); // Obtain the current display mode

        window = SDL_CreateWindow(  WINDOW_TITLE, 
                                    SDL_WINDOWPOS_UNDEFINED, 
                                    SDL_WINDOWPOS_UNDEFINED,
                                    window_resolution.x,
                                    window_resolution.y,
                                    SDL_WINDOW_SHOWN | SDL_WINDOW_VULKAN); //Creates the window

        if( window == NULL )
        {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            exit(EXIT_FAILURE); // Exits if window creation failed
        }


        SDL_VERSION(&wm_info.version);

        if(!SDL_GetWindowWMInfo(window, &wm_info))
        {
            printf("Could not get WMinfo! SDL_Error: %s\n", SDL_GetError());
            exit(EXIT_FAILURE); // Exits if wmi information failed    
        }
    }

    void quit() //Gracefully exit all of SDL
    {
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
}