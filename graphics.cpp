#include "main.hpp"

#include "graphics.hpp"
#include "resource.hpp"
#include "timer.hpp"

#pragma GCC diagnostic push 
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#pragma GCC diagnostic pop

#include <bx/math.h>

namespace gfx
{
    Color4rgba clear_color;
    Rect4i main_viewport;   

    struct PosColorVertex
    {
        float x;
        float y;
        float z;
        uint32_t color; //In ABGR

        static void init()
        {
            vertex_layout
                .begin()
                .add(bgfx::Attrib::Position, 3, bgfx::AttribType::Float)
                .add(bgfx::Attrib::Color0,   4, bgfx::AttribType::Uint8, true)
                .end();
        }

        static bgfx::VertexLayout vertex_layout;
    };

    bgfx::VertexLayout PosColorVertex::vertex_layout;
    bgfx::VertexBufferHandle vertex_buffer_handle;
    bgfx::IndexBufferHandle index_buffer_handle;

    //Render Cube
    static PosColorVertex cube_vertices[] =
    {
        {-10.0f,  10.0f,  10.0f, 0xff555555 },
        { 10.0f,  10.0f,  10.0f, 0xff0000ff },
        {-10.0f, -10.0f,  10.0f, 0xff00ff00 },
        { 10.0f, -10.0f,  10.0f, 0xff00ffff },
        {-10.0f,  10.0f, -10.0f, 0xffff0000 },
        { 10.0f,  10.0f, -10.0f, 0xffff00ff },
        {-10.0f, -10.0f, -10.0f, 0xffffff00 },
        { 10.0f, -10.0f, -10.0f, 0xffffffff },
    };

    static const uint16_t cube_tri_list[] =
    {
        0, 1, 2, // 0
        1, 3, 2,
        4, 6, 5, // 2
        5, 6, 7,
        0, 2, 4, // 4
        4, 2, 6,
        1, 5, 3, // 6
        5, 7, 3,
        0, 4, 1, // 8
        4, 5, 1,
        2, 3, 6, // 10
        6, 3, 7,
    };

    resource::Resource fragment_shader;
    resource::Resource vertex_shader;

    bgfx::ShaderHandle fragment_shader_handle;
    bgfx::ShaderHandle vertex_shader_handle;

    bgfx::ProgramHandle program_handle;

    float x_rot = 0.0f;
    float y_rot = 0.0f;

    //Render Cube

    void init()
    {
        Vector2i resolution = sdli::get_window_resolution();
    
        main_viewport = {0, 0, resolution.x, resolution.y};
        clear_color.value = 0xFFA500FF;

        //Render cube
        PosColorVertex::init();
        vertex_buffer_handle = bgfx::createVertexBuffer(

            bgfx::makeRef(cube_vertices, sizeof(cube_vertices)),
            PosColorVertex::vertex_layout
            );
        index_buffer_handle = bgfx::createIndexBuffer(

            bgfx::makeRef(cube_tri_list, sizeof(cube_tri_list))
            );

        //fragment_shader = load_resource("shaders/testfs.bin");
        //vertex_shader = load_resource("shaders/testvs.bin");

        load_resource("test_fragment_shader", "shaders/testfs.bin", &fragment_shader);
        load_resource("test_vertex_shader", "shaders/testvs.bin", &vertex_shader);

        const bgfx::Memory* fragment_shader_buffer = bgfx::copy(fragment_shader.content, fragment_shader.length);
        const bgfx::Memory* vertex_shader_buffer =   bgfx::copy(vertex_shader.content, vertex_shader.length);

        fragment_shader_handle = bgfx::createShader(fragment_shader_buffer);
        vertex_shader_handle = bgfx::createShader(vertex_shader_buffer);

        program_handle = bgfx::createProgram(vertex_shader_handle, fragment_shader_handle, true);

        //Render
    }

    void render()
    {
        bgfx::setViewRect(0, main_viewport.x, main_viewport.y, main_viewport.w, main_viewport.h);
        bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, clear_color.value, 1.0f, 0);

        //Render stuff here
        const bx::Vec3 at  = { 0.0f, 0.0f,   0.0f };
        const bx::Vec3 eye = { 0.0f, 0.0f, -35.0f };

        {
            float view[16];
            bx::mtxLookAt(view, eye, at);

            float proj[16];
            bx::mtxProj(proj,
                        60.0f, 
                        sdli::get_aspect_ratio(),
                        0.1f,
                        100.0f,
                        bgfx::getCaps()->homogeneousDepth
                        );

            bgfx::setViewTransform(0, view, proj);

            uint64_t state = 0 
                | BGFX_STATE_WRITE_R
                | BGFX_STATE_WRITE_G
                | BGFX_STATE_WRITE_B
                | BGFX_STATE_WRITE_A
                | BGFX_STATE_WRITE_Z
                | BGFX_STATE_DEPTH_TEST_LESS
                | BGFX_STATE_CULL_CW
                | BGFX_STATE_MSAA;

            float mtx[16] = {0.0f};

            x_rot += 0.1f * timer::delta_time;
            y_rot += 0.13f * timer::delta_time;

            bx::mtxRotateXY(mtx, x_rot, y_rot);

            mtx[12] = 0.0f;
            mtx[13] = 0.0f;
            mtx[14] = 0.0f;

            bgfx::setTransform(mtx);

            bgfx::setVertexBuffer(0, vertex_buffer_handle);
            bgfx::setIndexBuffer(index_buffer_handle);

            bgfx::setState(state);

            bgfx::submit(0, program_handle);
        }

        //Render cube
        bgfx::touch(0);
        bgfx::frame();
    }

    void quit()
    {
        //render cube
        bgfx::destroy(index_buffer_handle);
        bgfx::destroy(vertex_buffer_handle);
        bgfx::destroy(program_handle);
        //render cube
    }
}