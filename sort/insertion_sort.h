//
// Created by wuqq on 19/04/2017.
//

#ifndef PURE_CODE_INSERTION_SORT_H
#define PURE_CODE_INSERTION_SORT_H

#include <algorithm>

template <class Iter>
void linearInsert(Iter insertionPos, Iter p)
{
    std::rotate(insertionPos, p, p + 1);
}

template <class Iter>
void insertionSort(Iter first, Iter last)
{
    // [begin, p) sorted
    // [p, end) to be processed
    for (auto p = first; p != last; ++p) {
        auto insertionPoint = std::upper_bound(first, p, *p);

        // insert p to [insertionPoint, p)
        linearInsert(insertionPoint, p);
    }
}

#endif //PURE_CODE_INSERTION_SORT_H
