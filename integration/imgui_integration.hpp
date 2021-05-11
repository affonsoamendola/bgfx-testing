#pragma once

#include <imgui/imgui.h>
#include <imgui/imgui_impl_bgfx.h>
#include <imgui/imgui_impl_sdl.h>
#include <bx/platform.h>

namespace imguii
{
    void init();
    void quit();

    void start_frame();
    void end_frame();
}