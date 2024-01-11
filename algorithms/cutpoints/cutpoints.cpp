#include "cutpoints.hpp"

std::vector<int64_t> cutpoints_search(
    const std::vector<std::vector<int64_t>> &graph
) {
    int64_t n = static_cast<int64_t>(graph.size());
    std::vector<bool> visited(n, false);
    std::vector<int64_t> entry_time(n);
    std::vector<int64_t> lowpoint(n);
    int64_t timer = 0;

    std::vector<int64_t> cutpoints;

    std::function<void(int64_t, int64_t)> dfs;
    dfs = [&](int64_t node, int64_t parent) {
        visited[node] = true;
        entry_time[node] = timer;
        lowpoint[node] = timer;
        timer++;

        int64_t children_count = 0;
        for (int64_t neighbour : graph[node]) {
            if (neighbour == parent) {
                continue;
            }

            if (true == visited[neighbour]) {
                lowpoint[node] = std::min(
                    lowpoint[node],
                    entry_time[neighbour]
                );
            }
            else {
                dfs(neighbour, node);
                lowpoint[node] = std::min(
                    lowpoint[node],
                    lowpoint[neighbour]
                );
                if (
                    lowpoint[neighbour] >= entry_time[node] &&
                    -1 != parent
                ) {
                    cutpoints.push_back(node);
                }
                children_count++;
            }
        }
        if (
            -1 == parent &&
            children_count > 1
        ) {
            cutpoints.push_back(node);
        }
    };

    for (int64_t node = 0; node < n; ++node) {
        if (false == visited[node]) {
            dfs(node, -1);
        }
    }

    return cutpoints;
}