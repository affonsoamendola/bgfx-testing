#pragma once

#include "bgfx_integration.hpp"
#include "hash.hpp"

#include <iostream>
#include <fstream>
#include <string>

namespace resource
{
    enum ErrorType
    {
        NO_ERROR,
        FILE_NOT_FOUND,
        MATCHING_ID_LOADED,
        RESOURCE_LIMIT_REACHED
    };

    struct ResourceHandle
    {
        uint64_t id = 0;
        std::string name_str;

        void* content = NULL;
        uint64_t length = 0;
    };

    const uint64_t MAX_RESOURCES = 16;   
    extern ResourceHandle resource_pile[MAX_RESOURCES];
    extern uint64_t free_index;

    bool get_resource(std::string id, ResourceHandle* out = NULL, uint64_t* index = NULL);

    bool load_resource(std::string id, const char* filename, ResourceHandle* out = NULL, ErrorType* error = NULL);
    bool create_resource_from_data(std::string id, void* object, uint64_t size, ResourceHandle* out, ErrorType* error = NULL);

    bool destroy_resource(std::string id);

    void quit();
    inline void init(){};
}