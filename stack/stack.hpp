#include "../vector/vector.hpp"
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
		void push (const value_type& val)		{ _container.push_back();}
		void pop() 								{ _container.pop_back();};
};
