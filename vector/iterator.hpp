#pragma once
// #include "vector.hpp"


namespace ft
{
    template <class T>
    class const_iterator;

    template  <class T>
    class iterator
    {
        public:
            typedef T value_type;
            typedef T* pointer;
            typedef T& reference;
        public:
            iterator(){};
            iterator(value_type *v)
            {
                this->ptr = v;
            }
            iterator(const iterator &it)
            {
                *this = it;
            }
            iterator &operator=(const iterator &it)
            {
                this->ptr = it.base();
                return *this;
            }
            ~iterator(){};
            bool operator==(const iterator &it) {return (this->ptr == it.base());}
            bool operator!=(const iterator &it) {return (this->ptr != it.base());}
            bool operator<(const iterator &it) {return (this->ptr < it.base());}
            bool operator<=(const iterator &it) {return (this->ptr <= it.base());}
            bool operator>=(const iterator &it) {return (this->ptr >= it.base());}
            bool operator>(const iterator &it) {return (this->ptr > it.base());}
            
            template <class it>
            operator const_iterator<it>()
            {
                return const_iterator<it>();
            }
            reference operator*() {return *ptr;}
            pointer operator->() {return ptr;}
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
            reference operator[](int n) {return ptr[n];}
            pointer base() const{return ptr;}

                

        private:
            pointer ptr;
    };
    template<class T>
    iterator<T> operator+(int n, const iterator<T> &rhs)
    {
        return rhs + n;
    }





    template  <class T>
    class const_iterator
    {
        public:
            typedef T   value_type;
            typedef const T*  pointer;
            typedef const T&  reference;
        public:
            const_iterator(){};
            const_iterator(value_type *v)
            {
                ptr = v;
            }
            const_iterator(const const_iterator &it)
            {
                *this = it;
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
            reference operator*() {return *ptr;}
            pointer operator->() {return ptr;}
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
                return(const_iterator(this->base() - n));
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
            reference operator[](int n) {return ptr[n];}
            value_type *base() const{return ptr;}
            

        private:
            value_type *ptr;
    };
    template<class T>
    const_iterator<T> operator+(int n, const const_iterator<T> &rhs)
    {
        return rhs + n;
    }
    // template <class it>
    // bool operator !=(const it &lhs, const it &rhs)
    // {
    //     return (lhs.get_ptr() != rhs.get_ptr());
    // }
    // template <class it>
    // bool operator ==(const it &lhs, const it &rhs)
    // {
    //     return (lhs.get_ptr() == rhs.get_ptr());
    // }

}