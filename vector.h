#pragma once

template<typename T>
struct Vector {
    Vector( T a, T b, T c ) : x(a), y(b), z(c) {}
    T   x, y, z;
};

template<typename T>
T dot( const Vector<T> &a, const Vector<T> &b ) {
    return a.x*b.x + a.y*b.y + a.z*b.z;
}


