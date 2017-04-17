//
// Created by wuqq on 17/04/2017.
//

#ifndef PURE_CODE_UNGUARDED_PARTITION_H
#define PURE_CODE_UNGUARDED_PARTITION_H

#include <algorithm>

template <class Iter>
auto mo3(Iter first, Iter mid, Iter last) -> decltype(*first + *last)
{
    const auto a = *first;
    const auto b = *mid;
    const auto c = *last;

    if (a < b) {
        if (b < c) {
            return b;
        } else if (c < a) {
            return a;
        } else {
            return c;
        }
    } else if (a < c) {
        return a;
    } else if (c < b) {
        return b;
    } else {
        return c;
    }
}

// both ranges are not empty if len > 1
template <class Iter>
Iter unguardedPartition(Iter first, Iter last)
{
    const auto len = last - first;

    if (len <= 1) {
        return first;
    }

    auto pivot = mo3(first, first + (last - first) / 2, last - 1);

    // [begin, first) <=
    // [last, end) >=
    // [first, last) unexplored
    while (first < last) {
        while (*first < pivot) {
            ++first;
        }
        // first >= pivot

        --last;

        while (*last > pivot) {
            --last;
        }
        // last <= pivot: either first < pivot or pivot <= first

        if (first < last) {
            std::iter_swap(first, last);

            ++first;
        }
    }

    return first;
}

#endif //PURE_CODE_UNGUARDED_PARTITION_H
