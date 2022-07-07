#include <iostream>

namespace ft
{
	
	template <class T, class Allocator = std::allocator<T> >  
	class vector
	{
        public:
            typedef T value_type;
            typedef T& reference;
            typedef std::size_t size_type;
		public:
			vector() :_size(0) ,_capacity(0), _buff(NULL) {};
			size_type size(){ return _size;}
			size_type capacity(){ return _capacity;}

            void    reserve(size_type n)
            {
                if (n > _capacity)
                {
                    size_type old_capacity = _capacity;
                    _capacity = n;
                     // fill tmp with buff content
                    _tmp = _allocator.allocate(old_capacity);
                    for (size_type i = 0; i < _size; i++)
                        _allocator.construct(&_tmp[i], _buff[i]);
                    // destroy and deallocate buff
                    for (size_type i = 0; i < _size; i++)
                        _allocator.destroy(&_buff[i]);
                    if (_buff)
                        _allocator.deallocate(_buff, old_capacity);
                    // fill buff
                    _buff = _allocator.allocate(_capacity);
                    for (size_type i = 0; i < _size; i++)
                        _allocator.construct(&_buff[i], _tmp[i]);
                    // deallocate tmp
                    _allocator.deallocate(_tmp, old_capacity);
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
            
            void resize(size_type n, value_type val = value_type())
            {
                if (n < _size)
                {
                    for (size_type i = n; i < _size; i++)
                        _allocator.destroy(&_buff[i]);
                }
                else if (n > _size && n < _capacity)
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
            reference operator[](size_type n){ return (_buff[n]);}
		private:
			Allocator	_allocator;
			size_type _size;
			size_type _capacity;
			value_type* 			_buff;
			value_type* 			_tmp;
	};
}