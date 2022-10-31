#pragma once
#include <functional>
#include "../helper.hpp"
#include "iterator.hpp"
#include <vector>
namespace ft
{
	template < class Key,                                     // map::key_type
			class T,                                       // map::mapped_type
			class Compare = std::less<Key>,                     // map::key_compare
			class Alloc = std::allocator<pair<const Key,T> >    // map::allocator_type
			> class map
	{
		public:
			typedef Key								key_type;
			typedef T								mapped_type;
			typedef Compare							key_compare;
			typedef Alloc							allocator_type;
			typedef pair<Key,T>						value_type;
            typedef iterator<Key,T>					iterator;
			typedef Tree<Key,T, Compare, Alloc>		Tree;
			typedef size_t							size_type;
            typedef Node<value_type>				Node;
		private:
			allocator_type		_allocator;
			size_type			_size;
			Tree				_tree;
        // private:

		public:
			explicit map (const key_compare& comp = key_compare(),
              const allocator_type& alloc = allocator_type()) : _allocator(),  _size(0), _tree()
			  {
                //temp 
                (void)comp;
                (void)alloc;
              }
			size_type count (const key_type& k) const
            {
                if (_tree.search(_tree.root, k))
                    return (1);
                else
                    return (0);
            }
            iterator find (const key_type& k)
            {
                return (iterator(_tree, _tree.search(_tree.root, k)));
            }
            std::pair<iterator,bool> insert (const value_type& val)
            {
                if (_tree.search(val.first))
                    return std::make_pair(iterator(&_tree, NULL), false);
                _tree.insert(val);
                return std::make_pair(iterator(&_tree, _tree.min_value_node()), true);
            }
            template <class InputIterator>
            // void insert (InputIterator first, InputIterator last)
            // {
            //     while (first != last)
            //     {
            //         insert(*first);
            //         first++;
            //     }
            // }
            size_type erase (const key_type& k)
            {
                if (_tree.search(_tree.root, k))
                {
                    // _tree.delete_node(_tree.root, k);
                    _size--;
                    return (1);
                }
                return (0);
            }
            void erase (iterator position)
            {
                erase((*position).first);
            }
            void erase (iterator first, iterator last)
            {
                std::vector<key_type> v1;
                while (first != last)
                {
                    v1.push_back((*first).first);
                    // erase(first);
                    first++;
                }
                for (typename std::vector<key_type>::iterator it = v1.begin(); it != v1.end(); it++)
                    erase(*it);
                // {}

            }

            iterator begin()
            {
                return (iterator(&_tree, _tree.min_value_node()));
            }
            iterator end()
            {
                return (iterator(&_tree, _tree.dummy_node));
            }
	};
}