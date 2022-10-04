#pragma once
#include <functional>
#include "../helper.hpp"
#include "iterator.hpp"
namespace ft
{
	template < class Key,                                     // map::key_type
			class T,                                       // map::mapped_type
			class Compare = std::less<Key>,                     // map::key_compare
			class Alloc = std::allocator<pair<const Key,T> >    // map::allocator_type
			> class map
	{
		public:
			typedef Key                     key_type;
			typedef T                       mapped_type;
			typedef Compare                 key_compare;
			typedef Alloc                   allocator_type;
			typedef pair<Key,T>   value_type;
            typedef iterator<Key,T>             iterator;
			typedef Tree<Key,T>		Tree;
			typedef size_t					size_type;
            typedef Node<value_type>        Node;
		public:
			explicit map (const key_compare& comp = key_compare(),
              const allocator_type& alloc = allocator_type()) : _allocator(), _tree() , _size(0)
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
                Node *node = _tree.search(_tree.root, val);
                if (node)
                    return std::make_pair(iterator(_tree, node), false);
                _tree.root = _tree.insert(_tree.root, val);
                return std::make_pair(iterator(_tree, _tree.root), true);
            }
            iterator begin()
            {
                iterator it = iterator(_tree, 0);
                return (it++);
            }
            iterator end()
            {
                return (iterator(_tree, 0));
            }
		private:
			allocator_type		_allocator;
			Tree				_tree;
			size_type			_size;
	};
}