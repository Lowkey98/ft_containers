#pragma once
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include "iterator.hpp"
#include "../helper.hpp"
#include "../reverse_iterator.hpp"
namespace ft
{
	template <class T, class Allocator = std::allocator<T> >  
	class Vector
	{
        public:
            typedef T value_type;
            typedef Allocator allocator_type;
            
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::pointer   pointer;
            typedef std::size_t size_type;
            typedef ft::iterator<T> iterator;
            typedef	typename std::ptrdiff_t		        difference_type;
            typedef ft::reverse_iterator<iterator> reverse_iterator;
            typedef ft::const_iterator<T> const_iterator;
            typedef ft::const_reverse_iterator<const_iterator> const_reverse_iterator;
		public:
            explicit Vector (const allocator_type& alloc = allocator_type())
            {
                _allocator = alloc;
                _buff = NULL;
                _size = 0;
                _capacity = 0;
            }
            explicit Vector (size_type n, const value_type& val = value_type(),
                const allocator_type& alloc = allocator_type())
            {
                // (void)alloc;
                _allocator = alloc;
                _size = n;
                _capacity = n;
                _buff = _allocator.allocate(n);
                for (size_type i = 0; i < n; i++)
                    _allocator.construct(&_buff[i],val);
            }
            template <class InputIterator>
            Vector (InputIterator first, typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type last,
                 const allocator_type& alloc = allocator_type())
            {
                size_type n = ft::distance(last, first);
                _size = n;
                _capacity = n;
                _allocator = alloc;
                _buff = _allocator.allocate(n);
                for (size_type i = 0; i < n; i++)
                    _allocator.construct(&_buff[i], *(first + i));
            }
			size_type size()const { return _size;}
            size_type max_size() const{ return 1;};
			size_type capacity()const { return _capacity;}
            void    reserve(size_type n)
            {
                if (n > _capacity)
                {
                    value_type* 			_tmp;
                    // size_type old_capacity = _capacity;
                    _capacity = n;
                     // fill tmp with buff content
                    _tmp = _allocator.allocate(n);
                    for (size_type i = 0; i < _size; i++)
                        _allocator.construct(&_tmp[i], _buff[i]);
                    // destroy and deallocate buff
                    for (size_type i = 0; i < _size; i++)
                        _allocator.destroy(&_buff[i]);
                    // if (_buff)
                    //     _allocator.deallocate(_buff, _capacity);
                    // fill buff
                    _buff = _tmp; 
                }
            }
			void	push_back(value_type value)
			{
				if (_size == 0 && _capacity == 0)
				{
					_buff = _allocator.allocate(1);
					_capacity = 1;
				}
				else if (_size == _capacity)
				{
                    this->reserve(_capacity * 2);
				}
                _allocator.construct(&_buff[_size],value);
				_size++;
			}

            void    pop_back()
            {
                if(_size)
                {
                    _allocator.destroy(&_buff[_size - 1]);
                    _size--;
                }
            }

            reference back() const { return (_buff[_size - 1]);}
            reference front()const { return (_buff[0]);}
            
            void resize(size_type n, value_type val = value_type())
            {
                if (n < _size)
                {
                    for (size_type i = n; i < _size; i++)
                        _allocator.destroy(&_buff[i]);
                }
                else if (n > _size && n <= _capacity)
                {
                    for (size_type i = _size; i < n; i++)
                        _allocator.construct(&_buff[i], val);
                }
                else if (n > _capacity)
                {
                    this->reserve(n);
                    for (size_type i = _size; i < _capacity; i++)
                        _allocator.construct(&_buff[i], val);
                }
                _size = n;
            }
            void assign(size_type n, const value_type& val)
            {
                
                clear();
                if (n > _capacity)
                    this->reserve(n);
                for (size_type i = 0; i < n; i++)
                    _allocator.construct(&_buff[i], val);
                _size = n;
            }
            template <class InputIterator>
            void    assign(InputIterator first, typename ft::enable_if<ft::is_integral<InputIterator>::value, InputIterator>::type last)
            {
                clear();
                size_type dis = ft::distance(last, first);
                if (dis > _capacity)
                    this->reserve(dis);
                for (size_type i = 0; i != dis; i++)
                {
                    _allocator.construct(&_buff[i], *first);
                    first++;
                }
                _size = dis;
            }
            bool empty() const {return _size == 0;}
            reference operator[](size_type n){ return (_buff[n]);}
            const reference operator[](size_type n)const { return (_buff[n]);}
            void    swap(Vector &x)
            {
                std::swap(this->_buff, x._buff);
                std::swap(this->_size, x._size);
                std::swap(this->_capacity, x._capacity);
            }
            void    clear()
            {
                while(_size)
                    this->pop_back();
            }
            const_iterator begin() const
            {
                return (const_iterator(&_buff[0]));
            }
            iterator begin() 
            {
                return (iterator(&_buff[0]));
            }
            reverse_iterator rbegin()
            {
                return (reverse_iterator(end()));
            }
            const_reverse_iterator rbegin() const
            {
                return (const_reverse_iterator(end()));
            }
            const_iterator end() const
            {
                return (const_iterator(&_buff[_size]));
            }
            reverse_iterator rend()
            {
                return (reverse_iterator(begin()));
            }
            const_reverse_iterator rend() const
            {
                return (const_reverse_iterator(begin()));
            }
            iterator end() {return (iterator(&_buff[_size]));};
            iterator insert(iterator position, const value_type &val)
            {
                if (_capacity == 0)
                {
                    push_back(val);
                    return (begin());
                }
                int dis = ft::distance(end(), position);
                // std::cout << dis << std::endl;
                iterator end = this->end();
                if (_capacity == _size)
                    this->reserve(_capacity * 2);
                for (int i = 0; i != dis; i++)
                    _buff[_size - i] = _buff[_size - i - 1];
                _allocator.construct(&_buff[_size - dis], val);
                _size++;
                return iterator(end - dis);
            }
            void insert(iterator position, size_type n, const value_type& val)
            {
                int dis = ft::distance(end(), position);
                if (_size + n > _capacity * 2)
                    reserve(_size + n);
                while (n--)
                    insert(end() - dis, val);
            }
            template <class InputIterator>
            void insert (iterator position, typename ft::enable_if<ft::is_integral<InputIterator>::value,InputIterator>::type first, InputIterator last)
            {
                int dis = ft::distance(end(), position);
                int n = ft::distance(last, first);
                if (_size + n > _capacity * 2)
                    reserve(_size + n);
                for (InputIterator i = first; i != last; i++)
                    insert(end() - dis, *i);
            }
            iterator    erase(iterator position)
            {
                _allocator.destroy(&(*position));
                for (iterator i = position; i != end() - 1; i++)
                    *i = *(i + 1);
                _size--;
                return (position);                    
            }
            iterator    erase(iterator first, iterator last)
            {
                int dis = ft::distance(last, first);
                // int dis1 = ft::distance(first, begin());
                for (iterator i = first; i != last; i++)
                    _allocator.destroy(&(*i));
                for (iterator i = last; i != end(); i++)
                    *(i - dis) = *i;
                _size -= dis;
                return (first);
            }
            reference at (size_type n) const
            {
                if (n > _size)
                    throw std::out_of_range("");
                return this->_buff[n];
            }
            allocator_type get_allocator() const
            {
                return _allocator;
            }
            bool operator==(const Vector &rhs) const {return (this->_size == rhs.size()) && ft::equal(begin(), end(), rhs.begin());}
            bool operator!=(const Vector &rhs) const {return !(*this == rhs);}
            bool operator<(const Vector &rhs) const {return std::lexicographical_compare(begin(),end(),rhs.begin(),rhs.end());}
            bool operator>=(const Vector &rhs) const {return !(*this < rhs);}
            bool operator>(const Vector &rhs) const {return rhs < *this;}
            bool operator<=(const Vector &rhs) const {return !(rhs < *this);}

        private:
			Allocator	_allocator;
			size_type _size;
			size_type _capacity;
			value_type* 			_buff;
	};
}
