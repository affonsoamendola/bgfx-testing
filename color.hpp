#pragma once

typedef uint32_t Color4b; //4-bytes RGBA format 0xRRGGBBAA

struct Color4f
{
    float r;
    float g;
    float b;
    float a;

    Color4b to_Color4b() const
    {
        Color4b out = 0;

        out |= ((int)(r * 255.0f)) << (3 * 8);  //0xRR000000
        out |= ((int)(g * 255.0f)) << (2 * 8);  //0xRRGG0000
        out |= ((int)(b * 255.0f)) << 8;  //0xRRGGBB00
        out |= (int)(a * 255.0f);           //0xRRGGBBAA

        return out;
    }

    static Color4f from_Color4b(const Color4b& in)
    {
        Color4f out = {0};

        out.r = (float)((in >> 3 * 8) & 0xFF) / 255.0f; //0xRRGGBBAA >>-> 0x??????RR &-> 0x000000RR -> float
        out.g = (float)((in >> 2 * 8) & 0xFF) / 255.0f; //0xRRGGBBAA >>-> 0x????RRGG &-> 0x000000GG -> float
        out.b = (float)((in >> 1 * 8) & 0xFF) / 255.0f; //0xRRGGBBAA >>-> 0x??RRGGBB &-> 0x000000BB -> float
        out.a = (float)( in           & 0xFF) / 255.0f; //0xRRGGBBAA                 &-> 0x000000AA -> float
    
        return out;
    }
};