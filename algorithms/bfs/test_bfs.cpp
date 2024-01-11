#include <gtest/gtest.h>

#include "bfs.hpp"

TEST(BFS, Test0) {
    std::vector<std::vector<int64_t>> graph = {
        {1, 2},
        {0, 2},
        {0, 1},
    };

    std::vector<int64_t> distance = bfs(graph, 0);

    std::vector<int64_t> expected_distance = {0, 1, 1};

    ASSERT_EQ(distance, expected_distance);
}

TEST(BFS, Test1) {
    std::vector<std::vector<int64_t>> graph = {
        {1},
        {2},
        {},
    };

    std::vector<int64_t> distance = bfs(graph, 0);

    std::vector<int64_t> expected_distance = {0, 1, 2};

    ASSERT_EQ(distance, expected_distance);
}

TEST(BFS, Test2) {
    std::vector<std::vector<int64_t>> graph = {
        {1, 2},
        {0, 2},
        {0, 1},
        {4},
        {3},
    };

    std::vector<int64_t> distance = bfs(graph, 0);

    std::vector<int64_t> expected_distance = {0, 1, 1, -1, -1};

    ASSERT_EQ(distance, expected_distance);
}