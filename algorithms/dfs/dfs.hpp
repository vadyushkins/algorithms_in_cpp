#include <vector>
#include <cstdint>

std::vector<bool> &dfs(
    const std::vector<std::vector<int64_t>> &graph,
    std::vector<bool> &reachable,
    int node
);