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
			container_type c;
		public:
			explicit stack (const container_type& ctnr = container_type()): c(ctnr) {}
			stack(stack const & rhs) : c(rhs.c) {}
			stack&		operator=(stack const & other)
			{
				this->c = other.c;
				return *this;
			}
			~stack(){}
			bool empty() 	const 					{ return c.empty();}
			size_type size() const					{ return c.size();}
			value_type& top()						{ return c.back();}
			const value_type& top() const			{ return c.back();}
			void push (const value_type& val)		{ c.push_back(val);}
			void pop() 								{ c.pop_back();}
            private:
                template <class t, class container>
                friend bool operator== (const stack<t,container>& lhs, const stack<t,container>& rhs);
                 template <class t, class container>
                   friend bool operator!= (const stack<t,container>& lhs, const stack<t,container>& rhs);
                 template <class t, class container>
                   friend bool operator<  (const stack<t,container>& lhs, const stack<t,container>& rhs);
                 template <class t, class container>
                   friend bool operator<= (const stack<t,container>& lhs, const stack<t,container>& rhs);;
                 template <class t, class container>
                   friend bool operator>  (const stack<t,container>& lhs, const stack<t,container>& rhs);
                 template <class t, class container>
                   friend bool operator>=  (const stack<t,container>& lhs, const stack<t,container>& rhs);

	};
	template <class t, class container>
    bool operator== (const stack<t,container>& lhs, const stack<t,container>& rhs)
    {
        return lhs.c == rhs.c;
    }
	template <class t, class container>
    bool operator!= (const stack<t,container>& lhs, const stack<t,container>& rhs)
    {
        return lhs.c != rhs.c;
    }
	template <class t, class container>
    bool operator<  (const stack<t,container>& lhs, const stack<t,container>& rhs)
    {
        return lhs.c < rhs.c;
    }
	template <class t, class container>
    bool operator<= (const stack<t,container>& lhs, const stack<t,container>& rhs)
    {
        return lhs.c <= rhs.c;
    }
	template <class t, class container>
    bool operator>  (const stack<t,container>& lhs, const stack<t,container>& rhs)
    {
        return lhs.c > rhs.c;
    }
	template <class t, class container>
    bool operator>=  (const stack<t,container>& lhs, const stack<t,container>& rhs)
    {
        return lhs.c >= rhs.c;
    }
}
