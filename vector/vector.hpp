#pragma once
#include <iostream>
#include "iterator.hpp"
namespace ft
{
    #include "helper.hpp"
	template <class T, class Allocator = std::allocator<T> >  
	class vector
	{
        public:
            typedef T value_type;
            typedef T& reference;
            typedef std::size_t size_type;
            typedef ft::iterator<T> iterator;
		public:
			vector() :_size(0) ,_capacity(0), _buff(NULL) {};
			size_type size(){ return _size;}
			size_type capacity(){ return _capacity;}

            void    reserve(size_type n)
            {
                if (n > _capacity)
                {
                    value_type* 			_tmp;
                    size_type old_capacity = _capacity;
                    _capacity = n;
                     // fill tmp with buff content
                    _tmp = _allocator.allocate(n);
                    for (size_type i = 0; i < _size; i++)
                        _allocator.construct(&_tmp[i], _buff[i]);
                    // destroy and deallocate buff
                    for (size_type i = 0; i < _size; i++)
                        _allocator.destroy(&_buff[i]);
                    // if (_buff)
                    _allocator.deallocate(_buff, old_capacity);
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

            reference back(){ return (_buff[_size - 1]);}
            reference front(){ return (_buff[0]);}
            
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
                if (n > _capacity)
                    this->reserve(n);
                for (size_type i = 0; i < n; i++)
                {
                    _allocator.destroy(&_buff[i]);
                    _allocator.construct(&_buff[i], val);
                }
                for (size_type i = n; i < _size; i++)
                    _allocator.destroy(&_buff[i]);
                _size = n;
            }
            bool empty() const {return _size == 0;}
            reference operator[](size_type n){ return (_buff[n]);}
            void    swap(vector&x)
            {
                value_type*_buff_tmp = this->_buff;
                size_type _size_tmp = this->_size;
                size_type _capacity_tmp = this->_capacity;

                this->_buff = x._buff;
                this->_size = x._size; 
                this->_capacity = x._capacity;

                x._buff = _buff_tmp;
                x._size = _size_tmp;
                x._capacity = _capacity_tmp; 
            }
            void    clear()
            {
                while(_size)
                    this->pop_back();
            }
            iterator begin() 
            {
                return (iterator(&_buff[0]));
            }
            iterator end() {return (iterator(&_buff[_size]));};
            iterator insert(iterator position, const value_type &val)
            {
                int dis = ft::distance(end(), position);
                iterator end = this->end();
                if (_capacity == _size)
                    this->reserve(_capacity * 2);
                for (int i = 0; i != dis; i++)
                    *(end - i) = *(end  - i - 1);
                _allocator.construct(&(*(end - dis)), val);
                _size++;
                return end - dis;
            }
        // class iterator;
		
        private:
			Allocator	_allocator;
			size_type _size;
			size_type _capacity;
			value_type* 			_buff;
	};
}
