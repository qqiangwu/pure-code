//
// Created by wuqq on 19/04/2017.
//
#include <gtest/gtest.h>

#include <vector>
#include <numeric>
#include <algorithm>

#include "insertion_sort.h"

TEST(InsertionSort, Empty)
{
    std::vector<int> v;

    insertionSort(v.begin(), v.end());

    ASSERT_TRUE(v.empty());
}

TEST(InsertionSort, Equal)
{
    for (int i = 0; i < 10; ++i) {
        std::vector<int> vec(i, i);

        insertionSort(vec.begin(), vec.end());

        ASSERT_TRUE(std::is_sorted(vec.begin(), vec.end()));
    }
}

TEST(InsertionSort, Asc)
{
    for (int i = 0; i < 100; ++i) {
        std::vector<int> vec(i);
        std::iota(vec.begin(), vec.end(), i);

        insertionSort(vec.begin(), vec.end());

        ASSERT_TRUE(std::is_sorted(vec.begin(), vec.end()));
    }
}

TEST(InsertionSort, Des)
{
    for (int i = 0; i < 100; ++i) {
        std::vector<int> vec(i);
        std::iota(vec.rbegin(), vec.rend(), i);

        insertionSort(vec.begin(), vec.end());

        ASSERT_TRUE(std::is_sorted(vec.begin(), vec.end()));
    }
}

TEST(InsertionSort, Random)
{
    for (int i = 0; i < 100; ++i) {
        std::vector<int> vec(i);
        std::generate(vec.begin(), vec.end(), []{ return std::rand(); });

        insertionSort(vec.begin(), vec.end());

        ASSERT_TRUE(std::is_sorted(vec.begin(), vec.end()));
    }
}