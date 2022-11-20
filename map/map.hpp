#pragma once
#include <algorithm>
#include <cstdlib>
#include <functional>
#include "../helper.hpp"
#include "map_iterator.hpp"
#include "avl.hpp"
#include "../reverse_iterator.hpp"
#include "../vector/vector.hpp"
#include<vector>
namespace ft
{
	template <class Key,                                     
			class T,                                      
			class Compare = std::less<Key>,                    
			class Alloc = std::allocator<ft::pair<const Key,T> >
			> class map
	{

		public:
			typedef Key								                        key_type;
			typedef T								                        mapped_type;
			typedef Compare							                        key_compare;
			typedef Alloc							                        allocator_type;
			typedef ft::pair<const Key, T>						                value_type;
			typedef Tree<Key, T, Compare, Alloc>		                    Tree;
			typedef size_t							                        size_type;
            typedef Node<value_type>				                        Node;
            typedef map_iterator<Key, T, Tree>					            iterator;
            typedef const_map_iterator<Key, T, Tree>                        const_iterator;
            typedef reverse_iterator<const_iterator>					    const_reverse_iterator;
            typedef reverse_iterator<iterator>					            reverse_iterator;
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
			Tree				                                    _tree;
            key_compare												_compare;
            allocator_type											_allocator;
		public:
			explicit map (const key_compare& comp = key_compare(),
                const allocator_type& alloc = allocator_type()) : _tree(comp, alloc) , _compare(comp), _allocator(alloc) {}
            map (const map& x) : _tree(x.key_comp(), x.get_allocator()), _compare(x.key_comp()), _allocator(x.get_allocator())
            {
                insert(x.begin(), x.end());
            }
            template <class InputIterator>
                map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
                const allocator_type& alloc = allocator_type()) : _tree(comp, alloc)
                {	
        
                    while (first != last)
                    {
                        insert(*first);
                        first++;
                    }
                }
            map & operator= (const map &rhs) 
            {
                clear();
                this->_allocator = rhs._allocator;
                this->_compare   = rhs._compare;
                this->insert(rhs.begin(), rhs.end());
                return (*this);
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
                Node * node =  _tree.search(k);
                if (node)
                    return iterator(&_tree, node);
                return iterator(&_tree, _tree.dummy_node);
            }
            ft::pair<iterator,bool> insert (const value_type& val)
            {
                unsigned int  old_size = _tree.size;
                _tree.insert(val);
                if (_tree.size == old_size) 
                    return ft::make_pair(iterator(&_tree, _tree.inserted_node), false);
                return ft::make_pair(iterator(&_tree, _tree.inserted_node), true);
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
                    this->insert(*first);
                    first++;
                }
            }
            size_type erase (const key_type& k)
            {
                if (_tree.search(k))
                {
                    _tree.delete_node(k);
                    _tree.size--;
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
                ft::vector<key_type> v1;
                while (first != last)
                {
                    v1.push_back((*first).first);
                    first++;
                }
                for (typename ft::vector<key_type>::iterator it = v1.begin(); it != v1.end(); it++)
                {
                    erase(*it);
                }
            }
            void    clear()
            {
                _tree.clear();
            }
            iterator begin()
            {
                if (_tree.size == 0)
                {
                    return iterator(&_tree, _tree.dummy_node);
                }
                return iterator(&_tree, _tree.min_value_node());
            }
            const_iterator begin() const
            {
                if (_tree.size == 0)
                    return const_iterator(&_tree, _tree.dummy_node);
                return (const_iterator(&_tree, _tree.min_value_node()));
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
                return !(_tree.size);
            }
            size_type size() const
            {
                return (_tree.size);
            }
            key_compare key_comp() const
            {
                return _tree.get_compare();
            }
            iterator lower_bound (const key_type& k)
            {
                Node * lower_bound = _tree.lower_bound(k);
                if (lower_bound == NULL)
                    return end();
                return iterator(&_tree, lower_bound);
            }
            iterator upper_bound(const key_type& k)
            {
                Node * upper_bound = _tree.upper_bound(k);
                if (upper_bound == NULL)
                    return end();
                return iterator(&_tree, upper_bound);
            }
            const_iterator lower_bound (const key_type& k) const
            {
                Node * lower_bound = _tree.lower_bound(k);
                if (lower_bound == NULL)
                    return end();
                return const_iterator(&_tree, lower_bound);
            }
            const_iterator upper_bound(const key_type& k) const
            {
                Node * upper_bound = _tree.upper_bound(k);
                if (upper_bound == NULL)
                    return end();
                return const_iterator(&_tree, upper_bound);
            }
            ft::pair<iterator,iterator> equal_range (const key_type& k)
            {
                return (ft::make_pair(lower_bound(k), upper_bound(k)));
            }
            ft::pair<const_iterator,const_iterator> equal_range (const key_type& k) const
            {
                return (ft::make_pair(lower_bound(k), upper_bound(k)));
            }
            allocator_type get_allocator() const
            {
                return _tree.get_allocator();
            }
            void swap(map &x)
            {
                this->_tree.swap(x._tree);
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
	bool	operator == (const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		return (lhs.size() == rhs.size()) && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator != (const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		return (!(lhs == rhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator > (const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		return (rhs < lhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator < (const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		return (std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(),rhs.end()));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator >= (const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		return (!(lhs < rhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator <= (const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		return (!(lhs > rhs));
	}
}
