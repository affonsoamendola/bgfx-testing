#pragma once

#include "bgfx_integration.hpp"

namespace vertex
{
    extern bgfx::VertexLayout layout;

    void init();
}

struct Vertex4xyzc
{
    float x;
    float y;
    float z;
    uint32_t color; //In ABGR
};