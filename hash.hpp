#pragma once

#include <string>

namespace hash
{
    typedef uint64_t HashID;

    /* djb2 algorithm for calculating hash */
    inline uint64_t compute_hash(std::string string)
    {
        const char* s = string.c_str();

        uint64_t hash = 5381;
        int c;

        while ((c = *s++))
        {
            hash = ((hash << 5) + hash) + c;
        }

        return hash;
    }
}