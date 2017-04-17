#include <gtest/gtest.h>

#include <random>
#include <vector>
#include <algorithm>

#include "unguarded_partition.h"
#include "utils.h"


TEST(UnguardedPartition, NotSorted)
{
    std::default_random_engine engine;
    std::uniform_int_distribution<> dist(0, 1000);

    for (int i = 0; i < 100; i += 1) {
        std::vector<int> vec(i);

        std::generate(vec.begin(), vec.end(), std::bind(dist, engine));

        auto cut = unguardedPartition(vec.begin(), vec.end());

        ASSERT_TRUE(isPartition(vec.begin(), cut, vec.end()));
    }
}

TEST(UnguardedPartition, SortedAsc)
{
    std::default_random_engine engine;
    std::uniform_int_distribution<> dist(0, 1000);

    for (int i = 0; i < 100; i += 1) {
        std::vector<int> vec(i);

        std::generate(vec.begin(), vec.end(), std::bind(dist, engine));
        std::sort(vec.begin(), vec.end());

        auto cut = unguardedPartition(vec.begin(), vec.end());

        ASSERT_TRUE(isPartition(vec.begin(), cut, vec.end()));
    }
}

TEST(UnguardedPartition, SortedDes)
{
    std::default_random_engine engine;
    std::uniform_int_distribution<> dist(0, 1000);

    for (int i = 0; i < 100; i += 1) {
        std::vector<int> vec(i);

        std::generate(vec.begin(), vec.end(), std::bind(dist, engine));
        std::sort(vec.begin(), vec.end(), std::greater<int>{});

        auto cut = unguardedPartition(vec.begin(), vec.end());

        ASSERT_TRUE(isPartition(vec.begin(), cut, vec.end()));
    }
}