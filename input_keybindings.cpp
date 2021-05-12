#include "main.hpp"

#include "input.hpp"

namespace input
{
    const uint32_t MAX_BINDINGS = 4096;
    uint32_t free_binding_index = 0;

    SoftkeyPair keybindings[MAX_BINDINGS]; //No one`s ever going to use more than a full uint32 of keybindings, come on

    uint32_t get_keybindings_length()
    {
        return free_binding_index;
    }

    SoftkeyPair get_keybinding(uint32_t index)
    {
        if(index >= 0 && index < MAX_BINDINGS)
        {
            return keybindings[index];
        }

        return SoftkeyPair();
    }

    void register_default_keybindings()
    {
        //Default arrows + zxc, extremely popular in Asia
        register_keybinding(SOFTKEY_UP,     SDL_SCANCODE_UP);
        register_keybinding(SOFTKEY_DOWN,   SDL_SCANCODE_DOWN);
        register_keybinding(SOFTKEY_LEFT,   SDL_SCANCODE_LEFT);
        register_keybinding(SOFTKEY_RIGHT,  SDL_SCANCODE_RIGHT);
        register_keybinding(SOFTKEY_A,      SDL_SCANCODE_Z);
        register_keybinding(SOFTKEY_B,      SDL_SCANCODE_X);
        register_keybinding(SOFTKEY_C,      SDL_SCANCODE_C);

        //Default left handed version of arrows+zxc which I consider to be wasd+hjk
        register_keybinding(SOFTKEY_UP,     SDL_SCANCODE_W);
        register_keybinding(SOFTKEY_DOWN,   SDL_SCANCODE_S);
        register_keybinding(SOFTKEY_LEFT,   SDL_SCANCODE_A);
        register_keybinding(SOFTKEY_RIGHT,  SDL_SCANCODE_D);
        register_keybinding(SOFTKEY_A,      SDL_SCANCODE_H);
        register_keybinding(SOFTKEY_B,      SDL_SCANCODE_J);
        register_keybinding(SOFTKEY_C,      SDL_SCANCODE_K);
    }

    bool register_keybinding(const Softkey t_softkey, const SDL_Scancode t_scancode)
    {
        keybindings[free_binding_index].set(t_softkey, t_scancode); // Sets a key
 
        //Makes sure that the index stays withing the array
        if(free_binding_index < MAX_BINDINGS-1) free_binding_index++; //Increments the free index
    
        return true;
    }

    bool unregister_keybinding(const Softkey t_softkey, const SDL_Scancode t_scancode)
    {
        bool found = false;

        for(uint32_t i = 0; i < MAX_BINDINGS; i++)
        {
            if(keybindings[i].compare(t_softkey, t_scancode))
            {
                found = true;

                continue;
            }

            if(found)
            {
                            //I believe this is safe from accessing -1 since it needs found to be true which cant happen when i = 0
                keybindings[i-1] = keybindings[i]; //Replaces found binding with the next one, until it finds a SOFTKEY_NONE 
            }
            if(keybindings[i].softkey == SOFTKEY_NONE) break; //If found a SOFTKEY_NONE then its past the section of the array that has keybindings
        }

        keybindings[MAX_BINDINGS-1].empty(); //Makes sure the last element is always empty, which makes the 
       
        if(found == true)
        {
            if(free_binding_index > 0) free_binding_index--; //Decrement the free slot start 
            return true;
        }

        return false;
    }

    bool get_softkey(const Softkey t_softkey)
    {
        for(uint32_t i = 0; i < MAX_BINDINGS; i++)
        {
            if( keybindings[i].softkey == t_softkey &&
                get_key(keybindings[i].scancode))
            {
                return true;
            }

            if(keybindings[i].softkey == SOFTKEY_NONE) break;
        }

        return false;
    }
}
