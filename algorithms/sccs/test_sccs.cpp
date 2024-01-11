#include <gtest/gtest.h>

#include "sccs.hpp"

TEST(StronglyConnectedComponents, Test0) {
    std::vector<std::vector<int64_t>> graph = {
        {1, 2},
        {0},
        {3},
        {2},
    };

    std::vector<std::vector<int64_t>> strongly_connected_components = strongly_connected_components_search(graph);

    std::vector<std::vector<int64_t>> expected_strongly_connected_components = {
        {0, 1},
        {2, 3},
    };

    ASSERT_EQ(strongly_connected_components, expected_strongly_connected_components);
}

TEST(StronglyConnectedComponents, Test1) {
    std::vector<std::vector<int64_t>> graph = {
        {2, 3},
        {0},
        {1},
        {4},
        {5},
        {3},
    };

    std::vector<std::vector<int64_t>> strongly_connected_components = strongly_connected_components_search(graph);

    std::vector<std::vector<int64_t>> expected_strongly_connected_components = {
        {0, 1, 2},
        {3, 5, 4},
    };

    ASSERT_EQ(strongly_connected_components, expected_strongly_connected_components);
}

TEST(StronglyConnectedComponents, Test2) {
    std::vector<std::vector<int64_t>> graph = {
        {1},
        {},
    };

    std::vector<std::vector<int64_t>> strongly_connected_components = strongly_connected_components_search(graph);

    std::vector<std::vector<int64_t>> expected_strongly_connected_components = {
        {0},
        {1},
    };

    ASSERT_EQ(strongly_connected_components, expected_strongly_connected_components);
}

TEST(StronglyConnectedComponents, Test3) {
    std::vector<std::vector<int64_t>> graph = {
        {1},
        {2},
        {3},
        {4},
        {0},
    };

    std::vector<std::vector<int64_t>> strongly_connected_components = strongly_connected_components_search(graph);

    std::vector<std::vector<int64_t>> expected_strongly_connected_components = {
        {0, 4, 3, 2, 1},
    };

    ASSERT_EQ(strongly_connected_components, expected_strongly_connected_components);
}

TEST(StronglyConnectedComponents, Test4) {
    std::vector<std::vector<int64_t>> graph = {
        {},
        {},
        {},
    };

    std::vector<std::vector<int64_t>> strongly_connected_components = strongly_connected_components_search(graph);

    std::vector<std::vector<int64_t>> expected_strongly_connected_components = {
        {2},
        {1},
        {0},
    };

    ASSERT_EQ(strongly_connected_components, expected_strongly_connected_components);
}
