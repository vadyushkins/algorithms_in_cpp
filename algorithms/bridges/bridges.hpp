#pragma once

#include <vector>
#include <cstdint>
#include <functional>

std::vector<std::pair<int64_t, int64_t>> bridges_search(
    const std::vector<std::vector<int64_t>> &graph
);