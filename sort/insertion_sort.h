//
// Created by wuqq on 19/04/2017.
//

#ifndef PURE_CODE_INSERTION_SORT_H
#define PURE_CODE_INSERTION_SORT_H

#include <algorithm>

template <class Iter>
void linearInsert(Iter first, Iter last)
{
    auto insertionPoint = std::upper_bound(first, last, *last);

    std::rotate(insertionPoint, last, last + 1);
}

template <class Iter>
void insertionSort(Iter first, Iter last)
{
    // [begin, p) sorted
    // [p, end) to be processed
    for (auto p = first; p != last; ++p) {
        linearInsert(first, p);
    }
}

#endif //PURE_CODE_INSERTION_SORT_H
