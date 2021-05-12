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
    sdli::init(); //Start SDL using the sdli(ntegration) headers/code
    bgfxi::init(); //Start bgfx using the bgfxi(ntegration) headers/code
    imguii::init(); //Start Dear imGui using the imguii(ntegration) headers/code

    gfx::init();
    dui::init();

    input::init(); //Needs to be after sdli

    while(software_running)
    {
        imguii::start_frame(); //Starts imGui frame

        input::update(); //Handles input
        gfx::render();   //Render 3D/2D
        dui::draw();    //Draws the debug ui on top of everything

        imguii::end_frame(); //Ends imGui frame
    }

    input::quit();

    dui::quit();
    gfx::quit();

    imguii::quit();
    bgfxi::quit();
    sdli::quit();

    return EXIT_SUCCESS;
}

