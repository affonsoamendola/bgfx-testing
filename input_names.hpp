#pragma once

namespace input
{
    static const char* SOFTKEY_NAME[]
    {
        "Up",
        "Down",
        "Left",
        "Right",
        "Button A / Confirm",
        "Button B / Cancel",
        "Button C",
        "Button D",
        "Button W",
        "Button X",
        "Button Y",
        "Button Z",
    };
    
    struct ScancodeNamePair
    {
        SDL_Scancode code;
        const char*  name; 
    };

    static const ScancodeNamePair SDL_SCANNAMES[] = 
    {
        {SDL_SCANCODE_UP,           "Up Arrow"},
        {SDL_SCANCODE_DOWN,         "Down Arrow"},
        {SDL_SCANCODE_LEFT,         "Left Arrow"},
        {SDL_SCANCODE_RIGHT,        "Right Arrow"},
        {SDL_SCANCODE_ESCAPE,       "Escape"},
        {SDL_SCANCODE_F1,           "F1"},
        {SDL_SCANCODE_F2,           "F2"},
        {SDL_SCANCODE_F3,           "F3"},
        {SDL_SCANCODE_F4,           "F4"},
        {SDL_SCANCODE_F5,           "F5"},
        {SDL_SCANCODE_F6,           "F6"},
        {SDL_SCANCODE_F7,           "F7"},
        {SDL_SCANCODE_F8,           "F8"},
        {SDL_SCANCODE_F9,           "F9"},
        {SDL_SCANCODE_F10,          "F10"},
        {SDL_SCANCODE_F11,          "F11"},
        {SDL_SCANCODE_F12,          "F12"},
        {SDL_SCANCODE_F12,          "F12"},
        {SDL_SCANCODE_PRINTSCREEN,  "Print Screen"},
        {SDL_SCANCODE_1,            "1"},
        {SDL_SCANCODE_2,            "2"},
        {SDL_SCANCODE_3,            "3"},
        {SDL_SCANCODE_4,            "4"},
        {SDL_SCANCODE_5,            "5"},
        {SDL_SCANCODE_6,            "6"},
        {SDL_SCANCODE_7,            "7"},
        {SDL_SCANCODE_8,            "8"},
        {SDL_SCANCODE_9,            "9"},
        {SDL_SCANCODE_0,            "0"},
        {SDL_SCANCODE_Q,            "Q"},
        {SDL_SCANCODE_W,            "W"},
        {SDL_SCANCODE_E,            "E"},
        {SDL_SCANCODE_R,            "R"},
        {SDL_SCANCODE_T,            "T"},
        {SDL_SCANCODE_Y,            "Y"},
        {SDL_SCANCODE_U,            "U"},
        {SDL_SCANCODE_I,            "I"},
        {SDL_SCANCODE_O,            "O"},
        {SDL_SCANCODE_P,            "P"},
        {SDL_SCANCODE_A,            "A"},
        {SDL_SCANCODE_S,            "S"},
        {SDL_SCANCODE_D,            "D"},
        {SDL_SCANCODE_F,            "F"},
        {SDL_SCANCODE_G,            "G"},
        {SDL_SCANCODE_H,            "H"},
        {SDL_SCANCODE_J,            "J"},
        {SDL_SCANCODE_K,            "K"},
        {SDL_SCANCODE_L,            "L"},
        {SDL_SCANCODE_Z,            "Z"},
        {SDL_SCANCODE_X,            "X"},
        {SDL_SCANCODE_C,            "C"},
        {SDL_SCANCODE_V,            "V"},
        {SDL_SCANCODE_B,            "B"},
        {SDL_SCANCODE_N,            "N"},
        {SDL_SCANCODE_M,            "M"},
        {SDL_SCANCODE_TAB,          "Tab"},
        {SDL_SCANCODE_LSHIFT,       "Left Shift"},
        {SDL_SCANCODE_LCTRL,        "Left Control"},
        {SDL_SCANCODE_LALT,         "Left Alt"},
        {SDL_SCANCODE_SPACE,        "Spacebar"},
        {SDL_SCANCODE_RALT,         "Right Alt"},
        {SDL_SCANCODE_RCTRL,        "Right Control"},
        {SDL_SCANCODE_RSHIFT,       "Rught Shift"},
        {SDL_SCANCODE_RETURN,       "Return"},
        {SDL_SCANCODE_BACKSPACE,    "Backspace"},
        {SDL_SCANCODE_INSERT,       "Insert"},
        {SDL_SCANCODE_DELETE,       "Delete"},
        {SDL_SCANCODE_HOME,         "Home"},
        {SDL_SCANCODE_END,          "End"},
        {SDL_SCANCODE_PAGEUP,       "Page Up"},
        {SDL_SCANCODE_PAGEDOWN,     "Page Down"},
        {SDL_SCANCODE_KP_DIVIDE,    "Keypad /"},
        {SDL_SCANCODE_KP_MULTIPLY,  "Keypad *"},
        {SDL_SCANCODE_KP_MINUS,     "Keypad -"},
        {SDL_SCANCODE_KP_PLUS,      "Keypad +"},
        {SDL_SCANCODE_KP_ENTER,     "Keypad Enter"},
        {SDL_SCANCODE_KP_PERIOD,    "Keypad ."},
        {SDL_SCANCODE_KP_0,         "Keypad 0"},
        {SDL_SCANCODE_KP_1,         "Keypad 1"},
        {SDL_SCANCODE_KP_2,         "Keypad 2"},
        {SDL_SCANCODE_KP_3,         "Keypad 3"},
        {SDL_SCANCODE_KP_4,         "Keypad 4"},
        {SDL_SCANCODE_KP_5,         "Keypad 5"},
        {SDL_SCANCODE_KP_6,         "Keypad 6"},
        {SDL_SCANCODE_KP_7,         "Keypad 7"},
        {SDL_SCANCODE_KP_8,         "Keypad 8"},
        {SDL_SCANCODE_KP_9,         "Keypad 9"}
    };

    constexpr int LEN_SCANNAMES = sizeof(input::SDL_SCANNAMES)/sizeof(input::ScancodeNamePair);

    inline const char* get_softkey_name(Softkey key){ return SOFTKEY_NAME[(uint32_t)key]; }
    
    inline const char* get_scancode_name(SDL_Scancode t_code)
    {
        for(int i = 0; i < LEN_SCANNAMES; i++)  
        {
            if(SDL_SCANNAMES[i].code == t_code)
            {
                return SDL_SCANNAMES[i].name;
            }
        }

        return "Unknown Key";
    }
}