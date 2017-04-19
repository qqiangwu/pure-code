//
// Created by wuqq on 18/04/2017.
//

#ifndef PURE_CODE_DIJKSTRA_SP_H
#define PURE_CODE_DIJKSTRA_SP_H

#include <queue>
#include <vector>
#include <limits>

struct PointAndSp {
    unsigned v;
    unsigned sp;
};

struct Edge {
    unsigned to;
    unsigned cost;
};

struct PointAndSpCmp {
    bool operator()(const PointAndSp a, const PointAndSp b) const
    {
        return a.sp > b.sp;
    }
};

// \pre: s and t is in graph
template <class AdjacentList>
int dijkstraSp(const AdjacentList& graph, const unsigned s, const unsigned t)
{
    const auto n = graph.size();

    std::vector<unsigned> sp(n, std::numeric_limits<unsigned>::max());
    sp[s] = 0;

    std::priority_queue<PointAndSp, std::vector<PointAndSp>, PointAndSpCmp> pq;
    pq.push({ s, 0 });

    while (!pq.empty()) {
        auto v = pq.top();
        pq.pop();

        if (v.sp > sp[v.v]) {
            continue;
        }

        for (const auto e: graph[v.v]) {
            const auto from = v.v;
            const auto to = e.to;
            const auto cost = e.cost;

            if (sp[from] + cost < sp[to]) {
                sp[to] = sp[from] + cost;
                pq.push({ to, sp[to] });
            }
        }
    }

    return sp[t];
}

#endif //PURE_CODE_DIJKSTRA_SP_H
