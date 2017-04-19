//
// Created by wuqq on 19/04/2017.
//

#include <gtest/gtest.h>

#include <vector>
#include <numeric>
#include <algorithm>

#include "merge_sort.h"

TEST(MergeSort, Empty)
{
    std::vector<int> v;

    mergeSort(v.begin(), v.end());

    ASSERT_TRUE(v.empty());
}

TEST(MergeSort, Equal)
{
    for (int i = 0; i < 10; ++i) {
        std::vector<int> vec(i, i);

        mergeSort(vec.begin(), vec.end());

        ASSERT_TRUE(std::is_sorted(vec.begin(), vec.end()));
    }
}

TEST(MergeSort, Asc)
{
    for (int i = 0; i < 100; ++i) {
        std::vector<int> vec(i);
        std::iota(vec.begin(), vec.end(), i);

        mergeSort(vec.begin(), vec.end());

        ASSERT_TRUE(std::is_sorted(vec.begin(), vec.end()));
    }
}

TEST(MergeSort, Des)
{
    for (int i = 0; i < 100; ++i) {
        std::vector<int> vec(i);
        std::iota(vec.rbegin(), vec.rend(), i);

        mergeSort(vec.begin(), vec.end());

        ASSERT_TRUE(std::is_sorted(vec.begin(), vec.end()));
    }
}

TEST(MergeSort, Random)
{
    for (int i = 0; i < 100; ++i) {
        std::vector<int> vec(i);
        std::generate(vec.begin(), vec.end(), []{ return std::rand(); });

        mergeSort(vec.begin(), vec.end());

        ASSERT_TRUE(std::is_sorted(vec.begin(), vec.end()));
    }
}