#include "object.hpp"

void Object::init()
{
	vertex_buffer_handle = bgfx::createVertexBuffer(

	            bgfx::makeRef(cube_vertices, sizeof(cube_vertices)),
	            PosColorVertex::vertex_layout
	            );
	index_buffer_handle = bgfx::createIndexBuffer(

	            bgfx::makeRef(cube_tri_list, sizeof(cube_tri_list))
	            );
}