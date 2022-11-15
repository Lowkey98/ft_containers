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
class const_map_iterator;

template <class Key,class T, class Tree>
class map_iterator
{
	public:
		typedef ft::pair<const Key,T>               value_type;
		typedef std::bidirectional_iterator_tag     iterator_category;
		typedef ptrdiff_t                           difference_type;
		typedef value_type*                         pointer;
		typedef value_type&                         reference;
	private:
		typedef Node<value_type>                    Node;
	public:
		Tree    *_tree;
		Node    *_current;
	public:
		map_iterator() :_tree(NULL), _current(NULL)
		{
		}
		map_iterator(const map_iterator &it) :_tree(it._tree), _current(it._current)
		{
			// exit(0);
			// std::cout << "VALUE" << (_current->data.first) << std::endl;
			// *this = it;
		}

		map_iterator(Tree *tr, Node *cr): _tree(tr), _current(cr)
		{
			// (void)comp;
		}
		map_iterator &operator=(  map_iterator const &it)
		{
			_tree = it._tree;
			_current = it._current;
			return *this;
		}
		~map_iterator(){}

		// template <class Key,class T, class Tree>
		operator const_map_iterator<Key, T, Tree>() const
		{
			return const_map_iterator<Key, T, Tree>(this->_tree, this->_current);
		}
		pointer operator->() const
		{
			return (&(_current->data));
		}
		reference operator*() const
		{
			return (_current->data);
		}
		// Node    *current()const {return _current;}
		map_iterator operator++()
		{
			// Node *tmp = _current;
			// _current = _tree->findSuccessorIterative(_current);
			// return (map_iterator(_tree, tmp));
			this->_current = _tree->findSuccessorIterative(this->_current);
			return (*this);
		}
		map_iterator operator++(int)
		{
			// Node *tmp = _current;
			// _current = _tree->findPredecessorIterative(_current);
			// return (map_iterator(_tree, tmp));
			map_iterator tmp = *this;
			_current = _tree->findSuccessorIterative(_current);
			return (tmp);
		}
		map_iterator operator--()
		{
			this->_current = _tree->findPredecessorIterative(this->_current);
			return (*this);
		}
		map_iterator operator--(int)
		{
			map_iterator tmp = *this;
			this->_current = _tree->findPredecessorIterative(this->_current);
			return (tmp);
		}
        bool operator == (const map_iterator &rhs)
        {
            // return 0;
			// std::cout << (this->_current == rhs._current);
            return (this->_current == rhs._current);
        }
        bool operator != (const map_iterator &rhs)
        {
            // return 1;
            return (this->_current != rhs._current);
        }


};

// template<class Key, class T, class Tree>
// bool operator!=(const map_iterator<Key,T, Tree> & lhs, const map_iterator<Key,T, Tree> & rhs)
// {
//     (void)lhs;
//     (void)rhs;
// 	// return lhs.current()->data.first != rhs.current()->data.first;
//     return 1;
// }

// template<class Key, class T, class Tree>
// bool operator==(const map_iterator<Key,T, Tree> & lhs, const map_iterator<Key,T, Tree> & rhs)
// {
//     (void)lhs;
//     (void)rhs;
//     return 0;
// 	// return lhs.current()  == rhs.current() ;
// }

// template<class Key, class T, class Tree>
// bool operator==(const const_map_iterator<Key,T, Tree> & lhs, const map_iterator<Key,T, Tree> & rhs)
// {
//     // lhs = const_map_iterator();
// 	return lhs.current() == rhs.current();
// }


// ===============================================================================================//
// ====================================<<<const_map_iterator>>>=========================================//
// ===============================================================================================//
template <class Key,class T, class Tree>
class const_map_iterator
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
		const_map_iterator()
		{
            _tree = NULL;
            _current = NULL;
		}
		const_map_iterator(const const_map_iterator &it)
		{
			*this = it;
		}

		const_map_iterator(const Tree *tr,const Node * cr)
		{
            this->_tree = tr;
            this->_current = cr;
			// (void)comp;
		}
		const_map_iterator &operator=(const const_map_iterator &it)
		{
			_tree = it._tree;
			_current = it._current;
			return *this;
		}
		~const_map_iterator(){}
		operator const_map_iterator()
		{
			return const_map_iterator(this->_tree, this->_current);
		}
		pointer operator->() const
		{
			return (&(_current->data));
		}

		reference operator*() const
		{
			return (_current->data);
		}
		Node    *current() const {return _current;}
		const_map_iterator operator++()
		{
			// Node *tmp = _current;
			// _current = _tree->findSuccessorIterative(_current);
			// return (const_map_iterator(_tree, tmp));
			this->_current = _tree->findSuccessorIterative(this->_current);
			return (*this);
		}
		const_map_iterator operator++(int)
		{
			// Node *tmp = _current;
			// _current = _tree->findPredecessorIterative(_current);
			// return (const_map_iterator(_tree, tmp));
			const_map_iterator tmp = *this;
			_current = _tree->findSuccessorIterative(_current);
			return (tmp);
		}
		const_map_iterator operator--()
		{
			this->_current = _tree->findPredecessorIterative(this->_current);
			return (*this);
		}
		const_map_iterator operator--(int)
		{
			const_map_iterator tmp = *this;
			this->_current = _tree->findPredecessorIterative(this->_current);
			return (tmp);
		}
bool operator!=(const const_map_iterator<Key,T, Tree> & rhs)
{
    // (void)rhs;
	return this->_current  != rhs._current;
}
bool operator==(const const_map_iterator<Key,T, Tree> & rhs)
{
	return this->_current  == rhs._current;
	// return lhs.current()->data.first  != rhs.current()->data.first ;
    // return 0;
}
};
// ===============================================================================================//
// ====================================<<<reverse_iterator>>>=========================================//
// ===============================================================================================//
// #include "../iterator_traits.hpp"
}