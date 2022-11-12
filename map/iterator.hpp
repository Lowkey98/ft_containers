#pragma once
#include "map.hpp"
#include "../helper.hpp"
#include "avl.hpp"
#include <functional>

// struct Foo {
// {
//     int     a;
//     Foo(void) : a(10) { }
//     operator int()
//     {
//         return (a);
//     }
// };

// conversion function

// Foo     obj;
// int     x;

// x = obj; // x = obj.operator int();
namespace ft
{

template <class Key,class T, class Tree>
class const_iterator;

template <class Key,class T, class Tree>
class iterator
{
	public:
		typedef ft::pair<const Key,T>               value_type;
		typedef std::bidirectional_iterator_tag     iterator_category;
		typedef ptrdiff_t                           difference_type;
		typedef value_type*                         pointer;
		typedef value_type&                         reference;
	private:
		typedef Node<value_type>                    Node;
	private:
		Tree    *_tree;
		Node    *_current;
	public:
		iterator()
		{

		}
		iterator(const iterator &it)
		{
			*this = it;
		}

		iterator(Tree *tr, Node *cr): _tree(tr), _current(cr)
		{
			// (void)comp;
		}
		iterator &operator=( const iterator &it)
		{
			_tree = it._tree;
			_current = it._current;
			return *this;
		}
		~iterator(){}

		// template <class Key,class T, class Tree>
		operator const_iterator<Key, T, Tree>() const
		{
			return const_iterator<Key, T, Tree>(this->_tree, this->_current);
		}
		pointer operator->() const
		{
			return (&(_current->data));
		}
		reference operator*() const
		{
			return (_current->data);
		}
		Node    *current()const {return _current;}
		iterator operator++()
		{
			Node *tmp = _current;
			_current = _tree->findSuccessorIterative(_current);
			return (iterator(_tree, tmp));
		}
		iterator operator++(int)
		{
			_current = _tree->findSuccessorIterative(_current);
			return (iterator(_tree, _current));
		}
		iterator operator--()
		{
			Node *tmp = _current;
			_current = _tree->findPredecessorIterative(_current);
			return (iterator(_tree, tmp));
		}
		iterator operator--(int)
		{
			_current = _tree->findPredecessorIterative(_current);
			return (iterator(_tree, _current));
		} 

};

template<class Key, class T, class Tree>
bool operator!=(const iterator<Key,T, Tree> & lhs, const iterator<Key,T, Tree> & rhs)
{
    (void)lhs;
    (void)rhs;
	// return lhs.current()->data.first != rhs.current()->data.first;
    return 1;
}

template<class Key, class T, class Tree>
bool operator==(const iterator<Key,T, Tree> & lhs, const iterator<Key,T, Tree> & rhs)
{
    (void)lhs;
    (void)rhs;
    return 0;
	// return lhs.current()->data.first  == rhs.current()->data.first ;
}

// template<class Key, class T, class Tree>
// bool operator==(const const_iterator<Key,T, Tree> & lhs, const iterator<Key,T, Tree> & rhs)
// {
//     // lhs = const_iterator();
// 	return lhs.current() == rhs.current();
// }


// ===============================================================================================//
// ====================================<<<const_iterator>>>=========================================//
// ===============================================================================================//
template <class Key,class T, class Tree>
class const_iterator
{
	public:
		typedef ft::pair<const Key,T>               value_type;
		typedef std::bidirectional_iterator_tag     iterator_category;
		typedef ptrdiff_t                           difference_type;
		typedef const value_type*                         pointer;
		typedef const value_type&                         reference;
	private:
		typedef Node<value_type>                    Node;
	private:
		const Tree    *_tree;
		const Node    *_current;
	public:
		const_iterator()
		{
            _tree = NULL;
            _current = NULL;
		}
		const_iterator(const const_iterator &it)
		{
			*this = it;
		}

		const_iterator(const Tree *tr,const Node * cr)
		{
            this->_tree = tr;
            this->_current = cr;
			// (void)comp;
		}
		const_iterator &operator=(const const_iterator &it)
		{
			_tree = it._tree;
			_current = it._current;
			return *this;
		}
		~const_iterator(){}
		operator const_iterator()
		{
			return const_iterator(this->_tree, this->_current);
		}
		pointer operator->() const
		{
			return (&(_current->data));
		}

		reference operator*()
		{
			return (_current->data);
		}
		Node    *current() const {return _current;}
		const_iterator operator++()
		{
			const Node *tmp = _current;
			_current = _tree->findSuccessorIterative(_current);
			return (const_iterator(_tree, tmp));
		}
		const_iterator operator++(int)
		{
			_current = _tree->findSuccessorIterative(_current);
			return (const_iterator(_tree, _current));
		}
		const_iterator operator--()
		{
			const Node *tmp = _current;
			_current = _tree->findPredecessorIterative(_current);
			return (const_iterator(_tree, tmp));
		}
		const_iterator operator--(int)
		{
			_current = _tree->findPredecessorIterative(_current);
			return (const_iterator(_tree, _current));
		} 

};
template<class Key, class T, class Tree>
bool operator!=(const const_iterator<Key,T, Tree> & lhs, const const_iterator<Key,T, Tree> & rhs)
{
    (void)lhs;
    (void)rhs;
	// return lhs.current()->data.first  != rhs.current()->data.first ;
    return 1;
}
template<class Key, class T, class Tree>
bool operator==(const const_iterator<Key,T, Tree> & lhs, const const_iterator<Key,T, Tree> & rhs)
{
    (void)lhs;
    (void)rhs;
	// return lhs.current()->data.first  != rhs.current()->data.first ;
    return 1;
}
// ===============================================================================================//
// ====================================<<<reverse_iterator>>>=========================================//
// ===============================================================================================//
// #include "../iterator_traits.hpp"
template <class it>
class const_reverse_iterator;

template <class iterator>
class reverse_iterator
{
	public:
		// typedef Key									key_type;
		// typedef T									mapped_type;
		// typedef ft::pair<const Key, T>				value_type;
		// typedef Tree<Key, T>                        Tree;
		typedef typename iterator::value_type       value_type;
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
		value_type	&operator*()
		{
			iterator tmp = base_it;
			return (*(tmp--));
		}
		value_type * operator->() const
		{
            iterator tmp = base_it;

			return ((tmp--).operator->());
		}
		reverse_iterator operator--(){ return reverse_iterator(++base_it);}
		reverse_iterator operator++(){ return reverse_iterator(--base_it);}
		reverse_iterator operator--(int){ return reverse_iterator(base_it++);}
		reverse_iterator operator++(int){ return reverse_iterator(base_it--);}
};

template<class Iterator>
bool operator== (const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
{
    (void)lhs;
    (void)rhs;
    return 1;
	// return (lhs.base() == rhs.base());
}
template<class Iterator>
bool operator!= (const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
{
    (void)lhs;
    (void)rhs;
    return 1;
	// return (lhs.base() != rhs.base());
}

// ===============================================================================================//
// ====================================<<<reverse_iterator>>>=========================================//
// ===============================================================================================//
template <class iterator>
class const_reverse_iterator
{
	public:
		// typedef Key									key_type;
		// typedef T									mapped_type;
		// typedef ft::pair<const Key, T>				value_type;
		// typedef Tree<Key, T>                        Tree;
		typedef typename  iterator::value_type       value_type;
		// typedef Node<value_type>					Node;
		// typedef iterator<Key, T>	                iterator;
	private:
		iterator base_it;
	public:
		const_reverse_iterator(){}
		const_reverse_iterator(const iterator &it)
		{
			base_it = it;
		}
        const_reverse_iterator & operator=(const const_reverse_iterator &r_it)
        {
            this->base_it = r_it.base_it;
            return *this;
        }
		iterator 	base() const { return base_it;}
		value_type&	operator*()
		{
			iterator tmp = base_it;
			return (*(tmp--));
		}
		const value_type * operator->() const
		{
			return (base_it.operator->());
		}
		const_reverse_iterator operator--(){ return const_reverse_iterator(++base_it);}
		const_reverse_iterator operator++(){ return const_reverse_iterator(--base_it);}
		const_reverse_iterator operator--(int){ return const_reverse_iterator(base_it++);}
		const_reverse_iterator operator++(int){ return const_reverse_iterator(base_it--);}
};

template<class Iterator>
bool operator== (const const_reverse_iterator<Iterator> &lhs, const const_reverse_iterator<Iterator> &rhs)
{
    (void)lhs;
    (void)rhs;
    return 1;
	// return (lhs.base() == rhs.base());
}
template<class Iterator>
bool operator!= (const const_reverse_iterator<Iterator> &lhs, const const_reverse_iterator<Iterator> &rhs)
{
    (void)lhs;
    (void)rhs;
    return 1;
	// return (lhs.base() != rhs.base());
}
template<class Iterator>
bool operator!= (const const_reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
{
    (void)lhs;
    (void)rhs;
    return 1;
	// return (lhs.base() != rhs.base());
}
}