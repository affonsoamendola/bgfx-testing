#include "object.hpp"

Object::Object()
{
	printf("Created Object!");

	vertex_buffer_handle = bgfx::createVertexBuffer(

	            bgfx::makeRef(vertices, sizeof(vertices)),
	            vertex::layout
	            );
	index_buffer_handle = bgfx::createIndexBuffer(

	            bgfx::makeRef(tris, sizeof(tris))
	            );
}

Object::~Object()
{
	bgfx::destroy(index_buffer_handle);
    bgfx::destroy(vertex_buffer_handle);
}