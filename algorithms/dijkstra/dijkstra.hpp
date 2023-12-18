#include <vector>
#include <cstdint>

std::vector<int64_t> dijkstra(
    const std::vector<std::vector<std::pair<int64_t, int64_t>>> &graph,
    const int64_t source_node
);