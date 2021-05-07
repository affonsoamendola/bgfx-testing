#include "main.hpp"

#include "sdl_integration.hpp"
#include "bgfx_integration.hpp"

static void setup_bgfx_platform_data(bgfx::PlatformData &pd,
                                     const SDL_SysWMinfo &wmi) 
{
    switch (wmi.subsystem) {
        case SDL_SYSWM_UNKNOWN: abort();

        #if defined(SDL_VIDEO_DRIVER_X11)
        case SDL_SYSWM_X11:
            printf("X11 Window System Detected!\n");
            pd.ndt = wmi.info.x11.display;
            pd.nwh = (void *)(uintptr_t)wmi.info.x11.window;
            break;
        #endif

        #if defined(SDL_VIDEO_DRIVER_WAYLAND)
        case SDL_SYSWM_WAYLAND:

            printf("Wayland Window System Detected!\n");
            pd.ndt = wmi.info.wl.display;
            pd.nwh = wmi.info.wl.surface;
            break;
        #endif

        #if defined(SDL_VIDEO_DRIVER_MIR)
        case SDL_SYSWM_MIR:
            pd.ndt = wmi.info.mir.connection;
            pd.nwh = wmi.info.mir.surface;
            break;
        #endif

        #if defined(SDL_VIDEO_DRIVER_COCOA)
        case SDL_SYSWM_COCOA:
            pd.ndt = NULL;
            pd.nwh = wmi.info.cocoa.window;
            break;
        #endif

        #if defined(SDL_VIDEO_DRIVER_UIKIT)
        case SDL_SYSWM_UIKIT:
            pd.ndt = NULL;
            pd.nwh = wmi.info.uikit.window;
            break;
        #endif

        #if defined(SDL_VIDEO_DRIVER_WINDOWS)
        case SDL_SYSWM_WINDOWS:
            pd.ndt = NULL;
            pd.nwh = wmi.info.win.window;
            break;
        #endif

        #if defined(SDL_VIDEO_DRIVER_WINRT)
        case SDL_SYSWM_WINRT:
            pd.ndt = NULL;
            pd.nwh = wmi.info.winrt.window;
            break;
        #endif

        #if defined(SDL_VIDEO_DRIVER_VIVANTE)
        case SDL_SYSWM_VIVANTE:
            pd.ndt = wmi.info.vivante.display;
            pd.nwh = wmi.info.vivante.window;
            break;
        #endif

        default: 
            printf("Unknow Window System! Aborting!\n");
            exit(EXIT_FAILURE);
            break;
    }

    pd.context = NULL;
    pd.backBuffer = NULL;
    pd.backBufferDS = NULL;
}

void start_bgfx()
{
    bgfx::PlatformData platform_data;

    setup_bgfx_platform_data(platform_data, wm_info);

    bgfx::Init bgfx_init_info;

    bgfx_init_info.type = bgfx::RendererType::OpenGL;
    bgfx_init_info.resolution.width = SCREEN_WIDTH;
    bgfx_init_info.resolution.height = SCREEN_HEIGHT;
    bgfx_init_info.resolution.reset = BGFX_RESET_VSYNC;
    bgfx_init_info.platformData = platform_data;

    bgfx::init(bgfx_init_info);
    bgfx::reset(SCREEN_WIDTH, SCREEN_HEIGHT, BGFX_RESET_VSYNC);

    bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0xFFA500FF, 1.0f, 0);
    
    bgfx::setDebug(BGFX_DEBUG_TEXT);
}

extern int count;

void draw_frame_bgfx()
{
    bgfx::setViewRect(0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    bgfx::touch(0);
    bgfx::dbgTextClear();
    bgfx::dbgTextPrintf(1, 1, 0x4f, "Hello World! %d", count);

    bgfx::frame();
}

void quit_bgfx()
{
    bgfx::shutdown();
}