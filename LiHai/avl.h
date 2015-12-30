#pragma once


typedef int Data;

class Node
{
    friend int height(Node *node);
    friend Node *insert(Node*, Data);
    friend Node *single_rotate_with_left(Node*);
    friend Node *double_rotate_with_left(Node*);
    friend Node *single_rotate_with_right(Node*);
    friend Node *double_rotate_with_right(Node*);
public:
    Node(Data);
    ~Node();

    Data data;
private:
    Node *left;
    Node *right;
    Node *parent;
    int height;
};
