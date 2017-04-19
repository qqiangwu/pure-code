//
// Created by wuqq on 19/04/2017.
//

#include <gtest/gtest.h>

#include <vector>
#include <numeric>
#include <algorithm>

#include "bubble_sort.h"

TEST(BubbleSort, Empty)
{
    std::vector<int> v;

    bubbleSort(v.begin(), v.end());

    ASSERT_TRUE(v.empty());
}

TEST(BubbleSort, Equal)
{
    for (int i = 0; i < 10; ++i) {
        std::vector<int> vec(i, i);

        bubbleSort(vec.begin(), vec.end());

        ASSERT_TRUE(std::is_sorted(vec.begin(), vec.end()));
    }
}

TEST(BubbleSort, Asc)
{
    for (int i = 0; i < 100; ++i) {
        std::vector<int> vec(i);
        std::iota(vec.begin(), vec.end(), i);

        bubbleSort(vec.begin(), vec.end());

        ASSERT_TRUE(std::is_sorted(vec.begin(), vec.end()));
    }
}

TEST(BubbleSort, Des)
{
    for (int i = 0; i < 100; ++i) {
        std::vector<int> vec(i);
        std::iota(vec.rbegin(), vec.rend(), i);

        bubbleSort(vec.begin(), vec.end());

        ASSERT_TRUE(std::is_sorted(vec.begin(), vec.end()));
    }
}

TEST(BubbleSort, Random)
{
    for (int i = 0; i < 100; ++i) {
        std::vector<int> vec(i);
        std::generate(vec.begin(), vec.end(), []{ return std::rand(); });

        bubbleSort(vec.begin(), vec.end());

        ASSERT_TRUE(std::is_sorted(vec.begin(), vec.end()));
    }
}