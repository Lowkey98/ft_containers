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
            iterator(const iterator &it)
            {
                std::cout << "Copy constructor called" << std::endl;
                *this = it;
            }
            iterator &operator=(const iterator &it)
            {
                std::cout << "=operator" << std::endl;
                ptr = it.get_ptr();
                return *this;
            }
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

    template <class T>
    class const_iterator
    {
        public:
            typedef T value_type;
            typedef ft::iterator<T> iterator;
        public:
            const_iterator(){};
            const_iterator(const_iterator &const_it)
            {
                *this = const_it;
            }
            const_iterator(iterator &it)
            {
                *this = it;
            }
            const_iterator& operator = (const const_iterator &const_it)
            {
                this->ptr = const_it.get_ptr();
                return (*this);
            }
            // template<class iterator>
            const_iterator &operator = (const iterator &it)
            {
                this->ptr = it.get_ptr();
                return (*this);
            }
            const_iterator(const value_type *v){ptr = v;};
            const value_type& operator *() {return *ptr;}
            const value_type *get_ptr() const{return ptr;}
        private:
            const value_type *ptr;
    };
}