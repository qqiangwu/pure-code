//
// Created by wuqq on 18/04/2017.
//

#include <algorithm>
#include <numeric>
#include <vector>

#include <gtest/gtest.h>
#include "find_kth.h"

TEST(FindKth, Special)
{
    std::vector<int> vec1 {1,2,5,8,0};
    auto vec2 = vec1;

    for (int i = 0, size = vec1.size(); i < size - 1; ++i) {
        findKth(vec1.begin(), vec1.begin() + i, vec1.end());
        std::nth_element(vec2.begin(), vec2.begin() + i, vec2.end());

        ASSERT_EQ(vec2[i], vec1[i]);
    }
}


TEST(FindKth, Equal)
{
    for (int i = 0; i < 100; ++i) {
        std::vector<int> vec1(i, i);
        std::vector<int> vec2 = vec1;

        for (int k = 0; k < int(vec1.size()) - 1; ++k) {
            findKth(vec1.begin(), vec1.begin() + k, vec1.end());
            std::nth_element(vec2.begin(), vec2.begin() + k, vec2.end());

            ASSERT_EQ(vec1[k], vec2[k]);
        }
    }
}

TEST(FindKth, Normal)
{
    for (int i = 0; i < 100; ++i) {
        std::vector<int> vec1(i);

        std::generate(vec1.begin(), vec1.end(), []{ return rand(); });

        auto vec2 = vec1;

        for (int k = 0; k < int(vec1.size()) - 1; ++k) {
            findKth(vec1.begin(), vec1.begin() + k, vec1.end());
            std::nth_element(vec2.begin(), vec2.begin() + k, vec2.end());

            ASSERT_EQ(vec1[k], vec2[k]);
        }
    }
}

TEST(FindKth, SortedAsc)
{
    for (int i = 0; i < 100; ++i) {
        std::vector<int> vec1(i);

        std::iota(vec1.begin(), vec1.end(), i);

        auto vec2 = vec1;

        for (int k = 0; k < int(vec1.size()) - 1; ++k) {
            findKth(vec1.begin(), vec1.begin() + k, vec1.end());
            std::nth_element(vec2.begin(), vec2.begin() + k, vec2.end());

            ASSERT_EQ(vec1[k], vec2[k]);
        }
    }
}

TEST(FindKth, SortedDesc)
{
    for (int i = 0; i < 100; ++i) {
        std::vector<int> vec1(i);

        std::iota(vec1.rbegin(), vec1.rend(), i);

        auto vec2 = vec1;

        for (int k = 0; k < int(vec1.size()) - 1; ++k) {
            findKth(vec1.begin(), vec1.begin() + k, vec1.end());
            std::nth_element(vec2.begin(), vec2.begin() + k, vec2.end());

            ASSERT_EQ(vec1[k], vec2[k]);
        }
    }
}