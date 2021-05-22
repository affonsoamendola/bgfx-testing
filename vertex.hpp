#pragma once

#include "bgfx_integration.hpp"

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

inline static bgfx::VertexLayout PosColorVertex::vertex_layout;