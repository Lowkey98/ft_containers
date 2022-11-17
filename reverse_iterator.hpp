
#pragma once
#include "iterator_traits.hpp"
namespace ft {
    // template <class iterator>
    // class const_reverse_iterator;

    template <class iterator>
    class reverse_iterator
    {
        public:
            typedef iterator                                                iterator_type;
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
            explicit reverse_iterator(iterator_type it)
            {
                base_it = it;
            }
            template<class Iter>
                reverse_iterator(const reverse_iterator<Iter>& rev_it)
                {
                    base_it = rev_it.base();
                }
            iterator 	base() const { return base_it;}
            reference operator*() const
            {
                iterator tmp = base_it;
                return (*(--tmp));
            }
            pointer operator->() const
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
                const iterator	tmp = this->base_it - 1;

                return (tmp[-n]);
            }
    };
    template<class iterator>
        reverse_iterator<iterator> operator+(typename reverse_iterator<iterator>::difference_type n, reverse_iterator<iterator> &rhs){return rhs + n;}
    template <class Iterator>
        typename reverse_iterator<Iterator>::difference_type operator- (const reverse_iterator<Iterator>& lhs,
    const reverse_iterator<Iterator>& rhs)
    {
        return rhs.base() - lhs.base();
    }
}