#include <stdio.h>

#include "sdl_integration.hpp"
#include "bgfx_integration.hpp"
//#include "imgui_integration.hpp"

const char*     WINDOW_TITLE = "ImGUI testing";

bool software_running = true;

int count = 0;
int limit = 120;

int main(int argc, char const *argv[])
{   
    //Start modules
    start_sdl();
    start_bgfx();

    while(count < limit)
    {
        draw_frame_bgfx();
        count++;
    }

    quit_bgfx();
    quit_sdl();

    return EXIT_SUCCESS;
}