#pragma once

#include <list>

#include "object.hpp"

#include "resource.hpp"

struct Scene
{
	std::list<resource::ResourceHandle> objects;
};