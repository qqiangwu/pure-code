//
// Created by wuqq on 19/04/2017.
//

#include <gtest/gtest.h>

#include <algorithm>
#include <cstdlib>
#include <vector>
#include <numeric>

#include "merge_with_buffer.h"

TEST(MergeWithBuffer, Empty) {
    std::vector<int> vec;

    mergeWithBuffer(vec.begin(), vec.begin(), vec.end());
}

TEST(MergeWithBuffer, OneSideEmpty) {
    for (int i = 0; i < 10; ++i) {
        std::vector<int> vec(i);

        std::iota(vec.begin(), vec.end(), i);

        mergeWithBuffer(vec.begin(), vec.begin(), vec.end());

        ASSERT_TRUE(std::is_sorted(vec.begin(), vec.end()));
    }

    for (int i = 0; i < 10; ++i) {
        std::vector<int> vec(i);

        std::iota(vec.begin(), vec.end(), i);

        mergeWithBuffer(vec.begin(), vec.end(), vec.end());

        ASSERT_TRUE(std::is_sorted(vec.begin(), vec.end()));
    }
}

TEST(MergeWithBuffer, SameOrdered)
{
    for (int i = 0; i < 10; ++i) {
        for (int k = 0; k < i; ++k) {
            std::vector<int> vec(i, i);

            mergeWithBuffer(vec.begin(), vec.begin() + k, vec.end());

            ASSERT_TRUE(std::is_sorted(vec.begin(), vec.end()));
        }
    }
}

TEST(MergeWithBuffer, Ordered)
{
    for (int i = 0; i < 10; ++i) {
        for (int k = 0; k < i; ++k) {
            std::vector<int> vec(i);
            std::iota(vec.begin(), vec.end(), i);

            mergeWithBuffer(vec.begin(), vec.begin() + k, vec.end());

            ASSERT_TRUE(std::is_sorted(vec.begin(), vec.end()));
        }
    }
}

TEST(MergeWithBuffer, Random)
{
    for (int i = 0; i < 50; ++i) {
        for (int k = 0; k < i; ++k) {
            std::vector<int> vec(i);

            auto mid = vec.begin() + k;

            std::generate(vec.begin(), vec.end(), []{ return std::rand(); });

            std::sort(vec.begin(), mid);
            std::sort(mid, vec.end());

            mergeWithBuffer(vec.begin(), mid, vec.end());

            ASSERT_TRUE(std::is_sorted(vec.begin(), vec.end()));
        }
    }
}