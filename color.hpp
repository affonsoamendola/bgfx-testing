#pragma once

typedef uint32_t Color32rgba; //RGBA format 0xRRGGBBAA

struct Color4f
{
    float r;
    float g;
    float b;
    float a;

    Color32rgba to_Color32rgba()
    {
        Color32rgba out = 0;

        out |= (int)(r * 255.0f) << 3 * 8;  //0xRR000000
        out |= (int)(g * 255.0f) << 2 * 8;  //0xRRGG0000
        out |= (int)(b * 255.0f) << 1 * 8;  //0xRRGGBB00
        out |= (int)(a * 255.0f);           //0xRRGGBBAA

        return out;
    }
};