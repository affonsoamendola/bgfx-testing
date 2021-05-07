#pragma once

#include <SDL.h>
#include <SDL_syswm.h>

extern const int        SCREEN_WIDTH;
extern const int        SCREEN_HEIGHT;

extern SDL_Window*      window;
extern SDL_Surface*     screen_surface;
extern SDL_DisplayMode  display_mode;
extern SDL_SysWMinfo   wm_info;

void start_sdl();
void quit_sdl();