#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include "common.h"
#include "avl.h"

using std::vector;
using Data = i64;
using Tree = avl::Tree<Data>;
const static Data MAX = 1000;


int main() {
    Data a = Data();
    auto *tree = new Tree();
    auto data = vector<Data>{};
    for (Data i = 0; i < MAX; i++) { data.push_back(i); }
    std::random_shuffle(ITER(data));
    std::for_each(ITER(data), [&](auto i) { tree->insert(i); });
    Tree::Result result;
    for (;;)
    {
        std::cin >> a;
        if (a == -1) { break; }
        result = tree->search(&a);
        if (result.is_none())
        {
            std::cout << "Not Found" << std::endl;
        }
        else
        {
            std::cout << "Found: " << *(result.get()) << std::endl;
        }
    }
    delete tree;
    return 0;
}
