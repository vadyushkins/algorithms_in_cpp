#include <gtest/gtest.h>

#include "bridges.hpp"

TEST(Bridges, Test0) {
    std::vector<std::vector<int64_t>> graph = {
        {1, 2},
        {0},
        {0},
    };
    std::vector<std::pair<int64_t, int64_t>> bridges = bridges_search(graph);

    std::vector<std::pair<int64_t, int64_t>> expected_bridges = {{0, 1}, {0, 2}};

    ASSERT_EQ(bridges, expected_bridges);
}

TEST(Bridges, Test1) {
    std::vector<std::vector<int64_t>> graph = {
        {1, 2},
        {0, 2},
        {0, 1, 3},
        {2},
    };
    std::vector<std::pair<int64_t, int64_t>> bridges = bridges_search(graph);

    std::vector<std::pair<int64_t, int64_t>> expected_bridges = {{2, 3}};

    ASSERT_EQ(bridges, expected_bridges);
}

TEST(Bridges, Test2) {
    std::vector<std::vector<int64_t>> graph = {
        {1, 5, 7},
        {0, 2},
        {1, 3, 5, 7},
        {2, 4},
        {3},
        {0, 2, 6},
        {5},
        {0, 2, 8},
        {7},
    };
    std::vector<std::pair<int64_t, int64_t>> bridges = bridges_search(graph);

    std::vector<std::pair<int64_t, int64_t>> expected_bridges = {
        {3, 4},
        {2, 3},
        {5, 6},
        {7, 8},
    };

    ASSERT_EQ(bridges, expected_bridges);
}

TEST(Bridges, Test3) {
    std::vector<std::vector<int64_t>> graph = {
        {1, 2},
        {0, 2},
        {0, 1},
    };
    std::vector<std::pair<int64_t, int64_t>> bridges = bridges_search(graph);

    std::vector<std::pair<int64_t, int64_t>> expected_bridges = {};

    ASSERT_EQ(bridges, expected_bridges);
}