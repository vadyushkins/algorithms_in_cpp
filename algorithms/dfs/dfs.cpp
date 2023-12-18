#include "dfs.hpp"

std::vector<bool> &dfs(
    const std::vector<std::vector<int64_t>> &graph,
    std::vector<bool> &reachable,
    int node
) {
    reachable[node] = true;
    for (int neighbour : graph[node]) {
        if (false == reachable[neighbour]) {
            dfs(graph, reachable, neighbour);
        }
    }
    return reachable;
}