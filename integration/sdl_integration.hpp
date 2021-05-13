#pragma once

#include <SDL.h>
#include <SDL_syswm.h>

#include "vector.hpp"

namespace sdli
{
    Vector2i get_window_resolution();
    float get_aspect_ratio();

    extern SDL_Window*      window;
    extern SDL_Surface*     screen_surface;
    extern SDL_DisplayMode  display_mode;
    extern SDL_SysWMinfo    wm_info;

    void init();
    void quit();
}