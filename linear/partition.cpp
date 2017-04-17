//
// Created by wuqq on 17/04/2017.
//

#include <random>
#include <vector>
#include <algorithm>

#include <gtest/gtest.h>
#include "partition.h"
#include "utils.h"

TEST(OnePassPartition, NotSorted)
{
    std::default_random_engine engine;
    std::uniform_int_distribution<> dist(0, 1000);

    for (int i = 0; i < 100; i += 1) {
        std::vector<int> vec(i);

        std::generate(vec.begin(), vec.end(), std::bind(dist, engine));

        auto cut = partition(vec.begin(), vec.end());

        ASSERT_TRUE(isPartition(vec.begin(), cut, vec.end()));
    }
}

TEST(OnePassPartition, SortedAsc)
{
    std::default_random_engine engine;
    std::uniform_int_distribution<> dist(0, 1000);

    for (int i = 0; i < 100; i += 1) {
        std::vector<int> vec(i);

        std::generate(vec.begin(), vec.end(), std::bind(dist, engine));
        std::sort(vec.begin(), vec.end());

        auto cut = partition(vec.begin(), vec.end());

        ASSERT_TRUE(isPartition(vec.begin(), cut, vec.end()));
    }
}

TEST(OnePassPartition, SortedDes)
{
    std::default_random_engine engine;
    std::uniform_int_distribution<> dist(0, 1000);

    for (int i = 0; i < 100; i += 1) {
        std::vector<int> vec(i);

        std::generate(vec.begin(), vec.end(), std::bind(dist, engine));
        std::sort(vec.begin(), vec.end(), std::greater<int>{});

        auto cut = partition(vec.begin(), vec.end());

        if (!isPartition(vec.begin(), cut, vec.end())) {
            std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>{std::cout, ","});
            std::cout << std::endl;
            std::copy(vec.begin(), cut, std::ostream_iterator<int>{std::cout, ","});
            std::cout << std::endl;
            std::copy(cut, vec.end(), std::ostream_iterator<int>{std::cout, ","});
            std::cout << std::endl;
        }

        ASSERT_TRUE(isPartition(vec.begin(), cut, vec.end()));
    }
}