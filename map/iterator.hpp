#pragma once
#include "map.hpp"
#include "../helper.hpp"
#include <functional>

template <class Key,
        class T,
        class Compare = std::less<Key>,
		class Alloc = std::allocator<ft::pair<const Key,T> >
        >
class iterator
{
    public:
        typedef Key                     key_type;
        typedef T                       mapped_type;
        typedef Compare                 key_compare;
        typedef Alloc                   allocator_type;
        typedef ft::pair<Key,T>   value_type;
        typedef Tree<Key, T, Compare, Alloc>		Tree;
        typedef size_t					size_type;
        typedef Node<value_type>        Node;
    private:
        Tree    _tree;
        Node    *_current;
    public:
        iterator() : _tree(), _current(_tree.root)
        {

            // (void)comp;
        }
        iterator(const iterator &it)
        {
            *this = it;
        }
        iterator(const Tree tr, Node *cr): _tree(tr), _current(cr)
        {
            // (void)comp;
        }
        iterator &operator=(const iterator &it)
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
        iterator operator++(int)
        {
            if (_current == NULL)
            {
                // if (_tree.root == NULL) // no tree
                // _current = _tree.root;
                while (_current->left != NULL)
                    _current = _current->left;
                // exit(0);
            }
            else
            {
                if (_current->right != NULL)
                {
                    _current = _current->right;
                    while (_current->left != NULL)
                        _current = _current->left;
                }
                else
                {
                    Node *p = _current->parent;
                    while (p != NULL && _current == p->right)
                    {
                        _current = p;
                        p = p->parent;
                    }
                    _current = p;
                }
            }
            return *this;
        }
        Node    *current()const {return _current;}


};
template<class Key,
         class T>
bool operator!=(iterator<Key,T> & lhs, const iterator<Key,T> & rhs)
{
    return lhs.current() != rhs.current();
}