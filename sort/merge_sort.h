//
// Created by wuqq on 19/04/2017.
//

#ifndef PURE_CODE_MERGE_SORT_H
#define PURE_CODE_MERGE_SORT_H

#include <algorithm>

template <class Iter>
void mergeSort(Iter first, Iter last)
{
    const auto len = last - first;

    if (len <= 1) {
        return;
    }

    auto mid = first + len / 2;

    mergeSort(first, mid);
    mergeSort(mid, last);

    std::inplace_merge(first, mid, last);
}

#endif //PURE_CODE_MERGE_SORT_H
