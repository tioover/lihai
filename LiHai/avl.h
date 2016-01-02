#pragma once
#include<algorithm>
#include "common.h"
namespace avl
{

template <typename T>
class Tree
{
public:
    using Type = T;
    using Result = Maybe<T*>;

    Tree() { this->root = nullptr; };
    Tree(T data) { this->root = Node::insert(nullptr, data); };
    ~Tree() { delete this->root; };
    void insert(T data) { this->root = Node::insert(this->root, data); };
    Result search(T *key)
    {
        if (this->root == nullptr)
        {
            return Maybe<T*>();
        }
        else
        {
            return this->root->search(key);
        }
    }
private:
    class Node;
    Node *root;
};


template <typename T>
class Tree<T>::Node
{
    friend class Tree<T>;
    static Node *insert(Node* tree, T x)
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
        tree->height_ = height(tree->left, tree->right);
        return tree;
    };
    ~Node()
    {
        delete this->left;
        delete this->right;
        LOG("DELETED: " << this->data);
    };
    Maybe<T*> search(T *key)
    {
        if (*key == this->data)
        {
            return Maybe<T*>(&this->data);
        }
        else if (*key < this->data)
        {
            if (this->left == nullptr)
            {
                return Maybe<T*>();
            }
            return this->left->search(key);
        }
        else
        {
            if (this->right == nullptr)
            {
                return Maybe<T*>();
            }
            return this->right->search(key);
        }
    };
    Node(T d)
        : data(d)
    {
        left = right = parent = nullptr;
        height_ = 0;
    };
    T data;
    Node *restrict left;
    Node *restrict right;
    Node *parent;
    int height_;
    static inline int height(Node *node)
    {
        if (node == nullptr)
        {
            return -1;
        }
        else
        {
            return node->height_;
        }
    };
    static inline int height(Node *a, Node *b)
    {
        return std::max(height(a), height(b)) + 1;
    }
    static Node *single_rotate_with_left(Node* tree)
    {
        Node *new_tree;
        new_tree = tree->left;
        tree->left = new_tree->right;
        new_tree->right = tree;
        tree->height_ = height(tree->right, tree->left);
        new_tree->height_ = height(new_tree->left, tree);
        return new_tree;
    };
    static Node *double_rotate_with_left(Node* tree)
    {
        tree->left = single_rotate_with_right(tree->left);
        return single_rotate_with_left(tree);
    };
    static Node *single_rotate_with_right(Node* tree)
    {
        Node *new_tree;
        new_tree = tree->right;
        tree->right = new_tree->left;
        new_tree->left = tree;
        tree->height_ = height(tree->right, tree->left);
        new_tree->height_ = height(new_tree->right, tree);
        return new_tree;
    };
    static Node *double_rotate_with_right(Node* tree)
    {
        tree->right = single_rotate_with_left(tree->right);
        return single_rotate_with_right(tree);
    };
};

}
