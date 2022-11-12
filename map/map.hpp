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
			> class Map
	{

		public:
			typedef Key								        key_type;
			typedef T								        mapped_type;
			typedef Compare							        key_compare;
			typedef Alloc							        allocator_type;
			typedef pair<const Key, T>						        value_type;
			typedef Tree<Key, T, Compare, Alloc>		        Tree;
            typedef iterator<Key, T, Tree>					        iterator;
            typedef reverse_iterator<iterator>					reverse_iterator;
			typedef size_t							        size_type;
            typedef Node<value_type>				        Node;
            typedef const_iterator<Key, T, Tree>                    const_iterator;
            typedef const_reverse_iterator<const_iterator>					const_reverse_iterator;
            class value_compare
            {
                friend class map;
                protected:
                    Compare comp;
                    value_compare (Compare c) : comp(c) {}
                public:
                    typedef bool result_type;
                    typedef value_type first_argument_type;
                    typedef value_type second_argument_type;
                    value_compare () : comp() {}
                    bool operator() (const value_type& x, const value_type& y) const
                    {
                        return comp(x.first, y.first);
                    }
            };
		private:
			allocator_type		_allocator;
			size_type			_size;
			Tree				_tree;
            key_compare         _compare;
        // private:

		public:
			explicit Map (const key_compare& comp = key_compare(),
              const allocator_type& alloc = allocator_type()) : _allocator(),  _size(0), _tree()
			  {
                //temp 
                (void)comp;
                (void)alloc;
              }
            template <class InputIterator>
            Map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type())
			{
                (void)comp;
                (void)alloc;				
				while (first != last)
				{
					insert(*first);
					first++;
				}
			}

			size_type count (const key_type& k) const
            {
                if (_tree.search(k))
                    return (1);
                else
                    return (0);
            }
            iterator find (const key_type& k)
            {
                return (iterator(&_tree, _tree.search(k)));
            }
            pair<iterator,bool> insert (const value_type& val)
            {
                if (_tree.search(val.first))
                    return ft::make_pair(iterator(&_tree, NULL), false);
                _tree.insert(val);
                _size++;
                return ft::make_pair(iterator(&_tree, NULL), true);
            }
            iterator insert (iterator position, const value_type& val)
            {
                insert(val);
                return position;
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
                return (iterator(&_tree, NULL));
            }
            const_iterator begin() const
            {
                if (_size == 0)
                    return const_iterator(&_tree, _tree.dummy_node);
                return (const_iterator(&_tree, NULL));
            }
            iterator end()
            {
                return (iterator(&_tree, _tree.dummy_node));
            }
            const_iterator end() const
            {
                return (const_iterator(&_tree, _tree.dummy_node));
            }
            mapped_type& operator[] (const key_type& k)
            {
                this->insert(ft::make_pair(k,mapped_type()));
                return (_tree.search(k)->data.second);
            }
            mapped_type& at (const key_type& k)
            {
                Node *node = _tree.search(k);
                if (node == NULL)
                    throw std::out_of_range("out of range");
                return (node->data.second);
            }
			value_compare value_comp() const
			{
				return (value_compare());
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
            const_iterator lower_bound (const key_type& k) const
            {
                const_iterator it = begin();
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
            const_iterator upper_bound (const key_type& k) const
            {
                const_iterator it = begin();
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
            pair<const_iterator,const_iterator> equal_range (const key_type& k) const
            {
                return (ft::make_pair(lower_bound(k), upper_bound(k)));
            }
            allocator_type get_allocator() const
            {
                return _allocator;
            }
            void swap(Map &x)
            {
                std::swap(this->_tree, x._tree);
                std::swap(this->_size, x._size);
            }
            reverse_iterator rbegin()
            {
                return reverse_iterator(end());
            }
            const_reverse_iterator rbegin() const
            {
                return const_reverse_iterator(end());
            }
            reverse_iterator rend()
            {
                return reverse_iterator(begin());
            }
            const_reverse_iterator rend() const
            {
                return const_reverse_iterator(begin());
            }
	};
    template <class Key, class T, class Compare, class Alloc>
	bool	operator == (const Map<Key, T, Compare, Alloc>& lhs, const Map<Key, T, Compare, Alloc>& rhs)
	{
		return ((lhs.size() == rhs.size()));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator != (const Map<Key, T, Compare, Alloc>& lhs, const Map<Key, T, Compare, Alloc>& rhs)
	{
		return (!(lhs == rhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator > (const Map<Key, T, Compare, Alloc>& lhs, const Map<Key, T, Compare, Alloc>& rhs)
	{
		return (rhs < lhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator < (const Map<Key, T, Compare, Alloc>& lhs, const Map<Key, T, Compare, Alloc>& rhs)
	{
		return (std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator >= (const Map<Key, T, Compare, Alloc>& lhs, const Map<Key, T, Compare, Alloc>& rhs)
	{
			return (!(lhs < rhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator <= (const Map<Key, T, Compare, Alloc>& lhs, const Map<Key, T, Compare, Alloc>& rhs)
	{
		return (!(lhs > rhs));
	}
}
