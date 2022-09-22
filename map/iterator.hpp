#pragma once
#include "map.hpp"

template <class T>
class iterator
{
    public:
		typedef Tree<T>          Tree;
        typedef Node<T>             Node;
        typedef T                   value_type;
    public:
        iterator() : _tree(), _current(){}
        iterator(const iterator &it)
        {
            *this = it;
        }
        iterator(const Tree tr, Node *cr): _tree(tr), _current(cr){}
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
                _current = _tree.root;
                while (_current->left != NULL)
                    _current = _current->left;
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
    private:
        Tree    _tree;
        Node    *_current;


};
template<class T>
bool operator!=(iterator<T> & lhs, const iterator<T> & rhs)
{
    return lhs.current() != rhs.current();
}