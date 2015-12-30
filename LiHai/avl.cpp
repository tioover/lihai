#include "avl.h"
#define MAX(a,b) (a>b) ? a : b


Node::Node(Data d)
    : data(d)
{
    left = right = parent = nullptr;
    height = 0;
};


Node::~Node()
{
    delete this->left;
    delete this->right;
}


Node *insert(Node *tree, Data x)
{
    if (tree == nullptr)
    {
        return new Node(x);
    }
    if (x < tree->data)
    {
        tree->left = insert(tree->left, x);
        if (height(tree->left) - height(tree->right) == 2)
        {
            if (x < tree->left->data)
            {
                tree = single_rotate_with_left(tree);
            }
            else
            {
                tree = double_rotate_with_left(tree);
            }
        }
    }
    else if (x > tree->data)
    {
        tree->right = insert(tree->right, x);
        if (height(tree->right) - height(tree->left) == 2)
        {
            if (x > tree->right->data)
            {
                tree = single_rotate_with_right(tree);
            }
            else
            {
                tree = double_rotate_with_right(tree);
            }
        }

    }
    tree->height = MAX(height(tree->left), height(tree->right)) + 1;
    return tree;
}


Node *single_rotate_with_right(Node *tree) {
    Node *new_tree;
    new_tree = tree->right;
    tree->right = new_tree->left;
    new_tree->left = tree;
    tree->height = MAX(height(tree->right), height(tree->left)) + 1;
    new_tree->height = MAX(height(new_tree->right), height(tree)) + 1;
    return new_tree;
}


Node *single_rotate_with_left(Node *tree) {
    Node *new_tree;
    new_tree = tree->left;
    tree->left = new_tree->right;
    new_tree->right = tree;
    tree->height = MAX(height(tree->right), height(tree->left)) + 1;
    new_tree->height = MAX(height(new_tree->left), height(tree)) + 1;
    return new_tree;

}

Node *double_rotate_with_right(Node *tree) {
    tree->right = single_rotate_with_left(tree->right);
    return single_rotate_with_right(tree);
}

Node *double_rotate_with_left(Node *tree) {
    tree->left = single_rotate_with_right(tree->left);
    return single_rotate_with_left(tree);
}

int height(Node *node) {
    if (node == nullptr)
    {
        return -1;
    }
    else
    {
        return node->height;
    }
}

