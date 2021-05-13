#include "resource.hpp"

namespace resource
{
    Resource resource_pile[MAX_RESOURCES]; //Max of 4096 resources, can be easily increased
    uint64_t free_index = 0;

    bool push_resource(const Resource& resource)
    {
        if(free_index >= 0 && free_index < MAX_RESOURCES) //Bound check
        {
            resource_pile[free_index] = resource; //Push resource on the free spot on the pile
        
            free_index++; //Move the value of the free index, since that space is now occupied
            return true; //Success
        }

        return false; //Failed
    }

    Resource pop_resource() //Remember to free the resource after using it.
    {
        if(free_index > 0 && free_index < MAX_RESOURCES) //Bound check
        {
            free_index--; //Move the free index back, since there is a free place now
            Resource out_res = resource_pile[free_index]; //Get resource handle

            resource_pile[free_index].id = 0; //Sets id of recently popped data to 0, marking it as empty;

            return out_res; //Make sure to return the correct copy of resource, since now
                            //the one on the pile is marked as empty.
        }

        return {0};
    }

    bool get_resource(std::string id, Resource* out, uint64_t* index)
    {
        hash::HashID hash = hash::compute_hash(id);

        for(uint64_t i = 0; i < MAX_RESOURCES; i++)
        {
            if(resource_pile[i].id == 0) break; // If found a id = 0 then it found the empty area of the pile, so theres nothing more to find
            if(resource_pile[i].id == hash) //If found the wanted resource, return it
            {
                if(index != NULL) //Prevent NULL point
                {
                    *index = i; //If index pointer defined, put the index of the resource on the pile there
                }

                if(out != NULL) //Prevent NULL point
                {
                    *out = resource_pile[i]; //If Resource out pointer defined, put the resource wanted there.
                }

                return true;
            }
        }

        return false;
    }

    bool load_resource(std::string id, const char* filename, Resource* out, LoadErrorType* error)
    {
        if(get_resource(id) == true)
        {
            if(error != NULL) *error = MATCHING_ID_LOADED;
            return false;
        }

        Resource new_res;

        std::ifstream in(filename, std::ios::binary); //Open file in binary mode

        if(in.is_open())
        {
            auto begin = in.tellg(); //Get begin position

            in.seekg(0, std::ios::end); //Seek to end
            
            auto end = in.tellg(); //Get end position

            new_res.length = end - begin; //Calculate file size
            
            new_res.content = (char*)malloc(new_res.length); //Uses size to malloc a region on the heap for the file

            in.seekg(0, std::ios::beg); //Go back to the beginning of the file
            
            in.read((char*)new_res.content, new_res.length); //Copies file content into heap

            new_res.id = hash::compute_hash(id); // Calculates the hashID of the resource
            new_res.name_str = id;

            push_resource(new_res); //Pushes new resource on the pile

            if(out != NULL) //Prevent a point to NULL
            {
                *out = new_res; //Returns the contents of the resource file
            }

            if(error != NULL) *error = NO_ERROR;
            return true; //Success
        }
        else
        {
            if(error != NULL) *error = FILE_NOT_FOUND;
            return false; //Failure
        }
    }


    void free_resource(const Resource& res)
    {
        if(res.content != NULL)
        {
            free(res.content);
        }
    }
    
    void destroy_resource(const uint64_t index)
    {
        free_resource(resource_pile[index]);

        for(uint64_t i = index+1; i <= MAX_RESOURCES; i++) // i needs to go until 1 after the final resource
        {   
            if(resource_pile[i-1].id == 0) //Optimize if found the empty area of the pile
            {
                break;
            }

            if(i >= MAX_RESOURCES)
            {
                resource_pile[i-1] = Resource(); //Create new blank object for last object
            }
            else
            {
                resource_pile[i-1] = resource_pile[i]; //Copy the next object into the last object, moving everything down
            }
        }

        if(free_index > 0)
        {
            free_index--;
        }
    }

    bool destroy_resource(std::string id)
    {
        uint64_t index;

        bool found = get_resource(id, NULL, &index);
        
        if(found)
        {
            destroy_resource(index);
        }

        return found;
    }

    

    void quit()
    {
        while(free_index > 0)
        {
            Resource to_free = pop_resource();

            free_resource(to_free);
        }
    }
}