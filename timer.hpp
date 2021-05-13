#pragma once

#include <chrono>

namespace timer
{   
    extern float delta_time; //Frame delta time, calculated on every end_frame_count();

    void start_count(); //Start a count
    double end_count(); //End a count
  
    void start_frame_count(); //Starts frame count
    void end_frame_count();
}