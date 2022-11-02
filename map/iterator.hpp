#pragma once
#include "map.hpp"
#include "../helper.hpp"
#include "avl.hpp"
#include <functional>

template <class Key,
        class T,
        class Compare = std::less<Key>,
		class Alloc = std::allocator<ft::pair<const Key,T> >
        >
class iterator
{
    public:
        typedef Key                                 key_type;
        typedef T                                   mapped_type;
        typedef Compare                             key_compare;
        typedef Alloc                               allocator_type;
        typedef ft::pair<Key,T>                     value_type;
        typedef Tree<Key, T, Compare, Alloc>		Tree;
        typedef size_t					            size_type;
        typedef Node<value_type>                    Node;
    private:
        Tree    *_tree;
        Node    *_current;
    public:
        iterator() : _tree(), _current()
        {

        }
        iterator(const iterator &it)
        {
            *this = it;
        }
        iterator(Tree *tr, Node *cr): _tree(tr), _current(cr)
        {
            // (void)comp;
        }
        iterator &operator=( const iterator &it)
        {
            _tree = it._tree;
            _current = it._current;
            return *this;
        }
        ~iterator(){}
        value_type * operator->()
        {
            return (&(_current->data));
        }
        value_type operator*()
        {
            return (_current->data);
        }
        Node    *current()const {return _current;}
        iterator operator++()
        {
                    // std::cout << "TEST" << std::endl;
            Node *tmp = _current;
            _current = _tree->findSuccessorIterative(_current);
            return (iterator(_tree, tmp));
        }
        iterator operator++(int)
        {
            _current = _tree->findSuccessorIterative(_current);
            return (iterator(_tree, _current));
        }
        iterator operator--()
        {
            Node *tmp = _current;
            _current = _tree->findPredecessorIterative(_current);
            return (iterator(_tree, tmp));
        }
        iterator operator--(int)
        {
            _current = _tree->findPredecessorIterative(_current);
            return (iterator(_tree, _current));
        } 

};
template<class Key,
         class T>
bool operator!=(iterator<Key,T> & lhs, const iterator<Key,T> & rhs)
{
    return lhs.current() != rhs.current();
}