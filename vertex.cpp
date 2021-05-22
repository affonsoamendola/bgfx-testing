#include "bgfx_integration.hpp"

namespace vertex
{
    bgfx::VertexLayout layout;

    void init()
    {
        layout
            .begin()
            .add(bgfx::Attrib::Position, 3, bgfx::AttribType::Float)
            .add(bgfx::Attrib::Color0,   4, bgfx::AttribType::Uint8, true)
            .end();
    }
}