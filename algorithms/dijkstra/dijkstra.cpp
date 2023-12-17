#include "dijkstra.hpp"

std::vector<int64_t> dijkstra(
    const std::vector<std::vector<std::pair<int64_t, int64_t>>> graph,
    const int64_t source_node
)
{
    size_t n = graph.size();
    std::vector<int64_t> distance(n, -1);
    std::vector<bool> relaxed(n, false);

    distance[source_node] = 0;
    for (size_t i = 0; i < n; ++i)
    {
        int64_t u = -1;
        for (int64_t j = 0; j < n; ++j)
        {
            if (
                relaxed[j] == false && (
                    u == -1 || (
                        distance[j] != -1 &&
                        distance[j] < distance[u]
                    )
                )
            )
            {
                u = j;
            }
        }
        if (u == -1)
        {
            break;
        }

        for (const auto &[v, w] : graph[u])
        {
            if (
                distance[v] == -1 ||
                distance[v] > distance[u] + w
            )
            {
                distance[v] = distance[u] + w;
            }
        }

        relaxed[u] = true;
    }

    return distance;
}