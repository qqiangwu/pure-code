//
// Created by wuqq on 19/04/2017.
//

#include <gtest/gtest.h>

#include <vector>
#include <numeric>
#include <algorithm>

#include "heap_sort.h"

TEST(HeapSort, Empty)
{
    std::vector<int> v;

    heapSort(v.begin(), v.end());

    ASSERT_TRUE(v.empty());
}

TEST(HeapSort, Equal)
{
    for (int i = 0; i < 10; ++i) {
        std::vector<int> vec(i, i);

        heapSort(vec.begin(), vec.end());

        ASSERT_TRUE(std::is_sorted(vec.begin(), vec.end()));
    }
}

TEST(HeapSort, Asc)
{
    for (int i = 0; i < 100; ++i) {
        std::vector<int> vec(i);
        std::iota(vec.begin(), vec.end(), i);

        heapSort(vec.begin(), vec.end());

        ASSERT_TRUE(std::is_sorted(vec.begin(), vec.end()));
    }
}

TEST(HeapSort, Des)
{
    for (int i = 0; i < 100; ++i) {
        std::vector<int> vec(i);
        std::iota(vec.rbegin(), vec.rend(), i);

        heapSort(vec.begin(), vec.end());

        ASSERT_TRUE(std::is_sorted(vec.begin(), vec.end()));
    }
}

TEST(HeapSort, Random)
{
    for (int i = 0; i < 100; ++i) {
        std::vector<int> vec(i);
        std::generate(vec.begin(), vec.end(), []{ return std::rand(); });

        heapSort(vec.begin(), vec.end());

        ASSERT_TRUE(std::is_sorted(vec.begin(), vec.end()));
    }
}