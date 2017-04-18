//
// Created by wuqq on 18/04/2017.
//
#include "find_kth_of_2.h"
#include <vector>
#include <initializer_list>
#include <gtest/gtest.h>

template <class Iter>
int findKth(Iter first1, Iter last1, Iter first2, Iter last2, const int k)
{
    std::vector<int> vec(first1, last1);

    vec.insert(vec.end(), first2, last2);

    std::sort(vec.begin(), vec.end());

    return vec[k];
}

TEST(FindKthOf2, Emtpty)
{
    std::initializer_list<int> vec1 {};
    std::initializer_list<int> vec2 {1};

    ASSERT_EQ(
            findKth(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), 0),
            findKthOf2(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), 0)
    );

    vec2 = { 1, 2 };
    ASSERT_EQ(
            findKth(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), 0),
            findKthOf2(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), 0)
    );
    ASSERT_EQ(
            findKth(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), 1),
            findKthOf2(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), 1)
    );

    std::swap(vec1, vec2);

    ASSERT_EQ(
            findKth(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), 0),
            findKthOf2(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), 0)
    );
    ASSERT_EQ(
            findKth(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), 1),
            findKthOf2(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), 1)
    );
}

TEST(FindKthOf2, Less)
{
    std::initializer_list<int> vec1 {1,1,1,1};
    std::initializer_list<int> vec2 {2,3,4,5};

    for (int i = 0; i < vec1.size() + vec2.size(); ++i) {
        ASSERT_EQ(
                findKth(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), i),
                findKthOf2(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), i)
        );
    }

    std::swap(vec1, vec2);
    for (int i = 0; i < vec1.size() + vec2.size(); ++i) {
        ASSERT_EQ(
                findKth(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), i),
                findKthOf2(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), i)
        );
    }
}

TEST(FindKthOf2, Greater)
{
    std::initializer_list<int> vec1 {11,11,11,11};
    std::initializer_list<int> vec2 {2,3,4,5};

    for (int i = 0; i < vec1.size() + vec2.size(); ++i) {
        ASSERT_EQ(
                findKth(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), i),
                findKthOf2(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), i)
        );
    }

    std::swap(vec1, vec2);
    for (int i = 0; i < vec1.size() + vec2.size(); ++i) {
        ASSERT_EQ(
                findKth(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), i),
                findKthOf2(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), i)
        );
    }
}

TEST(FindKthOf2, Random)
{

    for (int i = 1; i < 20; ++i) {
        for (int j = 1; j < 20; ++j) {
            std::vector<int> vec1(i);
            std::vector<int> vec2(j);

            std::generate(vec1.begin(), vec1.end(), []{
                return std::rand();
            });
            std::generate(vec2.begin(), vec2.end(), []{
                return std::rand();
            });

            std::sort(vec1.begin(), vec1.end());
            std::sort(vec2.begin(), vec2.end());

            for (int k = 0; k < vec1.size() + vec2.size(); ++k) {
                ASSERT_EQ(
                        findKth(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), k),
                        findKthOf2(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), k)
                );
            }

            std::swap(vec1, vec2);
            for (int k = 0; k < vec1.size() + vec2.size(); ++k) {
                ASSERT_EQ(
                        findKth(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), k),
                        findKthOf2(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), k)
                );
            }
        }
    }
}