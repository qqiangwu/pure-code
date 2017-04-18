//
// Created by wuqq on 18/04/2017.
//

#ifndef PURE_CODE_UNION_FIND_H
#define PURE_CODE_UNION_FIND_H

#include <algorithm>
#include <vector>

class UnionFind {
    std::vector<int> _parent;
    std::vector<int> _rank;

public:
    UnionFind(const int n)
            : _parent(n, 0),
              _rank(n, 1)
    {
        for (int i = 0; i < n; ++i) {
            _parent[i] = i;
        }
    }

    int find(const int x)
    {
        if (x == _parent[x]) {
            return x;
        } else {
            return _parent[x] = find(_parent[x]);
        }
    }

    void unite(const int x, const int y)
    {
        auto px = _parent[x];
        auto py = _parent[y];

        if (px != py) {
            if (_rank[px] < _rank[py]) {
                _parent[x] = py;
            } else {
                _parent[y] = px;

                if (_rank[px] == _rank[py]) {
                    ++_rank[px];
                }
            }
        }
    }
};

#endif //PURE_CODE_UNION_FIND_H
