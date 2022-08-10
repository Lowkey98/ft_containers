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
                *this = it;
            }
            iterator &operator=(const iterator &it)
            {
                ptr = it.base();
                return *this;
            }
            ~iterator(){};
            bool operator==(const iterator &it) {return (this->ptr == it.base());}
            bool operator!=(const iterator &it) {return (this->ptr != it.base());}
            bool operator<(const iterator &it) {return (this->ptr < it.base());}
            bool operator<=(const iterator &it) {return (this->ptr <= it.base());}
            bool operator>=(const iterator &it) {return (this->ptr >= it.base());}
            bool operator>(const iterator &it) {return (this->ptr > it.base());}
            value_type& operator*() {return *ptr;}
            value_type* operator->() {return ptr;}
            iterator operator ++()
            {
                ptr++;
                return (*this);
            }
            iterator operator ++(int)
            {
                iterator tmp = *this;
                ptr++;
                return (tmp);
            }
            iterator operator --()
            {
                ptr--;
                return (*this);
            }
            iterator operator --(int)
            {
                iterator tmp = *this;
                ptr--;
                return (tmp);
            }
            iterator operator-(int n)
            {
                return(iterator(this->base() - n));
            }
            iterator operator+(int n)
            {
                return(iterator(this->base() + n));
            }
            int     operator-(iterator &it) { return (*this->ptr - it.base());}
            iterator &operator+=(int n)
            {
                ptr += n;
                return (*this);
            }
            iterator &operator-=(int n)
            {
                ptr -= n;
                return (*this);
            }
            value_type & operator[](int n) {return ptr[n];}
            value_type *base() const{return ptr;}
            

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
    template <class T>
    class reverse_iterator
    {
        public:
            typedef T value_type;
            typedef ft::iterator<T> iterator;
        public:
            reverse_iterator(){};
            // reverse_iterator(value_type *ptr){this->ptr = ptr;};
            explicit reverse_iterator(iterator it)
            {
                _base = it;
            }
            value_type & operator*()
            {

                return(*(_base - 1));
            }
            iterator base(){return (_base);}
        private:
            iterator _base;
    };
}