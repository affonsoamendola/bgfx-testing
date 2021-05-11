#pragma once

template <class T>
class Vector2
{
public:
    T x;
    T y;

    Vector2(const T& t_x, const T& t_y)
    {
        x = t_x;
        y = t_y;
    }
};

typedef Vector2<int> Vector2i;