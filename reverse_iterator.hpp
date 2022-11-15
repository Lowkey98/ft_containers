
#pragma once
#include "iterator_traits.hpp"
namespace ft {
        template <class it>
    class const_reverse_iterator;

    template <class iterator>
    class reverse_iterator
    {
        public:
            typedef	typename iterator_traits<iterator>::iterator_category	iterator_category;
            typedef	typename iterator_traits<iterator>::value_type			value_type;
            typedef	typename iterator_traits<iterator>::pointer				pointer;
            typedef	typename iterator_traits<iterator>::reference			reference;
            typedef	typename iterator_traits<iterator>::difference_type		difference_type;

            // typedef Key									key_type;
            // typedef T									mapped_type;
            // typedef ft::pair<const Key, T>				value_type;
            // typedef Tree<Key, T>                        Tree;
            // typedef typename iterator::value_type       value_type;
            // typedef Node<value_type>					Node;
            // typedef iterator<Key, T>	                iterator;
        private:
            iterator base_it;
        public:
            reverse_iterator(){}
            reverse_iterator(const iterator &it)
            {
                base_it = it;
            }
            reverse_iterator(const reverse_iterator &r_it)
            {
                *this = r_it;
            }
            reverse_iterator &operator=(const reverse_iterator &r_it)
            {
                this->base_it = r_it.base();
                return *this;
            }
            template<class it>
            operator const_reverse_iterator<it>()
            {
                return const_reverse_iterator<it>(this->base());
            }
            iterator 	base() const { return base_it;}
            value_type	&operator*() const
            {
                iterator tmp = base_it;
                return (*(--tmp));
            }
            value_type * operator->() const
            {
                iterator tmp = base_it;

                return ((--tmp).operator->());
            }
            reverse_iterator operator--(){ return reverse_iterator(++base_it);}
            reverse_iterator operator++(){ return reverse_iterator(--base_it);}
            reverse_iterator operator--(int){ return reverse_iterator(base_it++);}
            reverse_iterator operator++(int){ return reverse_iterator(base_it--);}
            bool operator == (const reverse_iterator &rhs) const {return this->base() == rhs.base();}
            bool operator != (const reverse_iterator &rhs) const {return this->base() != rhs.base();}
            bool operator < (const reverse_iterator &rhs) const {return this->base() > rhs.base();}
            bool operator > (const reverse_iterator &rhs) const {return this->base() < rhs.base();}
            bool operator >= (const reverse_iterator &rhs) const {return this->base() <= rhs.base();}
            bool operator <= (const reverse_iterator &rhs) const {return this->base() >= rhs.base();}
    
            reverse_iterator operator+(difference_type n) const {return reverse_iterator(base_it - n);}
            reverse_iterator operator-(difference_type n) const {return reverse_iterator(base_it + n);}
            reverse_iterator operator-(const reverse_iterator &rhs) const {return reverse_iterator(this->base_it - rhs.base_it);}
            reverse_iterator operator+(const reverse_iterator &rhs) const {return reverse_iterator(this->base_it + rhs.base_it);}

            reverse_iterator operator+=(difference_type n)
            {
                this->base_it -= n;
                return *this;
            }
            reverse_iterator operator-=(difference_type n)
            {
                this->base_it += n;
                return *this;
            }
        reference operator[](difference_type n) const
		{
			iterator	tmp = this->base_iterator - 1;

			return (tmp[-n]);
		}
    };
    template<class iterator>
    reverse_iterator<iterator> operator+(typename reverse_iterator<iterator>::difference_type n, reverse_iterator<iterator> &rhs){return rhs + n;}
    template<class iterator>
    reverse_iterator<iterator> operator-(typename reverse_iterator<iterator>::difference_type n, reverse_iterator<iterator> &rhs){return rhs - n;}

    // ===============================================================================================//
    // ====================================<<<reverse_iterator>>>=========================================//
    // ===============================================================================================//
    template <class const_iterator>
    class const_reverse_iterator
    {
        public:
            typedef	typename iterator_traits<const_iterator>::iterator_category	iterator_category;
            typedef	typename iterator_traits<const_iterator>::value_type			value_type;
            typedef	typename iterator_traits<const_iterator>::pointer				pointer;
            typedef	typename iterator_traits<const_iterator>::reference			reference;
            typedef	typename iterator_traits<const_iterator>::difference_type		difference_type;

            // typedef Key									key_type;
            // typedef T									mapped_type;
            // typedef ft::pair<const Key, T>				value_type;
            // typedef Tree<Key, T>                        Tree;
            // typedef typename  const_iterator::value_type       value_type;
            // typedef Node<value_type>					Node;
            // typedef const_iterator<Key, T>	                const_iterator;
        private:
            const_iterator  base_it;
        public:
            const_reverse_iterator(){}
            const_reverse_iterator(const const_reverse_iterator &r_it)
            {
                *this = r_it;
            }
            const_reverse_iterator & operator=(const const_reverse_iterator &r_it)
            {
                this->base_it = r_it.base_it;
                return *this;
            }
            const_reverse_iterator(const const_iterator &it)
            {
                base_it = it;
            }
            const_iterator 	base() const { return base_it;}
            const value_type&	operator*()
            {
                const_iterator tmp = base_it;
                return (*(tmp--));
            }
            const value_type* operator->() const
            {
                const_iterator tmp = base_it;
                return ((--tmp).operator->());
            }
            const_reverse_iterator operator--(){ return const_reverse_iterator(++base_it);}
            const_reverse_iterator operator++(){ return const_reverse_iterator(--base_it);}
            const_reverse_iterator operator--(int){ return const_reverse_iterator(base_it++);}
            const_reverse_iterator operator++(int){ return const_reverse_iterator(base_it--);}
            bool operator == (const const_reverse_iterator &rhs) const {return this->base() == rhs.base();}
            bool operator != (const const_reverse_iterator &rhs) const {return this->base() != rhs.base();}
            bool operator < (const const_reverse_iterator &rhs) const {return this->base() > rhs.base();}
            bool operator > (const const_reverse_iterator &rhs) const {return this->base() < rhs.base();}
            bool operator >= (const const_reverse_iterator &rhs) const {return this->base() <= rhs.base();}
            bool operator <= (const const_reverse_iterator &rhs) const {return this->base() >= rhs.base();}
            const_reverse_iterator operator+(difference_type n) const {return const_reverse_iterator(base_it - n);}
            const_reverse_iterator operator-(difference_type n) const {return const_reverse_iterator(base_it + n);}
            const_reverse_iterator operator-(const const_reverse_iterator &rhs) const {return const_reverse_iterator(this->base_it - rhs.base_it);}
            const_reverse_iterator operator+(const const_reverse_iterator &rhs) const {return const_reverse_iterator(this->base_it + rhs.base_it);}
    };

}