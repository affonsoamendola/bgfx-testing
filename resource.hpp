#pragma once

#include "bgfx_integration.hpp"
#include "hash.hpp"

#include <iostream>
#include <fstream>
#include <string>

namespace resource
{
    enum LoadErrorType
    {
        NO_ERROR,
        FILE_NOT_FOUND,
        MATCHING_ID_LOADED
    };

    struct Resource
    {
        uint64_t id = 0;
        std::string name_str;

        void* content = NULL;
        uint64_t length = 0;
    };

    const uint64_t MAX_RESOURCES = 8;   
    extern Resource resource_pile[MAX_RESOURCES];
    extern uint64_t free_index;

    bool get_resource(std::string id, Resource* out = NULL, uint64_t* index = NULL);

    bool load_resource(std::string id, const char* filename, Resource* out = NULL, LoadErrorType* error = NULL);

    bool destroy_resource(std::string id);

    void quit();
    inline void init(){};
}