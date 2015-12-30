#include<iostream>
#include<vector>
#include<cstdlib>
#include "avl.h"


using std::vector;

int main() {
    Tree<int> *tree = new Tree<int>();
    for (size_t i = 0; i < 100; i++)
    {
        tree->insert(rand() % 1000);
    }
    delete tree;
    getchar();
    return 0;
}
