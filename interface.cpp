#include <list>

#include "main.hpp"

#include "interface.hpp"

#include "graphics_i.hpp"
#include "engine_i.hpp"
#include "input_i.hpp"
#include "resource_i.hpp"
#include "scene_i.hpp"

namespace dui
{
/*
    //Collapsing header Resource Module variables
    void init_resource_header()
    {

    }   

    void draw_resource_header()
    {
         
    }
*/
    void init()
    {
        engine_interface::init();
        gfx_interface::init();
        input_interface::init();
        resource_interface::init();

        scene_interface::init();
    }

    void draw()
    {
        engine_interface::draw();
        gfx_interface::draw();
        input_interface::draw();
        resource_interface::draw();

        scene_interface::draw();

        ImGui::ShowDemoWindow();
    } 

    void quit()
    {
        resource_interface::quit();
        input_interface::quit();
        gfx_interface::quit();
        engine_interface::quit();
    
        scene_interface::quit();
    }
}
