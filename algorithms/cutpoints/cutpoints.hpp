#pragma once

#include <vector>
#include <cstdint>
#include <functional>

std::vector<int64_t> cutpoints_search(
    const std::vector<std::vector<int64_t>> &graph
);