#include "main.hpp"

#include "sdl_integration.hpp"

const int       SCREEN_WIDTH = 800;
const int       SCREEN_HEIGHT = 600;

SDL_Window*     window = NULL;
SDL_DisplayMode display_mode;

SDL_SysWMinfo   wm_info;

void start_sdl()
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
                                SCREEN_WIDTH,
                                SCREEN_HEIGHT,
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

void quit_sdl() //Gracefully exit all of SDL
{
    SDL_DestroyWindow(window);
}