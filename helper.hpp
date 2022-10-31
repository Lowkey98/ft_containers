#pragma once
// #include "vector/vector.hpp"
namespace ft
{
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
bool pred(int i , int j){return i == j;}
template <class InputIterator1, class InputIterator2, class BinaryPredicate>
bool equal (InputIterator1 first1, InputIterator1 last1,
              InputIterator2 first2, BinaryPredicate pred)
{
    while (first1 != last1)
    {
        if (!pred(*first1, *first2))
            return (false);
        first1++;
        first2++;
    }
    return (true);
}
template <class T1, class T2>
struct pair
{
    typedef T1 first_type;
    typedef T2 second_type;

    first_type first;
    second_type second;

    pair() : first(), second(){}

    template<class U, class V>
    pair (const pair<U,V>& pr) : first(pr.first), second(pr.second) {} 

    pair (const first_type& a, const second_type& b) :first(a), second(b) {}

    pair& operator= (const pair &pr)
    {
        this->first = pr.first;
        this->second = pr.second;
        return (*this);
    }
};
template <class T1, class T2>
bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{
    return ((lhs.first == rhs.first) && (lhs.second == rhs.second));
}
template <class T1, class T2>
bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{
    return (!(lhs == rhs));
}
template <class T1, class T2>
bool operator< (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{
    return ((lhs.first < rhs.first) || (lhs.first == rhs.first && lhs.second < rhs.second));
}

template <class T1, class T2>
bool operator> (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{
    return (rhs < lhs);
}

template <class T1, class T2>
bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{
    return (!(lhs > rhs));
}
template <class T1, class T2>
bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{
    return (rhs <= lhs);
}

template <class T1, class T2>
pair<T1,T2> make_pair (T1 x, T2 y)
{
    return (ft::pair<T1,T2>(x,y));
}
}