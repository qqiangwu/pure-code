//
// Created by wuqq on 19/04/2017.
//

#ifndef PURE_CODE_MERGE_WITHOUT_BUFFER_H
#define PURE_CODE_MERGE_WITHOUT_BUFFER_H

#include <algorithm>

template <class Iter>
void mergeWithoutBuffer(Iter first, Iter mid, Iter last)
{
    if (first == mid || mid == last) {
        return;
    }

    if (last - first == 2) {
        if (*mid < *first) {
            std::iter_swap(first, mid);
        }
        return;
    }

    const auto len1 = mid - first;
    const auto len2 = last - mid;

    Iter cut1;
    Iter cut2;

    if (len1 < len2) {
        cut2 = mid + len2 / 2;
        cut1 = std::upper_bound(first, mid, *cut2);
    } else {
        cut1 = first + len1 / 2;
        cut2 = std::upper_bound(mid, last, *cut1);
    }

    auto newMid = std::rotate(cut1, mid, cut2);

    mergeWithoutBuffer(first, cut1, newMid);
    mergeWithoutBuffer(newMid, cut2, last);
}

#endif //PURE_CODE_MERGE_WITHOUT_BUFFER_H
