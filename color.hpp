#pragma once

struct Color4bs
{
    uint32_t value;

    virtual uint8_t r() = 0;
    virtual uint8_t g() = 0;
    virtual uint8_t b() = 0;
    virtual uint8_t a() = 0;
};

struct Color4rgba : Color4bs
{
    uint8_t r() override { return (value & 0xFF000000) >> (3 * 8); }
    uint8_t g() override { return (value & 0x00FF0000) >> (2 * 8); }
    uint8_t b() override { return (value & 0x0000FF00) >> (1 * 8); }
    uint8_t a() override { return (value & 0x000000FF)           ; }
};

struct Color4abgr : Color4bs
{
    uint8_t r() override { return (value & 0x000000FF)           ; }
    uint8_t g() override { return (value & 0x0000FF00) >> (1 * 8); }
    uint8_t b() override { return (value & 0x00FF0000) >> (2 * 8); }
    uint8_t a() override { return (value & 0xFF000000) >> (3 * 8); }
};

namespace Color
{
    inline Color4abgr rgba_to_abgr(const Color4rgba& rgba)
    {
        Color4abgr out;

        out.value |= (rgba.value & 0x000000FF) << (3*8);
        out.value |= (rgba.value & 0x0000FF00) << (1*8);
        out.value |= (rgba.value & 0x00FF0000) >> (1*8);
        out.value |= (rgba.value & 0xFF000000) >> (3*8);

        return out;
    }   

    inline Color4rgba abgr_to_rgba(const Color4abgr& abgr)
    {
        Color4rgba out;

        out.value |= (abgr.value & 0x000000FF) << (3*8);
        out.value |= (abgr.value & 0x0000FF00) << (1*8);
        out.value |= (abgr.value & 0x00FF0000) >> (1*8);
        out.value |= (abgr.value & 0xFF000000) >> (3*8);

        return out;
    }
}   

struct Color4f
{
    float r;
    float g;
    float b;
    float a;

    Color4rgba to_Color4rgba() const
    {
        Color4rgba out;

        out.value = 0;

        out.value |= ((int)(r * 255.0f)) << (3 * 8);  //0xRR000000
        out.value |= ((int)(g * 255.0f)) << (2 * 8);  //0xRRGG0000
        out.value |= ((int)(b * 255.0f)) << (1 * 8);  //0xRRGGBB00
        out.value |=  (int)(a * 255.0f);              //0xRRGGBBAA

        return out;
    }

    static Color4f from_Color4rgba(const Color4rgba& in)
    {
        Color4f out = {0};

        out.r = (float)((in.value >> (3 * 8)) & 0xFF) / 255.0f; //0xRRGGBBAA >>-> 0x??????RR &-> 0x000000RR -> float
        out.g = (float)((in.value >> (2 * 8)) & 0xFF) / 255.0f; //0xRRGGBBAA >>-> 0x????RRGG &-> 0x000000GG -> float
        out.b = (float)((in.value >> (1 * 8)) & 0xFF) / 255.0f; //0xRRGGBBAA >>-> 0x??RRGGBB &-> 0x000000BB -> float
        out.a = (float)( in.value             & 0xFF) / 255.0f; //0xRRGGBBAA                 &-> 0x000000AA -> float
    
        return out;
    }
};