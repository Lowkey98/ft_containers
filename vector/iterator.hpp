#pragma once
#include "vector.hpp"
namespace ft
{
    template  <class T>
    class iterator
    {
        public:
            typedef T value_type;
        
        public:
            iterator(value_type *v)
            {
                ptr = v;
            }
            value_type operator *() {return *ptr;}
            value_type operator ++(int n)
            {
                (void)n;
                ptr++;
                return (*ptr);
            }

            value_type *get_ptr() const{return ptr;}
        private:
            value_type *ptr;
    };
    template <class iterator>
    bool operator !=(const iterator &lhs, const iterator &rhs)
    {
        return (lhs.get_ptr() != rhs.get_ptr());
    }
}