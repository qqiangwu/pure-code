//
// Created by wuqq on 18/04/2017.
//

#ifndef PURE_CODE_FIND_KTH_OF_2_H
#define PURE_CODE_FIND_KTH_OF_2_H

#include <algorithm>

// find the kth element of two sorted arrays
// if both ranges are empty, the behavior is undefined
template <class Iter>
int findKthOf2(Iter first1, Iter last1, Iter first2, Iter last2, const int k)
{
    if (last1 - first1 > last2 - first2) {
        return findKthOf2(first2, last2, first1, last1, k);
    }

    auto l = first1 + std::max<int>(0, k - (last2 - first2));
    auto r = first1 + std::min<int>(k, last1 - first1);

    while (l != r) {
        const auto mid1 = l + (r - l) / 2;
        const auto mid2 = first2 + (k - (mid1 - first1));

        if (mid2 != first2 && *mid1 < *(mid2 - 1)) {
            l = mid1 + 1;
        } else {
            r = mid1;
        }
    }

    const auto len1 = l - first1;
    const auto len2 = k - len1;

    if (len1 == last1 - first1) {
        return first2[len2];
    } else if (len2 == last2 - first2) {
        return first1[len1];
    } else {
        return std::min(first1[len1], first2[len2]);
    }
}

#endif //PURE_CODE_FIND_KTH_OF_2_H
