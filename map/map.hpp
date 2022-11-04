#pragma once
#include <functional>
#include "../helper.hpp"
#include "iterator.hpp"
// #include "../vector/vector.hpp"
namespace ft
{
	template < class Key,                                     // map::key_type
			class T,                                       // map::mapped_type
			class Compare = std::less<Key>,                     // map::key_compare
			class Alloc = std::allocator<pair<const Key,T> >    // map::allocator_type
			> class map
	{
		public:
			typedef Key								        key_type;
			typedef T								        mapped_type;
			typedef Compare							        key_compare;
			typedef Alloc							        allocator_type;
			typedef pair<Key,T>						        value_type;
            typedef iterator<Key,T>					        iterator;
            typedef reverse_iterator<Key,T>					reverse_iterator;
			typedef Tree<Key,T, Compare, Alloc>		        Tree;
			typedef size_t							        size_type;
            typedef Node<value_type>				        Node;
		private:
			allocator_type		_allocator;
			size_type			_size;
			Tree				_tree;
            key_compare         _compare;
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
                return (iterator(&_tree, _tree.search(k)));
            }
            ft::pair<iterator,bool> insert (const value_type& val)
            {
                if (_tree.search(val.first))
                    return ft::make_pair(iterator(&_tree, NULL), false);
                _tree.insert(val);
                _size++;
                return ft::make_pair(iterator(&_tree, _tree.min_value_node()), true);
            }
            template <class InputIterator>
            void insert (InputIterator first, InputIterator last)
            {
                while (first != last)
                {
                    insert(*first);

                    first++;
                }
            }
            size_type erase (const key_type& k)
            {
                if (_tree.search(k))
                {
                    _tree.delete_node(k);
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
            void    clear()
            {
                // std::cout << _tree.root->data.first << std::endl;
                _tree.post_order(&Tree::clear_node);
                _size = 0;

            }
            iterator begin()
            {
                if (_size == 0)
                    return iterator(&_tree, _tree.dummy_node);
                return (iterator(&_tree, _tree.min_value_node()));
            }
            iterator end()
            {
                return (iterator(&_tree, _tree.dummy_node));
            }
            mapped_type& operator[] (const key_type& k)
            {
                this->insert(make_pair(k,mapped_type()));
                return (_tree.search(k)->data.second);
            }
            mapped_type& at (const key_type& k)
            {
                Node *node = _tree.search(k);
                if (node == NULL)
                    throw std::out_of_range("out of range");
                return (node->data.second);
            }
            bool empty() const
            {
                return _size;
            }
            size_type size() const
            {
                return (_size);
            }
            key_compare key_comp() const
            {
                return (_compare);
            }
            iterator lower_bound (const key_type& k)
            {
                iterator it = begin();
                while (_compare((*it).first, k))
                    it++;
                return it;
            }
            iterator upper_bound (const key_type& k)
            {
                iterator it = begin();
                while (_compare((*it).first, k))
                {
                    it++;
                }
                return it++;
            }
            pair<iterator,iterator> equal_range (const key_type& k)
            {
                return (ft::make_pair(lower_bound(k), upper_bound(k)));
            }
            allocator_type get_allocator() const
            {
                return _allocator;
            }
            void swap(map &x)
            {
                std::swap(this->_tree, x._tree);
                std::swap(this->_size, x._size);
            }
            reverse_iterator rbegin()
            {
                return reverse_iterator(end());
            }
            reverse_iterator rend()
            {
                return reverse_iterator(begin());
            }
	};
}