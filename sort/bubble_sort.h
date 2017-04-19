//
// Created by wuqq on 19/04/2017.
//

#ifndef PURE_CODE_BUBBLE_SORT_H
#define PURE_CODE_BUBBLE_SORT_H

#include <algorithm>

template <class Iter>
void bubbleUp(Iter first, Iter last)
{
    if (last - first <= 1) {
        return;
    }

    for (auto p = first, end = last - 1; p != end; ++p) {
        if (*p > *(p + 1)) {
            std::iter_swap(p, p + 1);
        }
    }
}

template <class Iter>
void bubbleSort(Iter first, Iter last)
{
    // [begin, p) not sorted
    // [p, end) sorted, the most largest elements
    for (auto p = last; p != first; --p) {
        bubbleUp(first, p);
    }
}

#endif //PURE_CODE_BUBBLE_SORT_H
