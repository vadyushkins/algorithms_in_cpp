#include <gtest/gtest.h>
#include <deque>

#include "binary_heap.hpp"

TEST(BinaryHeapStruct, Test0) {
    BinaryHeap<int64_t> *heap = new BinaryHeap<int64_t>();

    heap->push(10);

    EXPECT_EQ(heap->size(), 1);
    EXPECT_EQ(heap->container->begin()[0], 10);
}

TEST(BinaryHeapStruct, Test1) {
    BinaryHeap<int64_t> *heap = new BinaryHeap<int64_t>();

    heap->push(10);
    heap->push(20);

    EXPECT_EQ(heap->size(), 2);
    EXPECT_EQ(heap->container->begin()[0], 20);
    EXPECT_EQ(heap->container->begin()[1], 10);
}

TEST(BinaryHeapStruct, Test2) {
    BinaryHeap<int64_t, std::vector<int64_t>, std::less<int64_t>> *heap = (
        new BinaryHeap<int64_t, std::vector<int64_t>, std::less<int64_t>>()
    );

    heap->push(10);
    heap->push(20);

    EXPECT_EQ(heap->size(), 2);
    EXPECT_EQ(heap->container->begin()[0], 10);
    EXPECT_EQ(heap->container->begin()[1], 20);
}

TEST(BinaryHeapStruct, Test3) {
    BinaryHeap<int64_t, std::deque<int64_t>, std::less<int64_t>> *heap = (
        new BinaryHeap<int64_t, std::deque<int64_t>, std::less<int64_t>>()
    );

    heap->push(10);
    heap->push(20);

    EXPECT_EQ(heap->size(), 2);
    EXPECT_EQ(heap->container->begin()[0], 10);
    EXPECT_EQ(heap->container->begin()[1], 20);
}

TEST(BinaryHeapStruct, Test4) {
    BinaryHeap<int64_t> *heap = new BinaryHeap<int64_t>();

    heap->push(10);
    heap->push(20);
    heap->push(30);
    heap->push(40);

    EXPECT_EQ(heap->size(), 4);
    EXPECT_EQ(heap->container->begin()[0], 40);
    EXPECT_EQ(heap->container->begin()[1], 30);
    EXPECT_EQ(heap->container->begin()[2], 20);
    EXPECT_EQ(heap->container->begin()[3], 10);
}

TEST(BinaryHeapStruct, Test5) {
    BinaryHeap<int64_t> *heap = new BinaryHeap<int64_t>();

    heap->push(10);
    heap->push(20);
    heap->push(30);
    heap->push(40);
    heap->change(0, 5);

    EXPECT_EQ(heap->size(), 4);
    EXPECT_EQ(heap->container->begin()[0], 30);
    EXPECT_EQ(heap->container->begin()[1], 10);
    EXPECT_EQ(heap->container->begin()[2], 20);
    EXPECT_EQ(heap->container->begin()[3], 5);
}

TEST(BinaryHeapStruct, Test6) {
    BinaryHeap<int64_t> *heap = new BinaryHeap<int64_t>();

    heap->push(10);
    heap->push(20);
    heap->push(30);
    heap->push(40);
    heap->remove(1);

    EXPECT_EQ(heap->size(), 3);
    EXPECT_EQ(heap->container->begin()[0], 40);
    EXPECT_EQ(heap->container->begin()[1], 10);
    EXPECT_EQ(heap->container->begin()[2], 20);
}
