#pragma once


template<typename T>
struct Color {
    Color( T w, T x, T y, T z ) : r(w), g(x), b(y), a(z) {}
    T   r, g, b, a;
};


