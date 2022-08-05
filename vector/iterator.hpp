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
            iterator(){};
            iterator(value_type *v)
            {
                ptr = v;
            }
            // iterator(const iterator &it)
            // {
            //     std::cout << "Copy constructor called" << std::endl;
            //     *this = it;
            // }
            // iterator &operator=(const iterator &it)
            // {
            //     std::cout << "=operator" << std::endl;
            //     ptr = it.get_ptr();
            //     return *this;
            // }
            value_type& operator *() {return *ptr;}
            value_type operator ++(int n)
            {
                (void)n;
                ptr++;
                return (*ptr);
            }
            value_type operator --(int n)
            {
                (void)n;
                ptr--;
                return (*ptr);
            }
            value_type *get_ptr() const{return ptr;}
            iterator operator-(int n)
            {
                return(iterator(this->get_ptr() - n));
            }
            iterator operator+(int n)
            {
                return(iterator(this->get_ptr() + n));
            }

        private:
            value_type *ptr;
    };

    template <class it>
    bool operator !=(const it &lhs, const it &rhs)
    {
        return (lhs.get_ptr() != rhs.get_ptr());
    }
    // template <class it>
    // bool operator ==(const it &lhs, const it &rhs)
    // {
    //     return (lhs.get_ptr() == rhs.get_ptr());
    // }
}