#include "dfs.hpp"

std::vector<bool> &dfs(
    const std::vector<std::vector<int64_t>> &graph,
    std::vector<bool> &reachable,
    int64_t node
) {
    reachable[node] = true;
    for (int64_t neighbour : graph[node]) {
        if (false == reachable[neighbour]) {
            dfs(graph, reachable, neighbour);
        }
    }
    return reachable;
}