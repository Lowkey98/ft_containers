#include<iostream>
#include "../helper.hpp"
template <class T>
class Node
{
    public:
        T  data;
        Node<T> *left;
        Node<T> *right;
        Node<T> *parent;
    public:
        Node(T &d) :data(d){}
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
        typedef ft::pair<Key,T>                 value_type;
        typedef Node<value_type>                Node;
    public:
        Tree(): root(NULL){}
        Node *root;
    private:
        key_compare _compare;
        allocator_type _allocator;
        typename allocator_type::template rebind<Node>::other _node_allocator;
    public:
        Node *left_left_rotation(Node *root)
        {
            Node *tmp = root->left;
            root->left = tmp->right;
            if (tmp->right != NULL)
                tmp->right->parent = root;
            tmp->right = root;
            tmp->parent = root->parent;
            root->parent = tmp;
            if (tmp->parent != NULL && root->data < tmp->parent->data)
                tmp->parent->left = tmp;
            else 
            {
                if (tmp->parent != NULL)
                    tmp->parent->right = tmp;
            }
            root = tmp;
            return root;
        }
        Node* right_right_rotation(Node* root)
        {
            Node* tmp = root->right;
            root->right = tmp->left;
            if (tmp->left != NULL)
                tmp->left->parent = root;
            tmp->left = root;
            tmp->parent = root->parent;
            root->parent = tmp;
            if (tmp->parent != NULL && root->data < tmp->parent->data)
                tmp->parent->left = tmp;
            else
            {
                if (tmp->parent != NULL)
                    tmp->parent->right = tmp;
            }
            root = tmp;
            return root;
        }
        Node *left_right_rotation(Node *root)
        {
            root->left = right_right_rotation(root->left);
            return (left_left_rotation(root));
        }
        Node *right_left_rotation(Node *root)
        {
            root->right = left_left_rotation(root->right);
            return (right_right_rotation(root));
        }
        int     height(Node* node)
        {
            if (node == NULL)
                return -1;
            int height_l = height(node->left);
            int height_r = height(node->right);
            return (std::max(height_l, height_r) + 1);
        }
        int     get_balance_factor(Node* node)
        {
            return (height(node->left) - height(node->right));
        }

        Node * delete_node(Node *node, key_type key)
        {
        	if (node != NULL)
        	{
                if (node->data.first == key)
                { 
					if (node->right == NULL
						&& node->left != NULL) {
						if (node->parent != NULL)
						{
							if (node->parent->data.first
								< node->data.first)
								node->parent->right = node->left;
							else
								node->parent->left = node->left;
						}
						node->left->parent = node->parent;
						node->left = balance_tree(node->left, key);
						return node->left;
                }
                	else if (node->left == NULL
                        && node->right != NULL) {
                    if (node->parent != NULL) {
                        exit(0);
                        if (node->parent->data.first
                            < node->data.first)
                            node->parent->right = node->right;
                        else
                            node->parent->left = node->right;
                    }
                    node->right->parent = node->parent;
                    node->right = balance_tree(node->right, key);
                    return node->right;
                }
                	else if (node->left == NULL
                        && node->right == NULL)
					{
						if (node->parent->data.first < node->data.first)
						{
							node->parent->right = NULL;
						}
						else
						{
							node->parent->left = NULL;
						}
						node = NULL;
						return NULL;
            		}
					else
					{
						// exit(0);
						Node* tmpnode = node;
						tmpnode = tmpnode->right;
						while (tmpnode->left != NULL) {
							tmpnode = tmpnode->left;
						}
						int val = tmpnode->data.first;
						node->right = delete_node(node->right, tmpnode->data.first);
						node->data.first = val;
						node = balance_tree(node, key);
					}
        		}
				else if (node->data.first < key)
				{
					node->right = delete_node(node->right, key);
					node = balance_tree(node, key);
				}
				else if (node->data.first > key)
				{
					node->left = delete_node(node->left, key);
					node = balance_tree(node, key);
				}
    		}
        	return node;
    	}
        Node *balance_tree(Node* node, key_type key)
        {
            int balance_factor = get_balance_factor(node);
            if (balance_factor == 2)
            {
                if (key > node->left->data.first)
                {
                    node = left_right_rotation(root);
                }
                else 
                    node = left_left_rotation(root);
            }
            else if (balance_factor == -2)
            {
                if (key < node->right->data.first)
                {
                    node = right_left_rotation(node);
                }
                else 
                    node = right_right_rotation(node);
            }
            return node;
        }
        Node* insert(Node *node, value_type data)
        {
            if (node == NULL)
            {
                node = _node_allocator.allocate(1);
                _node_allocator.construct(node, data);
                return (node);
            }
            if (data.first > node->data.first)
            {
                Node *right_child = insert(node->right, data);
                node->right = right_child;
                right_child->parent = node;
            }
            else
            {
                Node *left_child = insert(node->left, data);
                node->left = left_child;
                left_child->parent = node;
            }
            node = balance_tree(node, data.first);
            return (node);
        }
        Node* search(Node *root, key_type key)
        {
            if (root == NULL)
                return NULL;
            else if (root->data.first == key)
                return root;
            else if (root->data.first > key)
            {
                Node* rt = search(root->left, key);
                return rt;
            }
            else
            {
                Node* rt = search(root->right, key);
                return rt;
            }
        }
        void    inorder(Node* node)
        {
            if (node == NULL)
                return ;
            inorder(node->left);
            if (node->parent)
                std::cout << node->data.first << "parent" << node->parent->data.first << std::endl;
            else
                std::cout << node->data.first << std::endl; 
            inorder(node->right);
        }
        void    preorder(Node* node)
        {
            if (node == NULL)
                return ;
            std::cout << node->data << std::endl;
            preorder(node->left);
            preorder(node->right);
        }
        void    postorder(Node* node)
        {
            if (node == NULL)
                return ;
            postorder(node->left);
            postorder(node->right);
            std::cout << node->data << std::endl;
        }
        Node* minValueNode(Node *node)
        {
            Node* current = node;
            while (current != NULL  && current->left != NULL)
                current = current->left;
            return current;
        }
};