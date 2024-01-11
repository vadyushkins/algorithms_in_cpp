#pragma once

#include <vector>
#include <cstdint>
#include <functional>

std::vector<std::vector<int64_t>> strongly_connected_components_search(
    const std::vector<std::vector<int64_t>> &graph
);