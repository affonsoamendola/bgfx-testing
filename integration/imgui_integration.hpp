#pragma once

#include <imgui/imgui.h>
#include <imgui/imgui_impl_bgfx.h>
#include <imgui/imgui_impl_sdl.h>
#include <bx/platform.h>

void start_imgui();
void quit_imgui();

void imgui_start_frame();
void imgui_end_frame();