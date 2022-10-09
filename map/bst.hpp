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
        unsigned int height;
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
            if (tmp->parent != NULL && root->data.first < tmp->parent->data.first)
                tmp->parent->left = tmp;
            else 
            {
                if (tmp->parent != NULL)
                    tmp->parent->right = tmp;
            }
            root = tmp;
            update_height(root->left);
            update_height(root->right);
            update_height(root);
            update_height(root->parent);
            return root;
        }
        void update_height(Node* root)
        {
            if (root != NULL) 
            {
                int val = 1;
                if (root->left != NULL)
                    val = root->left->height + 1;
                if (root->right != NULL)
                    val = max(val, root->right->height + 1);
                root->height = val;
            }
        }
        int max(int a, int b)
        {
            if (a > b)
                return (a);
            return b;
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
            if (tmp->parent != NULL && root->data.first < tmp->parent->data.first)
                tmp->parent->left = tmp;
            else
            {
                if (tmp->parent != NULL)
                    tmp->parent->right = tmp;
            }
            root = tmp;
            update_height(root->left);
            update_height(root->right);
            update_height(root);
            update_height(root->parent);
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
        Node* balance_node(Node* root)
        {
            int firstheight = 0;
            int secondheight = 0;
            if (root->left != NULL)
                firstheight = root->left->height;
            if (root->right != NULL)
                secondheight = root->right->height;
            if (abs(firstheight - secondheight) == 2)
            {
                if (firstheight < secondheight)
                {
                    int rightheight1 = 0;
                    int rightheight2 = 0;
                    if (root->right->right != NULL)
                        rightheight2 = root->right->right->height;
                    if (root->right->left != NULL)
                        rightheight1 = root->right->left->height;
                    if (rightheight1 > rightheight2)
                    {
                        root = right_left_rotation(root);
                    }
                    else
                    {
                        root = right_right_rotation(root);
                    }
                }
                else
                {
                    int leftheight1 = 0;
                    int leftheight2 = 0;
                    if (root->left->right != NULL)
                        leftheight2 = root->left->right->height;
                    if (root->left->left != NULL)
                        leftheight1 = root->left->left->height;
                    if (leftheight1 > leftheight2)
                    {
                        root = left_left_rotation(root);
                    }
                    else
                    {
                        root = left_right_rotation(root);
                    }
                }
            }
            return root;
        }
        Node* delete_node(Node* root, key_type key)
        {
            if (root != NULL)
            {
                if (root->data.first == key)
                {
                    if (root->right == NULL && root->left != NULL)
                    {
                        if (root->parent != NULL)
                        {
                            if (root->parent->data.first < root->data.first)
                                root->parent->right = root->left;
                            else
                                root->parent->left = root->left;
                            update_height(root->parent);
                        }
                        root->left->parent = root->parent;
                        root->left = balance_node(root->left);
                        return root->left;
                    }
                    else if (root->left == NULL && root->right != NULL)
                    {
                        if (root->parent != NULL)
                        {
                            if (root->parent->data.first < root->data.first)
                                root->parent->right = root->right;
                            else
                                root->parent->left = root->right;
                            update_height(root->parent);
                        }
                        root->right->parent = root->parent;
                        root->right = balance_node(root->right);
                        return root->right;
                    }
                    else if (root->left == NULL && root->right == NULL)
                    {
                        if (root->parent->data.first < root->data.first)
                        {
                            root->parent->right = NULL;
                        }
                        else
                        {
                            root->parent->left = NULL;
                        }
                        if (root->parent != NULL)
                            update_height(root->parent);
                        root = NULL;
                        return NULL;
                    }
                    else
                    {
                        Node* tmpnode = root;
                        tmpnode = tmpnode->right;
                        while (tmpnode->left != NULL)
                        {
                            tmpnode = tmpnode->left;
                        }
                        int val = tmpnode->data.first;
                        root->right = delete_node(root->right, tmpnode->data.first);
                        root->data.first = val;
                        root = balance_node(root);
                    }
                }
                else if (root->data.first < key)
                {
                    root->right = delete_node(root->right, key);
                    root = balance_node(root);
                }
                else if (root->data.first > key)
                {
                    root->left = delete_node(root->left, key);
                    root = balance_node(root);
                }
                if (root != NULL)
                {
                    update_height(root);
                }
            }
            else
            {}
            return root;
        }
 
        // Node * delete_node(Node *node, key_type key)
        // {
        // 	if (node != NULL)
        // 	{
        //         if (node->data.first == key)
        //         { 
		// 			if (node->right == NULL
		// 				&& node->left != NULL) {
		// 				if (node->parent != NULL)
		// 				{
		// 					if (node->parent->data.first
		// 						< node->data.first)
		// 						node->parent->right = node->left;
		// 					else
		// 						node->parent->left = node->left;
		// 				}
		// 				node->left->parent = node->parent;
		// 				node->left = balance_tree(node->left, key);
		// 				return node->left;
        //         }
        //         	else if (node->left == NULL
        //                 && node->right != NULL) {
        //             if (node->parent != NULL) {
        //                 exit(0);
        //                 if (node->parent->data.first
        //                     < node->data.first)
        //                     node->parent->right = node->right;
        //                 else
        //                     node->parent->left = node->right;
        //             }
        //             node->right->parent = node->parent;
        //             node->right = balance_tree(node->right, key);
        //             return node->right;
        //         }
        //         	else if (node->left == NULL
        //                 && node->right == NULL)
		// 			{
		// 				if (node->parent->data.first < node->data.first)
		// 				{
		// 					node->parent->right = NULL;
		// 				}
		// 				else
		// 				{
		// 					node->parent->left = NULL;
		// 				}
		// 				node = NULL;
		// 				return NULL;
        //     		}
		// 			else
		// 			{
		// 				// exit(0);
		// 				Node* tmpnode = node;
		// 				tmpnode = tmpnode->right;
		// 				while (tmpnode->left != NULL) {
		// 					tmpnode = tmpnode->left;
		// 				}
		// 				int val = tmpnode->data.first;
		// 				node->right = delete_node(node->right, tmpnode->data.first);
		// 				node->data.first = val;
		// 				node = balance_tree(node, key);
		// 			}
        // 		}
		// 		else if (node->data.first < key)
		// 		{
		// 			node->right = delete_node(node->right, key);
		// 			node = balance_tree(node, key);
		// 		}
		// 		else if (node->data.first > key)
		// 		{
		// 			node->left = delete_node(node->left, key);
		// 			node = balance_tree(node, key);
		// 		}
    	// 	}
        // 	return node;
    	// }
        
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
        Node* insert(Node *root, Node *parent, value_type data)
        {
            if (root == NULL)
            {
                root = _node_allocator.allocate(1);
                _node_allocator.construct(root, data);
                root->parent = parent;
                root->left = NULL;
                root->right = NULL;
                root->height = 1;
                return (root);
            }
            else if (data.first > root->data.first)
            {
                // std::cout << "b" << std::endl;
                root->right = insert(root->right, root, data);
                int first_height = 0;
                int second_height = 0;

                if (root->left != NULL)
                    first_height = root->left->height;
                if (root->right != NULL)
                    second_height = root->right->height;
                if (std::abs(first_height - second_height) == 2)
                {
                    if (root->right != NULL && root->data.first < root->right->data.first)
                    {
                        root = right_left_rotation(root);
                    }
                    else
                        root = right_right_rotation(root);
                }
            }
            else if (data.first < root->data.first)
            {
                root->left = insert(root->left, root, data);
                // std::cout << data.first << std::endl;
                // std::cout << root->data.first << std::endl;
                // std::cout << data.first << std::endl;
                int first_height = 0;
                int second_height = 0;
                if (root->left != NULL)
                    first_height = root->left->height;
                if (root->right != NULL)
                    second_height = root->right->height;
                if (std::abs(first_height - second_height) == 2)
                {
                    if (root->left != NULL && data.first  < root->left->data.first)
                        root = left_left_rotation(root);
                    else
                        root = left_right_rotation(root);
                }
            }
            else
            {}
            return (root);
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