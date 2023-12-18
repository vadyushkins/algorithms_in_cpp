#include "bfs.hpp"

std::vector<int64_t> bfs(
    const std::vector<std::vector<int64_t>> &graph,
    int64_t source_node
) {
    std::size_t n = graph.size();
    std::vector<int64_t> distance(n, -1);
    distance[source_node] = 0;
    std::deque<int64_t> queue = {source_node};
    while (false == queue.empty()) {
        int64_t u = queue.front();
        queue.pop_front();
        for (int64_t v : graph[u]) {
            if (-1 == distance[v]) {
                distance[v] = distance[u] + 1;
                queue.push_back(v);
            }
        }
    }
    return distance;
}