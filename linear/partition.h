//
// Created by wuqq on 17/04/2017.
//

#ifndef PURE_CODE_PARTITION_H
#define PURE_CODE_PARTITION_H

#include <algorithm>

// both ranges are not empty if len > 1
template <class Iter>
Iter partition(Iter first, Iter last)
{
    const auto len = last - first;

    if (len <= 1) {
        return first;
    }

    const auto& pivot = *first;

    // [begin + 1, aLast) < pivot
    // [aLast, bLast) >= pivot
    auto aLast = first + 1;
    auto bLast = aLast;

    while (bLast != last) {
        if (*bLast < pivot) {
            std::iter_swap(aLast, bLast);
            ++aLast;
        }

        ++bLast;
    }

    --aLast;

    if (aLast == first) {
        return aLast + 1;
    } else {
        std::iter_swap(first, aLast);
        return aLast;
    }
}

#endif //PURE_CODE_PARTITION_H
