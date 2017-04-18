//
// Created by wuqq on 18/04/2017.
//

#ifndef PURE_CODE_FIND_KTH_H
#define PURE_CODE_FIND_KTH_H

#include "partition.h"

template <class Iter>
void findKth(Iter first, Iter mid, Iter last)
{
    while (last - first > 1) {
        auto partitionPoint = partition(first, last);

        // proof: first will advance or last will retreat
        // if len <= 1: end of story
        // if len > 1: partitionPoint will be in (first, last)
        if (partitionPoint <= mid) {
            first = partitionPoint;
        } else {
            last = partitionPoint;
        }
    }

}

#endif //PURE_CODE_FIND_KTH_H
