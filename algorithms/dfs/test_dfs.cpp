#include <gtest/gtest.h>

#include "dfs.hpp"

TEST(DFS, Test0) {
    std::vector<std::vector<int64_t>> graph = {
        {1, 2},
        {0, 2},
        {0, 1},
    };

    std::vector<bool> reachable(3, false);
    dfs(graph, reachable, 0);

    std::vector<bool> expected_reachable = {true, true, true};

    ASSERT_EQ(reachable, expected_reachable);
}

TEST(DFS, Test1) {
    std::vector<std::vector<int64_t>> graph = {
        {1},
        {2},
        {},
    };

    std::vector<bool> reachable(3, false);
    dfs(graph, reachable, 0);

    std::vector<bool> expected_reachable = {true, true, true};

    ASSERT_EQ(reachable, expected_reachable);
}

TEST(DFS, Test2) {
    std::vector<std::vector<int64_t>> graph = {
        {1, 2},
        {0, 2},
        {0, 1},
        {4},
        {3},
    };

    std::vector<bool> reachable(5, false);
    dfs(graph, reachable, 0);

    std::vector<bool> expected_reachable = {true, true, true, false, false};

    ASSERT_EQ(reachable, expected_reachable);
}