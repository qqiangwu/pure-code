//
// Created by wuqq on 19/04/2017.
//

#ifndef PURE_CODE_MERGE_WITH_BUFFER_H
#define PURE_CODE_MERGE_WITH_BUFFER_H

#include <algorithm>
#include <vector>

template <class Iter>
void mergeWithBuffer(Iter first, Iter mid, Iter last)
{
    if (first == mid || mid == last) {
        return;
    }

    using ValueType = typename Iter::value_type;

    std::vector<ValueType> output;

    auto p1 = first;
    auto p2 = mid;

    while (p1 != mid && p2 != last) {
        if (*p1 <= *p2) {
            output.push_back(*p1);

            ++p1;
        } else {
            output.push_back(*p2);

            ++p2;
        }
    }

    std::copy(p1, mid, std::back_inserter(output));
    std::copy(p2, last, std::back_inserter(output));

    std::copy(output.begin(), output.end(), first);
}

#endif //PURE_CODE_MERGE_WITH_BUFFER_H
