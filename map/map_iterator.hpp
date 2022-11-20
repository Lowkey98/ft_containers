#pragma once
#include "../helper.hpp"
#include "avl.hpp"
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
			map_iterator() :_tree(NULL), _current(NULL){}
			map_iterator(const map_iterator &it) :_tree(it._tree), _current(it._current){}
			map_iterator(Tree *tr, Node *cr) :_tree(tr), _current(cr){}
			map_iterator &operator=(const map_iterator &it)
			{
				_tree = it._tree;
				_current = it._current;
				return *this;
			}
			~map_iterator(){}
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
			map_iterator operator++()
			{
				this->_current = _tree->find_successor(this->_current);
				return (*this);
			}
			map_iterator operator++(int)
			{
				map_iterator tmp = *this;
				_current = _tree->find_successor(_current);
				return (tmp);
			}
			map_iterator operator--()
			{
				this->_current = _tree->find_predecessor(this->_current);
				return (*this);
			}
			map_iterator operator--(int)
			{
				map_iterator tmp = *this;
				this->_current = _tree->find_predecessor(this->_current);
				return (tmp);
			}
			bool operator == (const map_iterator &rhs) {return this->_current == rhs._current;}
			bool operator != (const map_iterator &rhs) {return this->_current != rhs._current;}
	};

	template <class Key,class T, class Tree>
	class const_map_iterator
	{
		public:
			typedef ft::pair<const Key,T>				value_type;
			typedef std::bidirectional_iterator_tag		iterator_category;
			typedef ptrdiff_t							difference_type;
			typedef const value_type*					pointer;
			typedef const value_type&					reference;
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
			}
			const_map_iterator &operator=(const const_map_iterator &it)
			{
				_tree = it._tree;
				_current = it._current;
				return *this;
			}
			~const_map_iterator(){}
			operator const_map_iterator(){return const_map_iterator(this->_tree, this->_current);}
			pointer operator->() const {return &(_current->data);}
			reference operator*() const {return (_current->data);}
			Node    *current() const {return _current;}
			const_map_iterator operator++()
			{
				this->_current = _tree->find_successor(this->_current);
				return (*this);
			}
			const_map_iterator operator++(int)
			{
				const_map_iterator tmp = *this;
				_current = _tree->find_successor(_current);
				return (tmp);
			}
			const_map_iterator operator--()
			{
				this->_current = _tree->find_predecessor(this->_current);
				return (*this);
			}
			const_map_iterator operator--(int)
			{
				const_map_iterator tmp = *this;
				this->_current = _tree->find_predecessor(this->_current);
				return (tmp);
			}
			bool operator!=(const const_map_iterator& rhs){return this->_current  != rhs._current;}
			bool operator==(const const_map_iterator& rhs){return this->_current  == rhs._current;}
	};
}