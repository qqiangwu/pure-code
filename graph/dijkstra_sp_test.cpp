//
// Created by wuqq on 18/04/2017.
//
#include <algorithm>
#include <vector>

#include <gtest/gtest.h>

#include "dijkstra_sp.h"

TEST(DijkstraSP, Line)
{
    std::vector<std::vector<Edge>> graph {
            { { 1U, 1U } },
            { { 2U, 2U } },
            { { 3U, 3U } },
            {}
    };

    ASSERT_EQ(dijkstra_sp(graph, 0, 3), 6);
    ASSERT_EQ(dijkstra_sp(graph, 0, 2), 3);
    ASSERT_EQ(dijkstra_sp(graph, 0, 1), 1);
    ASSERT_EQ(dijkstra_sp(graph, 0, 0), 0);
    ASSERT_EQ(dijkstra_sp(graph, 1, 2), 2);
    ASSERT_EQ(dijkstra_sp(graph, 1, 3), 5);
}

TEST(DijkstraSP, Cycle)
{
    std::vector<std::vector<Edge>> graph {
            { { 1U, 10U }, { 2U, 1U} },
            { { 3U, 4U } },
            { { 1U, 2U } },
            {}
    };

    ASSERT_EQ(dijkstra_sp(graph, 0, 1), 3);
    ASSERT_EQ(dijkstra_sp(graph, 0, 2), 1);
    ASSERT_EQ(dijkstra_sp(graph, 0, 3), 7);
}
