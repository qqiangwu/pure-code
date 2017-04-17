//
// Created by wuqq on 17/04/2017.
//

#ifndef PURE_CODE_UTILS_H
#define PURE_CODE_UTILS_H

#include <algorithm>

template <class Iter>
bool isPartition(Iter first, Iter mid, Iter last)
{
    if (first == mid || mid == last) {
        return true;
    }

    const auto maxV = *std::max_element(first, mid);
    const auto minV = *std::min_element(mid, last);

    return maxV <= minV;
}

#endif //PURE_CODE_UTILS_H
