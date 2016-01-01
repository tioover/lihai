#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include "common.h"
#include "avl.h"

using std::vector;


int main() {
    using Data = i64;
    Data a = Data();
    const Data MAX = 1000;
    auto *tree = new Tree<Data>();
    auto data = vector<Data>{};
    for (Data i = 0; i < MAX; i++)
    {
        data.push_back(i);
    }
    std::random_shuffle(data.begin(), data.end());
    std::for_each(data.begin(), data.end(), [&](auto i) { tree->insert(i); });
    decltype(tree->search(nullptr)) result;
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
