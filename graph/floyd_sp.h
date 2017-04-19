//
// Created by wuqq on 19/04/2017.
//

#ifndef PURE_CODE_FLOYD_SP_H
#define PURE_CODE_FLOYD_SP_H

#include <vector>

// \pre graph is not empty
// \return true if no cycles
//
// m[i][i] == 0
// m[i][j] = cost if (i, j) exists
// m[i][j] = INT_MAX if (i, j) not exist
template <class Matrix>
bool floydSp(Matrix& graph)
{
    const auto n = graph.size();
    auto& sp = graph;

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (sp[i][k] != std::numeric_limits<int>::max() &&
                        sp[k][j] != std::numeric_limits<int>::max()) {
                    sp[i][j] = std::min(sp[i][j], sp[i][k] + sp[k][j]);
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (sp[i][i] < 0) {
            return false;
        }
    }

    return true;
}

#endif //PURE_CODE_FLOYD_SP_H
