#include "imgui_integration.hpp"
#include "sdl_integration.hpp"
#include "bgfx_integration.hpp"

void start_imgui()
{
    ImGui::CreateContext();

    ImGui_Implbgfx_Init(255);

    bgfx::RendererType::Enum renderer_type = bgfx::getRendererType();

    switch(renderer_type)
    {
        case bgfx::RendererType::Direct3D9:
        case bgfx::RendererType::Direct3D11:
        case bgfx::RendererType::Direct3D12:
            ImGui_ImplSDL2_InitForD3D(window);
            break;

        case bgfx::RendererType::Metal:
            ImGui_ImplSDL2_InitForMetal(window);
            break;

        case bgfx::RendererType::OpenGLES:
        case bgfx::RendererType::OpenGL:
            ImGui_ImplSDL2_InitForOpenGL(window, nullptr);
            break;

        case bgfx::RendererType::Vulkan:
            ImGui_ImplSDL2_InitForVulkan(window);
            break;

        default:
            printf("Unknown Renderer Type! Can't initialize Dear ImGUI!\n");
            exit(EXIT_FAILURE);
            break;
    }
}


void start_frame_imgui()
{
    ImGui_Implbgfx_NewFrame();
    ImGui_ImplSDL2_NewFrame(window);
    ImGui::NewFrame();
}

void end_frame_imgui()
{
    ImGui::Render();
    ImGui_Implbgfx_RenderDrawLists(ImGui::GetDrawData());
}

void quit_imgui()
{
    ImGui_ImplSDL2_Shutdown();
    ImGui_Implbgfx_Shutdown();

    ImGui::DestroyContext();
}