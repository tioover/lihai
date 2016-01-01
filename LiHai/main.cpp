#include<iostream>
#include<vector>
#include<cstdlib>
#include "avl.h"


using std::vector;


int main() {
    i64 a;
    auto *tree = new Tree<decltype(a)>();
    decltype(tree->search(nullptr)) data;
    for (size_t i = 0; i < 1000; i++)
    {
        tree->insert(i);
    }
    for (;;)
    {
        std::cin >> a;
        if (a == -1) { break; }
        data = tree->search(&a);
        if (data.is_none())
        {
            std::cout << "Not Found" << std::endl;
        }
        else
        {
            std::cout << "Found: " << *(data.get()) << std::endl;
        }
    }
    delete tree;
    return 0;
}
