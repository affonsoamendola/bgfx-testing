#include "main.hpp"

#include "graphics.hpp"

#pragma GCC diagnostic push 
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#pragma GCC diagnostic pop

namespace gfx
{
    Color4rgba clear_color;
    Rect4i main_viewport;   
    
    //Render Cube
    resource::ResourceHandle fragment_shader;
    resource::ResourceHandle vertex_shader;

    bgfx::ShaderHandle fragment_shader_handle;
    bgfx::ShaderHandle vertex_shader_handle;

    bgfx::ProgramHandle program_handle;

    float x_rot = 0.0f;
    float y_rot = 0.0f;

    Scene scene;

    //Render Cube

    void init()
    {
        Vector2i resolution = sdli::get_window_resolution();
    
        main_viewport = {0, 0, resolution.x, resolution.y};
        clear_color.value = 0xFFA500FF;

        vertex::init();
    
        //fragment_shader = load_resource("shaders/testfs.bin");
        //vertex_shader = load_resource("shaders/testvs.bin");

    //This needs to be in the Material code eventually

        load_resource("test_fragment_shader", "shaders/testfs.bin", &fragment_shader);
        load_resource("test_vertex_shader", "shaders/testvs.bin", &vertex_shader);

        const bgfx::Memory* fragment_shader_buffer = bgfx::copy(fragment_shader.content, fragment_shader.length);
        const bgfx::Memory* vertex_shader_buffer =   bgfx::copy(vertex_shader.content, vertex_shader.length);

        fragment_shader_handle = bgfx::createShader(fragment_shader_buffer);
        vertex_shader_handle = bgfx::createShader(vertex_shader_buffer);

        program_handle = bgfx::createProgram(vertex_shader_handle, fragment_shader_handle, true);
    //End of material placeholder

    //This is also placeholder
        for(int i = 0; i < 10; i++)
        {
            Object object;

            object.transform.x = 1.0f * i;
            object.transform.z = -3.0f;

            resource::ResourceHandle new_res;

            std::string obj_name = ("Object " + std::to_string(i));

            resource::create_resource_from_data(obj_name , 
                                                &object, 
                                                sizeof(object), 
                                                &new_res, 
                                                NULL);

            //scene.objects.push_back(new_res);
        }
    //This is also placeholder

        //Render
    }

    void render()
    {
        bgfx::setViewRect(0, main_viewport.x, main_viewport.y, main_viewport.w, main_viewport.h);
        bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, clear_color.value, 1.0f, 0);

        //Render stuff here
        const bx::Vec3 at  = { 0.0f, 0.0f,   0.0f };
        const bx::Vec3 eye = { 0.0f, 0.0f, -35.0f };

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

        for(auto it = scene.objects.begin(); it != scene.objects.end(); it++)
        {
            /*
            float mtx[16] = {0.0f};

            x_rot += 0.1f * timer::delta_time;
            y_rot += 0.13f * timer::delta_time;

            bx::mtxRotateXY(mtx, x_rot, y_rot);

            bx::mtxTranslate(mtx, it->transform.x, it->transform.y, it->transform.z);
            
            bgfx::setTransform(mtx);

            bgfx::setVertexBuffer(0, it->vertex_buffer_handle);
            bgfx::setIndexBuffer(it->index_buffer_handle);

            bgfx::setState(state);

            bgfx::submit(0, program_handle);
            */
        }

        //Render cube
        bgfx::touch(0);
        bgfx::frame();
    }

    void quit()
    {
        //render cube
        bgfx::destroy(program_handle);
        //render cube
    }
}