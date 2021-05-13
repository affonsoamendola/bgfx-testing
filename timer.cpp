#include "timer.hpp"

namespace timer
{   
    float delta_time = 0.0f;

    using namespace std::chrono;

    high_resolution_clock::time_point t_0;
    high_resolution_clock::time_point t_1;

    void start_count() //Start a count
    {
        t_0 = high_resolution_clock::now();
    }

    double end_count() //End a count
    {
        t_1 = high_resolution_clock::now();
    
        duration<double> time_span = duration_cast<duration<double>>(t_1 - t_0);
        
        return time_span.count();
    }

    high_resolution_clock::time_point frame_0;
    high_resolution_clock::time_point frame_1;

    void start_frame_count() //Starts frame count
    {
        frame_0 = high_resolution_clock::now();
    }

    void end_frame_count() //End a frame count
    {
        frame_1 = high_resolution_clock::now();
    
        duration<double> time_span = duration_cast<duration<double>>(frame_1 - frame_0);
        
        delta_time = time_span.count();
    }
}