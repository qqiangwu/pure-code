//
// Created by wuqq on 19/04/2017.
//

#ifndef PURE_CODE_HEAP_SORT_H
#define PURE_CODE_HEAP_SORT_H

#include <algorithm>

template <class Iter>
void heapSort(Iter first, Iter last)
{
    std::make_heap(first, last);

    for (auto p = last; p != first; --p) {
        std::pop_heap(first, p);
    }
}

#endif //PURE_CODE_HEAP_SORT_H
