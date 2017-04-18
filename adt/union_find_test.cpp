//
// Created by wuqq on 18/04/2017.
//
#include <algorithm>
#include <gtest/gtest.h>

#include "union_find.h"


TEST(UnionFind, Simple)
{
    UnionFind uf(10);

    for (int i = 0; i < 10; ++i) {
        ASSERT_EQ(uf.find(i), i);
    }

    for (int i = 0; i < 3; ++i) {
        uf.unite(i, 9 - i);
    }

    for (int i = 0; i < 3; ++i) {
        ASSERT_EQ(uf.find(i), uf.find(9 - i));
    }

    ASSERT_NE(uf.find(0), uf.find(1));
    ASSERT_NE(uf.find(0), uf.find(2));
}

TEST(UnionFind, Random)
{
    for (int i = 0; i < 100; ++i) {
        UnionFind uf(i);

        for (int k = 0; k < i; ++k) {
            ASSERT_EQ(uf.find(k), k);
        }

        for (int k = 0; k < i / 3; ++k) {
            const auto other = i - k - 2;

            uf.unite(k, other);
        }

        for (int k = 0; k < i / 3; ++k) {
            const auto other = i - k - 2;

            ASSERT_EQ(uf.find(k), uf.find(other));
            ASSERT_NE(uf.find(k), uf.find(i - 1));
        }
    }
}