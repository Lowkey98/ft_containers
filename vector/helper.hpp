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