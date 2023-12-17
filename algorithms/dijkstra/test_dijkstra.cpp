#include <gtest/gtest.h>
#include <iostream>

#include "dijkstra.hpp"

TEST(Dijkstra, Test0)
{
    std::vector<std::vector<std::pair<int64_t, int64_t>>> graph = {
        {{1, 1}, {2, 1}},
        {{0, 1}, {2, 1}},
        {{0, 1}, {1, 1}},
    };

    int64_t source_node = 0;

    std::vector<int64_t> distance = dijkstra(graph, source_node);

    std::vector<int64_t> expected_distance = {0, 1, 1};

    ASSERT_EQ(distance, expected_distance);
}

TEST(Dijkstra, Test1)
{
    std::vector<std::vector<std::pair<int64_t, int64_t>>> graph = {
        {{1, 1}},
        {{2, 1}},
        {{3, 1}},
        {},
    };

    int64_t source_node = 0;

    std::vector<int64_t> distance = dijkstra(graph, source_node);

    std::vector<int64_t> expected_distance = {0, 1, 2, 3};

    ASSERT_EQ(distance, expected_distance);
}

TEST(Dijkstra, Test2)
{
    std::vector<std::vector<std::pair<int64_t, int64_t>>> graph = {
        {{1, 1}, {2, 1}},
        {{3, 1}},
        {{3, 1}},
        {},
    };

    int64_t source_node = 0;

    std::vector<int64_t> distance = dijkstra(graph, source_node);

    std::vector<int64_t> expected_distance = {0, 1, 1, 2};

    ASSERT_EQ(distance, expected_distance);
}