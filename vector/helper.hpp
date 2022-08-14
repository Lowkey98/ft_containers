#pragma once
#include "vector.hpp"
template <class it>
std::size_t distance(it b, it a)
{
    std::size_t distance = 0;
    for (it i = b; i != a; i--)
        distance++;
    return(distance);
}
template<bool, class T>
struct enable_if {};
 
template<class T>
struct enable_if<true, T> { typedef T type; };

template <class>
struct is_integral{static const bool value = true;};

template<>
struct is_integral<int>{static const bool value = false;};