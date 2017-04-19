//
// Created by wuqq on 19/04/2017.
//
#include <vector>
#include <gtest/gtest.h>

#include "floyd_sp.h"

TEST(FloydSP, Cycle)
{
    std::vector<std::vector<int>> graph(3);

    graph[0] = { 0, 1, INT_MAX };
    graph[1] = { INT_MAX, 0, -2 };
    graph[2] = { -3, INT_MAX, 0 };

    ASSERT_EQ(false, floydSp(graph));
}

TEST(FloydSP, NoCycle)
{
    std::vector<std::vector<int>> graph(3);

    graph[0] = { 0, 1, INT_MAX };
    graph[1] = { INT_MAX, 0, -2 };
    graph[2] = { 3, INT_MAX, 0 };

    ASSERT_EQ(true, floydSp(graph));

    ASSERT_EQ(1, graph[0][1]);
    ASSERT_EQ(-1, graph[0][2]);
    ASSERT_EQ(-2, graph[1][2]);
    ASSERT_EQ(1, graph[1][0]);
}

TEST(FloydSP, Normal)
{
    std::vector<std::vector<int>> graph(3);

    graph[0] = { 0, 2, 9 };
    graph[1] = { 8, 0, 6 };
    graph[2] = { 1, INT_MAX, 0 };

    ASSERT_EQ(true, floydSp(graph));

    auto result = std::vector<std::vector<int>> {
            { 0, 2, 8 },
            { 7, 0, 6 },
            { 1, 3, 0 }
    };

    ASSERT_EQ(result, graph);
}