#include <gtest/gtest.h>

#include "cutpoints.hpp"

TEST(Cutpoints, Test0) {
    std::vector<std::vector<int64_t>> graph = {
        {1, 2},
        {0},
        {0},
    };
    std::vector<int64_t> cutpoints = cutpoints_search(graph);

    std::vector<int64_t> expected_cutpoints = {0};

    ASSERT_EQ(cutpoints, expected_cutpoints);
}

TEST(Cutpoints, Test1) {
    std::vector<std::vector<int64_t>> graph = {
        {1, 2},
        {0, 2},
        {0, 1, 3},
        {2},
    };
    std::vector<int64_t> cutpoints = cutpoints_search(graph);

    std::vector<int64_t> expected_cutpoints = {2};

    ASSERT_EQ(cutpoints, expected_cutpoints);
}

TEST(Cutpoints, Test2) {
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
    std::vector<int64_t> cutpoints = cutpoints_search(graph);

    std::vector<int64_t> expected_cutpoints = {3, 2, 5, 7};

    ASSERT_EQ(cutpoints, expected_cutpoints);
}

TEST(Cutpoints, Test3) {
    std::vector<std::vector<int64_t>> graph = {
        {1, 2},
        {0, 2},
        {0, 1},
    };
    std::vector<int64_t> cutpoints = cutpoints_search(graph);

    std::vector<int64_t> expected_cutpoints = {};

    ASSERT_EQ(cutpoints, expected_cutpoints);
}