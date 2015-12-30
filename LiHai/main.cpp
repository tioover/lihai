#include<iostream>
#include "avl.h"


int main() {
    Node *root = nullptr;
    int data[] = { 10, 18, 18, 8, 7, 9, 50, 14, 17, 25 };
    for each (auto i in data)
    {
        root = insert(root, i);
    }
    getchar();
    return 0;
}
