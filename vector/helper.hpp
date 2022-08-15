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

template <class InputIterator1, class InputIterator2>
bool equal (InputIterator1 first1, InputIterator1 last1,
            InputIterator2 first2)
{
    while (first1 != last1)
    {
        if (*first1 != *first2)
            return (false);
        first1++;
        first2++;
    }
    return (true);
}