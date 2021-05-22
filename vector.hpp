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
typedef Vector2<float> Vector2f;

template <class T>
class Vector3
{
public:
    T x;
    T y;
    T z;

    Vector3(const T& t_x, const T& t_y, const T& t_z)
    {
        x = t_x;
        y = t_y;
        z = t_z;
    }
};

typedef Vector3<float> Vector3f;