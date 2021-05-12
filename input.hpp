#pragma once

#include <map>

namespace input
{
    enum Softkey
    {
        SOFTKEY_NONE = -1,
        SOFTKEY_UP,
        SOFTKEY_DOWN,
        SOFTKEY_LEFT,
        SOFTKEY_RIGHT,
        SOFTKEY_A,
        SOFTKEY_B,
        SOFTKEY_C,
        SOFTKEY_D,
        SOFTKEY_W,
        SOFTKEY_X,
        SOFTKEY_Y,
        SOFTKEY_Z,
        SOFTKEY_LENGTH //This is here so I can have the length of the enum in compile time
    };

    struct SoftkeyPair
    {
        Softkey         softkey;
        SDL_Scancode    scancode; 

        bool compare(const Softkey t_softkey, const SDL_Scancode t_scancode)
        {
            return (softkey == t_softkey &&
                    scancode  == t_scancode );
        }   

        void set(const Softkey t_softkey, const SDL_Scancode t_scancode)
        {
            softkey = t_softkey;
            scancode = t_scancode;
        }

        void empty()
        {
            softkey = SOFTKEY_NONE;
        }

        SoftkeyPair() //When constructed, create an identifiable Empty state
        {
            empty();
        }
    };

    void init();
    void quit();

    void update();

    void register_default_keybindings();

    SoftkeyPair get_keybinding(uint32_t index);
    bool register_keybinding(const Softkey t_code, const SDL_Scancode t_key);
    bool unregister_keybinding(const Softkey t_code, const SDL_Scancode t_key);
    
    uint32_t get_keybindings_length();

    bool get_softkey(const Softkey t_code);
    bool get_key(SDL_Scancode t_scancode);
}

#include "input_names.hpp"