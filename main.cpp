#include <stdio.h>

#include "main.hpp"

#include "input.hpp"
#include "graphics.hpp"
#include "interface.hpp"

const char*     WINDOW_TITLE = "ImGUI testing";

bool software_running = true;
bool debug_mode = true;

int main(int argc, char const *argv[])
{   
    //Start modules
    start_sdl();
    start_bgfx();
    start_imgui();

    while(software_running)
    {
        handle_input();
        render();
    }

    quit_imgui();
    quit_bgfx();
    quit_sdl();

    return EXIT_SUCCESS;
}

