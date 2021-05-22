#pragma once

#include "vertex.hpp"
#include "vector.hpp"
#include "resource.hpp"

struct Object
{
	Vector3f transform = {0};

	bgfx::VertexBufferHandle vertex_buffer_handle;
    bgfx::IndexBufferHandle index_buffer_handle;

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

    void init();
};