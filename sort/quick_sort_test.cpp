//
// Created by wuqq on 19/04/2017.
//

#include <gtest/gtest.h>

#include <vector>
#include <numeric>
#include <algorithm>

#include "quick_sort.h"

TEST(QuickSort, Empty)
{
    std::vector<int> v;

    quickSort(v.begin(), v.end());

    ASSERT_TRUE(v.empty());
}

TEST(QuickSort, Equal)
{
    for (int i = 0; i < 10; ++i) {
        std::vector<int> vec(i, i);

        quickSort(vec.begin(), vec.end());

        ASSERT_TRUE(std::is_sorted(vec.begin(), vec.end()));
    }
}

TEST(QuickSort, Asc)
{
    for (int i = 0; i < 100; ++i) {
        std::vector<int> vec(i);
        std::iota(vec.begin(), vec.end(), i);

        quickSort(vec.begin(), vec.end());

        ASSERT_TRUE(std::is_sorted(vec.begin(), vec.end()));
    }
}

TEST(QuickSort, Des)
{
    for (int i = 0; i < 100; ++i) {
        std::vector<int> vec(i);
        std::iota(vec.rbegin(), vec.rend(), i);

        quickSort(vec.begin(), vec.end());

        ASSERT_TRUE(std::is_sorted(vec.begin(), vec.end()));
    }
}

TEST(QuickSort, Random)
{
    for (int i = 0; i < 100; ++i) {
        std::vector<int> vec(i);
        std::generate(vec.begin(), vec.end(), []{ return std::rand(); });

        quickSort(vec.begin(), vec.end());

        ASSERT_TRUE(std::is_sorted(vec.begin(), vec.end()));
    }
}