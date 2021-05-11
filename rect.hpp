#pragma once

template <class T>
struct Rect4
{
    T x;
    T y;
    T w;
    T h;

    Rect4<T> translate(const T offset_x, const T offset_y) const
    {
        Rect4<T> changed;

        changed.x = this.x + offset_x;
        changed.y = this.y + offset_y;
        changed.w = this.w;
        changed.h = this.h;
            
        return changed; 
    }

    bool inside(const T t_x, const T t_y) const
    {
        return (t_x > x && t_x <= x + w &&
                t_y > y && t_y <= y + h );
    }

    T right() const { return x + w; }
    T up() const { return y; }
    T left() const { return x; }
    T down() const { return y + h; }
    
    T* as_array() { return &x; }
    
    static Rect4<T> from_array(const T* t_array)
    {
        Rect4<T> new_rect;

        new_rect.x = t_array[0];
        new_rect.y = t_array[1];
        new_rect.w = t_array[2];
        new_rect.h = t_array[3];

        return new_rect;
    }
};

typedef Rect4<float> Rect4f;
typedef Rect4<int> Rect4i;