#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<cstdlib>
#include "../LiHai/common.h"
#include "../LiHai/avl.h"


namespace Test
{		
    TEST_CLASS(AvlTreeTest)
    {
    using Data = i64;
    using Tree = avl::Tree<Data>;
    const Data MAX = 1000;
	public:
        TEST_METHOD(add_and_search)
		{
            auto *tree = new Tree();
            auto data = std::vector<Data>(MAX);
            std::iota(ITER(data), 0);
            std::random_shuffle(ITER(data));
            std::for_each(ITER(data), [&](auto i) { tree->insert(i); });
            Tree::Result result;
            Data *p;
            for (Data i = 0; i < MAX; i++)
            {
                result = tree->search(&i);
                Assert::IsFalse(result.is_none());
                p = result.get();
                Assert::IsNotNull(p);
                Assert::IsTrue(i == *p);
            }
            delete tree;
        }
    };
}

