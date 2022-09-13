#pragma once
#include <functional>
#include "helper.hpp"

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
			typedef ft::pair<const Key,T>   value_type;
			typedef Tree<value_type>		Tree;
			typedef size_t					size_type 
		public:
			explicit map (const key_compare& comp = key_compare(),
              const allocator_type& alloc = allocator_type()) : _tree(), _size(0), _allocator() 
			  {}
			
		private:
			allocator_type		_allocator;
			Tree				_tree;
			size_type			_size;
	}
}