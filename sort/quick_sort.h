//
// Created by wuqq on 19/04/2017.
//

#ifndef PURE_CODE_QUICK_SORT_H
#define PURE_CODE_QUICK_SORT_H

#include "../linear/partition.h"

template <class Iter>
void quickSort(Iter first, Iter last)
{
    if (last - first <= 1) {
        return;
    }

    auto partitionPoint = partition(first, last);

    quickSort(first, partitionPoint);
    quickSort(partitionPoint, last);
}

#endif //PURE_CODE_QUICK_SORT_H
