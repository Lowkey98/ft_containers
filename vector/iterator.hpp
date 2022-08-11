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
            const_iterator(const value_type *v) :ptr(v)
            {
                // ptr = v;
            }
            const_iterator(const iterator &it) : ptr(it.base())
            {
                // *this = it;
            }
            const_iterator &operator=(const const_iterator &it)
            {
                ptr = it.base();
                return *this;
            }
            ~const_iterator(){};
            bool operator==(const const_iterator &it) {return (this->ptr == it.base());}
            bool operator!=(const const_iterator &it) {return (this->ptr != it.base());}
            bool operator<(const const_iterator &it) {return (this->ptr < it.base());}
            bool operator<=(const const_iterator &it) {return (this->ptr <= it.base());}
            bool operator>=(const const_iterator &it) {return (this->ptr >= it.base());}
            bool operator>(const const_iterator &it) {return (this->ptr > it.base());}
            const value_type operator*() {return *ptr;}
            const_iterator operator ++()
            {
                ptr++;
                return (*this);
            }
            const_iterator operator ++(int)
            {
                const_iterator tmp = *this;
                ptr++;
                return (tmp);
            }
            const_iterator operator --()
            {
                ptr--;
                return (*this);
            }
            const_iterator operator --(int)
            {
                const_iterator tmp = *this;
                ptr--;
                return (tmp);
            }
            const_iterator operator-(int n)
            {
                return(const_iterator((this->base() - n)));
            }
            const_iterator operator+(int n)
            {
                return(const_iterator(this->base() + n));
            }
            int     operator-(const_iterator &it) { return (*this->ptr - it.base());}
            const_iterator &operator+=(int n)
            {
                ptr += n;
                return (*this);
            }
            const_iterator &operator-=(int n)
            {
                ptr -= n;
                return (*this);
            }
            value_type & operator[](int n) {return ptr[n];}
            const value_type *base() const{return ptr;}
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
            reverse_iterator(iterator &it) : _base(it.base()) {}
            explicit reverse_iterator(iterator it)
            {
                _base = it;
            }
            value_type & operator*()
            {
                return(*(_base - 1));
            }
            reverse_iterator operator+(int n){return (reverse_iterator(base() - n));}
            reverse_iterator operator-(int n){return (reverse_iterator(base() + n));}
            bool operator==(const reverse_iterator &it) {return (this->ptr == it.base());}
            bool operator!=(const reverse_iterator &it) {return (this->ptr != it.base());}
            bool operator<(const reverse_iterator &it) {return (this->ptr < it.base());}
            bool operator<=(const reverse_iterator &it) {return (this->ptr <= it.base());}
            bool operator>=(const reverse_iterator &it) {return (this->ptr >= it.base());}
            bool operator>(const reverse_iterator &it) {return (this->ptr > it.base());}
            reverse_iterator &operator+=(int n)
            {
                _base-=n;
                return (*this);
            }
            reverse_iterator &operator-=(int n)
            {
                _base+=n;
                return (*this);
            }
            iterator base()const{return (_base);}

        private:
            iterator _base;
    };
    template <class T>
    class const_reverse_iterator
    {
        public:
            typedef T value_type;
            typedef ft::const_iterator<T> const_iterator;
            typedef ft::reverse_iterator<T> reverse_iterator;

        public:
            const_reverse_iterator(){};
            const_reverse_iterator(const reverse_iterator &it) : _base(it.base())
            {
                // *this = it;
            }
            const_reverse_iterator &operator=(const const_reverse_iterator &it)
            {
                _base = it.base();
                return *this;
            }
            explicit const_reverse_iterator(const_iterator it)
            {
                _base = it;
            }
            const value_type operator*()
            {
                return(*(_base - 1));
            }
            const_reverse_iterator operator+(int n){return (const_reverse_iterator(base() - n));}
            const_reverse_iterator operator-(int n){return (const_reverse_iterator(base() + n));}
            bool operator==(const const_reverse_iterator &it) {return (this->ptr == it.base());}
            bool operator!=(const const_reverse_iterator &it) {return (this->ptr != it.base());}
            bool operator<(const const_reverse_iterator &it) {return (this->ptr < it.base());}
            bool operator<=(const const_reverse_iterator &it) {return (this->ptr <= it.base());}
            bool operator>=(const const_reverse_iterator &it) {return (this->ptr >= it.base());}
            bool operator>(const const_reverse_iterator &it) {return (this->ptr > it.base());}
            const_reverse_iterator &operator+=(int n)
            {
                _base-=n;
                return (*this);
            }
            const_reverse_iterator &operator-=(int n)
            {
                _base+=n;
                return (*this);
            }
            const_iterator base()const {return (_base);}
        private:
            const_iterator _base;
    };
}