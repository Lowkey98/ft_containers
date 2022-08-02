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
            value_type operator ++()
            {
                ptr++;
                return (*ptr);
            }
            bool operator !=(iterator &rhs)
            {
                return (ptr != rhs.get_ptr());
            }
            value_type *get_ptr() const{return ptr;}
        private:
            value_type *ptr;
    };
}