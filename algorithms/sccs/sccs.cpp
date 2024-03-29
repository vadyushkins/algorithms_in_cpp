#include "sccs.hpp"

std::vector<std::vector<int64_t>> strongly_connected_components_search(
    const std::vector<std::vector<int64_t>> &graph
) {
    int64_t n = static_cast<int64_t>(graph.size());
    std::vector<bool> visited(n, false);

    std::vector<int64_t> condensation_order;

    std::function<void(int64_t)> compute_order;
    compute_order = [&](int64_t node) {
        visited[node] = true;
        for (int64_t neighbour : graph[node]) {
            if (false == visited[neighbour]) {
                compute_order(neighbour);
            }
        }
        condensation_order.push_back(node);
    };

    for (int64_t i = 0; i < n; ++i) {
        if (false == visited[i]) {
            compute_order(i);
        }
    }

    std::vector<std::vector<int64_t>> transposed_graph(n);
    for (int64_t i = 0; i < n; ++i) {
        for (int64_t j : graph[i]) {
            transposed_graph[j].push_back(i);
        }
    }

    visited.assign(n, false);

    std::vector<int64_t> strongly_connected_component;

    std::function<void(int64_t)> compute_strongly_connected_component;
    compute_strongly_connected_component = [&](int64_t node) {
        visited[node] = true;
        strongly_connected_component.push_back(node);

        for (int64_t neighbour : transposed_graph[node]) {
            if (false == visited[neighbour]) {
                compute_strongly_connected_component(neighbour);
            }
        }
    };

    std::vector<std::vector<int64_t>> result;
    for (int64_t i = n - 1; i >= 0; --i) {
        int64_t node = condensation_order[i];
        if (false == visited[node]) {
            compute_strongly_connected_component(node);
            result.emplace_back(strongly_connected_component);
            strongly_connected_component.clear();
        }
    }

    return result;
}