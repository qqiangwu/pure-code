//
// Created by wuqq on 19/04/2017.
//

#include <gtest/gtest.h>

#include <algorithm>
#include <cstdlib>
#include <vector>
#include <numeric>

#include "merge_without_buffer.h"

TEST(MergeWithoutBuffer, Empty) {
    std::vector<int> vec;

    mergeWithoutBuffer(vec.begin(), vec.begin(), vec.end());
}

TEST(MergeWithoutBuffer, OneSideEmpty) {
    for (int i = 0; i < 30; ++i) {
        for (int k = 0; k < i; ++k) {
            std::vector<int> vec(i);

            auto mid = vec.begin() + k;

            std::fill(vec.begin(), mid, 0);
            std::fill(mid, vec.end(), 1);

            mergeWithoutBuffer(vec.begin(), mid, vec.end());

            ASSERT_TRUE(std::is_sorted(vec.begin(), vec.end()));
        }
    }
}

TEST(MergeWithoutBuffer, SameOrdered)
{
    for (int i = 0; i < 30; ++i) {
        for (int k = 0; k < i; ++k) {
            std::vector<int> vec(i, i);

            mergeWithoutBuffer(vec.begin(), vec.begin() + k, vec.end());

            ASSERT_TRUE(std::is_sorted(vec.begin(), vec.end()));
        }
    }
}

TEST(MergeWithoutBuffer, Ordered)
{
    for (int i = 0; i < 30; ++i) {
        for (int k = 0; k < i; ++k) {
            std::vector<int> vec(i);
            std::iota(vec.begin(), vec.end(), i);

            mergeWithoutBuffer(vec.begin(), vec.begin() + k, vec.end());

            ASSERT_TRUE(std::is_sorted(vec.begin(), vec.end()));
        }
    }
}

TEST(MergeWithoutBuffer, Random)
{
    for (int i = 0; i < 100; ++i) {
        for (int k = 0; k < i; ++k) {
            std::vector<int> vec(i);

            auto mid = vec.begin() + k;

            std::generate(vec.begin(), vec.end(), []{ return std::rand(); });

            std::sort(vec.begin(), mid);
            std::sort(mid, vec.end());

            mergeWithoutBuffer(vec.begin(), mid, vec.end());

            ASSERT_TRUE(std::is_sorted(vec.begin(), vec.end()));
        }
    }
}