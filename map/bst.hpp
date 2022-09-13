#include<iostream>
template <class T>
struct Node
{
    T  data;
    Node<T> *left;
    Node<T> *right;
    Node<T> *parent;
};

template <class T>
class Tree
{
    public:
        typedef Node<T> Node;
    public:
        Tree(): root(NULL){}
        Node *root;

    Node *newNode(T data)
    {
        Node* n = (Node *)malloc(sizeof(Node));
        n->data = data;
        n->left = NULL;
        n->right = NULL;
        n->parent = NULL;
        return (n);
    }
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
    Node* insert(Node *node, int data)
    {
        if (node == NULL)
            return (newNode(data));
        if (data > node->data)
            node->right = insert(node->right, data);
        else
            node->left = insert(node->left, data);

        int balance_factor = get_balance_factor(node);
        if (balance_factor == 2)
        {
            if (data > node->left->data)
            {
                node = left_right_rotation(root);
            }
            else 
                node = left_left_rotation(root);
        }
        else if (balance_factor == -2)
        {
            if (data < node->right->data)
            {
                node = right_left_rotation(node);
            }
            else 
                node = right_right_rotation(node);
        }
        return (node);
    }
    void    inorder(Node* node)
    {
        if (node == NULL)
            return ;
        inorder(node->left);
        std::cout << node->data << std::endl;
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
    Node * delete_node(Node *node, int data)
    {
        if (node == NULL)
            return node;
        if (data < node->data)
            node->left = delete_node(node->left, data);
        else if (data > node->data)
            node->right = delete_node(node->right, data);
        else
        {
            if (node->left == NULL && node->right == NULL)
                return NULL;
            else if (node->left == NULL)
            {
                Node *temp = node->right;
                free(node);
                return temp;
            }
            else if (node->right == NULL)
            {
                Node *temp = node->left;
                free(node);
                return temp;
            }
            Node *temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = delete_node(node->right, temp->data);
        }
        if (get_balance_factor(node) > 1 &&
            get_balance_factor(node->left) >= 0)
            return right_rotate(node);
        if (get_balance_factor(node) > 1 &&
            get_balance_factor(node->left ) < 0)
        {
            node->left = left_rotate(node->left);
            return right_rotate(node);
        }
        if (get_balance_factor(node) < -1 && 
            get_balance_factor(node->right) <= 0)
            return left_rotate(node);
        if (get_balance_factor(node) < -1 &&
            get_balance_factor(node->right) > 0)
        {
            node->right = right_rotate(node->right);
            return left_rotate(node);
        }

        return node;
    }
};