#pragma once
#include<iostream>
#include "../helper.hpp"
template <class T>
class Node
{
	public:
		T  data;
		unsigned int height;
		Node<T> *left;
		Node<T> *right;
	public:
		Node(const T &d) :data(d), height(1), left(NULL), right(NULL){}
		~Node(){}
};

template <class Key,
		  class T,
		  class Compare = std::less<Key>,
		  class Alloc = std::allocator<ft::pair<const Key,T> >
		 > 
class Tree
{
	public:
		typedef Key								key_type;
		typedef T								mapped_type;
		typedef Compare							key_compare;
		typedef Alloc							allocator_type;
		typedef ft::pair<const Key,T>           value_type;
		typedef Node<value_type>                Node;
	public:
		Node                                                    *dummy_node;
		Node													*inserted_node;
		unsigned int											size;
	private:
		Node                                                    *_root;
		key_compare												_compare;
		allocator_type											_allocator;
		typename allocator_type::template rebind<Node>::other	_node_allocator;
	public:
		Tree(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):
		 size(0),_root(NULL), _compare(comp), _allocator(alloc)
		{
			dummy_node = _node_allocator.allocate(1);
		}
		~Tree()
		{
			clear(_root);
			_node_allocator.deallocate(dummy_node, 1);
		}
		void	insert(const value_type &data)
		{
			_root = insert(_root, data);
		}
		void	delete_node(key_type key)
		{
			_root = delete_node(_root, key);
		}
		Node* search(key_type key) const
		{
			return search(_root, key);
		}
		Node *min_value_node()
		{
			Node *current = this->_root;
			while (current->left != NULL)
				current = current->left;
			return current;
		}
		Node *min_value_node() const
		{
			Node *current = this->_root;
			while (current->left != NULL)
				current = current->left;
			return current;
		}
		void    post_order(void(Tree::*func)(Node*) )
		{
			post_order(this->_root, func);
		}
		allocator_type get_allocator() const
		{
			return _allocator;
		}
		key_compare get_compare() const
		{
			return (_compare);
		}
		Node*	lower_bound(const key_type & key) const
		{
			Node	*tmp = this->_root;
			Node	*lower_bound = NULL;

			while (tmp != NULL)
			{
				if (!_compare(tmp->data.first, key) && !_compare(key, tmp->data.first))
				{
					lower_bound = tmp;
					break ;
				}
				if (_compare(key, tmp->data.first) == true) // move to left
				{
					lower_bound = tmp;
					tmp = tmp->left;
				}
				else // move to right
					tmp = tmp->right;
			}
			return (lower_bound);
		}
		Node*	upper_bound(const key_type & key) const
		{
			Node	*tmp = this->_root;
			Node	*upper_bound = NULL;

			while (tmp != NULL)
			{
				if (_compare(key, tmp->data.first) == true) // move to left
				{
					upper_bound = tmp;
					tmp = tmp->left;
				}
				else // move to right
					tmp = tmp->right;
			}
			return (upper_bound);
		}
		void clear()
		{
			clear(this->_root);
			_root = NULL;
			size = 0;
		}
	private:
		int height(Node *n)
		{
			if (n == NULL)
				return 0;
			return n->height;
		}
		int max(int a, int b)
		{
			if (a > b)
				return a;
			return b;
		}
		int get_balance(Node *n)
		{
			if (n == NULL)
				return 0;
			return height(n->left) - height(n->right);
		}
		Node *right_rotate(Node *y)
		{
			Node *x = y->left;
			Node *T2 = x->right;
			x->right = y;
			y->left = T2;
			y->height = max(height(y->left), height(y->right)) + 1;
			x->height = max(height(x->left), height(x->right)) + 1;
			return x;
		}

		Node *left_rotate(Node *x)
		{
			Node *y = x->right;
			Node *T2 = y->left;
		
			// Perform rotation
			y->left = x;
			x->right = T2;
		
			// Update heights
			x->height = max(height(x->left), height(x->right)) + 1;
			y->height = max(height(y->left), height(y->right)) + 1;
			return y;
		}
		Node* insert(Node *node, const value_type &data)
		{
			if (node == NULL)
			{
				Node * new_node = _node_allocator.allocate(1);
				_node_allocator.construct(new_node, data);
				inserted_node = new_node;
				size++;
				return (new_node);
			}
			if (_compare(data.first, node->data.first))
				node->left = insert(node->left, data);
			else if (_compare(node->data.first, data.first))
			{
				node->right = insert(node->right, data);
			}
			else
			{
				inserted_node = node;
			}
			node->height = 1 + max(height(node->left), height(node->right));
			int balance = get_balance(node);
			if (balance > 1 && _compare(data.first, node->left->data.first))
			{
				return right_rotate(node);
			}
			else if (balance < -1 && _compare(node->right->data.first, data.first))
			{
				return left_rotate(node);
			}
			else if (balance > 1 && _compare(node->left->data.first, data.first))
			{
				node->left = left_rotate(node->left);
				return right_rotate(node);
			}
			else if (balance < -1 && _compare(data.first, node->right->data.first))
			{
				node->right = right_rotate(node->right);
				return left_rotate(node);
			}
			return (node);
		}
		Node *delete_node(Node *root, key_type key)
		{
			if (root == NULL)
				return root;
			if (_compare(key, root->data.first))
				root->left = delete_node(root->left, key);
			else if (_compare(root->data.first, key))
			{
				root->right = delete_node(root->right, key);

			}
			else
			{
				if (root->left == NULL && root->right==NULL)
				{
					_node_allocator.destroy(root);
					_node_allocator.deallocate(root, 1);
					std::cout << "TEST" << std::endl;
					return NULL;

				}
				else if (root->left == NULL)
				{
					Node* temp = root->right;
					_node_allocator.destroy(root);
					_node_allocator.deallocate(root, 1);
					return temp;
				}
				else if (root->right == NULL)
				{
					Node* temp = root->left;
					_node_allocator.destroy(root);
					_node_allocator.deallocate(root, 1);
					return temp;
				}
				Node* temp = min_value_node(root->right);
				_allocator.destroy(&root->data);
				_allocator.construct(&root->data, temp->data);
				root->right = delete_node(root->right, temp->data.first);
			}
			if (root == NULL)
				return root;
			root->height = 1 + max(height(root->left), height(root->right));
			int balance = get_balance(root);
			if (balance > 1 && get_balance(root->left) >= 0)
				return right_rotate(root);
			if (balance > 1 && get_balance(root->left) < 0)
			{
				root->left = left_rotate(root->left);
				return right_rotate(root);
			}
			if (balance < -1 && get_balance(root->right) <= 0)
				return left_rotate(root);
			if (balance < -1 && get_balance(root->right) > 0)
			{
				root->right = right_rotate(root->right);
				return left_rotate(root);
			}
			return root;
		}
		Node* search(Node *root, key_type key) const
		{
			if (root == NULL)
				return NULL;
			else if (_compare(key, root->data.first))
			{
				Node* rt = search(root->left, key);
				return rt;
			}
			else if (_compare(root->data.first, key))
			{
				Node* rt = search(root->right, key);
				return rt;
			}
			else 
				return root;
		}
		void clear(Node *node)
		{
			if (node == NULL)
				return;
			clear(node->left);
			clear(node->right);
			_node_allocator.destroy(node);
			_node_allocator.deallocate(node, 1);
		}
		public:
			void swap(Tree &x)
			{
				std::swap(this->_root, x._root);
				std::swap(this->size, x.size);
				std::swap(this->_compare, x._compare);
				std::swap(this->_allocator, x._allocator);
			}
			void    print_node(Node *node)
			{
				std::cout << node->data.first << std::endl;
			}
			Node *find_successor(Node *node) const
			{
				if (node == dummy_node || node == NULL)
					return NULL;
				return (find_successor(_root, node->data.first));
			}
			Node *find_predecessor(Node *node) const
			{
				if (node == dummy_node)
					return max_value_node(this->_root);
				return (find_predecessor (_root, node->data.first));
			}
			const Node *find_successor(const Node *node) const
			{
				if (node == dummy_node || node == NULL)
				{
					// std::cout << "TEST" << std::endl;
					return NULL;
				}
				return (find_successor(_root, node->data.first));
			}
			const Node *find_predecessor(const Node *node) const
			{
				if (node == dummy_node)
					return max_value_node(this->_root);
				return find_predecessor(_root, node->data.first);
			}
			Node* max_value_node(Node* root) const
			{
				while(root->right)
					root = root->right;	
				return root;
			}
			Node *min_value_node(Node *root)
			{
				Node *current = root;
				while (current->left != NULL)
					current = current->left;
				return current;
			}
			Node *min_value_node(Node *root) const
			{
				Node *current = root;
				while (current->left != NULL)
					current = current->left;
				return current;
			}
			Node* find_successor(Node *root, key_type key) const
			{
				Node *succ = NULL;
				while (true)
				{
					// if the node is greater than key, go to left subtree
					if (_compare(key, root->data.first))
					{
						// update successor to current node
						succ = root;
						root = root->left;
					}
					// if the node is less than the key, go to right subtree
					else if (_compare(root->data.first, key))
						root = root->right;
					// if node has same value as the key, 
					// then its successor is minimum value node in its right subtree
					else
					{
						if (root->right != NULL)
							succ = min_value_node(root->right);
						break;
					}

					// key doesn't exist in binary tree
					// if (root == NULL)
					//     return dummy_node;            
				}
				if (succ == NULL)
					return dummy_node;
				// return Successor
				return succ;
			}
		Node* find_predecessor(Node *rt, key_type key) const
		{
			Node* pred = NULL;
			while (true)
			{
			// if node value is greater than key, go to left subtree
			if (_compare(key, rt->data.first))
				rt = rt->left;
			// if node value is less than key, go to right subtree
			else if (_compare(rt->data.first, key))
			{
				// update predecessor to current node
				pred = rt;
				rt = rt->right;
			}

			// if node has same value as the key, 
			// then its predecessor is greatest value node in its left subtree
			else
			{
				if (rt->left!= NULL)
					pred = max_value_node(rt->left);
				break;
			}
			// if key doesn't exist in binary tree
			if (rt == NULL)
				return NULL;
			}
			// return predecessor if any
			return pred;
		}

};