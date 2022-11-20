#include "../vector/vector.hpp"

namespace ft
{

	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef T           value_type;
			typedef Container   container_type;
			typedef size_t      size_type;
		protected:
			container_type _container;
		public:
			explicit stack (const container_type& ctnr = container_type()): _container(ctnr) {}
			bool empty() 	const 					{ return _container.empty();}
			size_type size() const					{ return _container.size();}
			value_type& top()						{ return _container.back();}
			const value_type& top() const			{ return _container.back();}
			void push (const value_type& val)		{ _container.push_back(val);}
			void pop() 								{ _container.pop_back();}
			
			// bool operator== (const stack& rhs)
			// {
			// 	(void)rhs;
			// 	return 0;
			// }
		// friend bool operator== (const stack& lhs, const stack& rhs);
			friend bool ft::operator== (const stack<T,Container>& , const stack<T,Container>& );
			friend bool ft::operator!= (const stack<T,Container>& , const stack<T,Container>& );
  			friend bool ft::operator< (const stack<T,Container>& , const stack<T,Container>& );
  			friend bool ft::operator<= (const stack<T,Container>& , const stack<T,Container>& );
  			friend bool ft::operator> (const stack<T,Container>& , const stack<T,Container>& );
  			friend bool ft::operator>= (const stack<T,Container>& , const stack<T,Container>& );
	};
		template <class T, class Container>
			bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
			{
				return lhs._container == rhs._container;
			}
		template <class T, class Container>
			bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
			{
				return lhs._container != rhs._container;
			}
		template <class T, class Container>
  			bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
			{
				return lhs._container < rhs._container;
			}
		template <class T, class Container>
  			bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
			{
				return lhs._container <= rhs._container;
			}
		template <class T, class Container>
  			bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
			{
				return lhs._container > rhs._container;
			}
		template <class T, class Container>
  			bool operator>=  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
			{
				return lhs._container >= rhs._container;
			}
}