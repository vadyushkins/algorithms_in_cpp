#include <gtest/gtest.h>

#include "dll.hpp"

TEST(DoublyLinkedListStruct, Test0) {
    DoublyLinkedList<int64_t> *list = new DoublyLinkedList<int64_t>();

    list->push_back(1);

    EXPECT_EQ(list->head->prev, nullptr);
    EXPECT_EQ(list->head->data, 1);
    EXPECT_EQ(list->head->next, nullptr);

    EXPECT_EQ(list->tail->prev, nullptr);
    EXPECT_EQ(list->tail->data, 1);
    EXPECT_EQ(list->tail->next, nullptr);
}

TEST(DoublyLinkedListStruct, Test1) {
    DoublyLinkedList<int64_t> *list = new DoublyLinkedList<int64_t>();

    list->push_back(1);
    list->push_front(2);

    EXPECT_EQ(list->head->prev, nullptr);
    EXPECT_EQ(list->head->data, 2);
    EXPECT_EQ(list->head->next->data, 1);
    EXPECT_EQ(list->head->next->next, nullptr);

    EXPECT_EQ(list->tail->prev->data, 2);
    EXPECT_EQ(list->tail->data, 1);
    EXPECT_EQ(list->tail->prev->prev, nullptr);
    EXPECT_EQ(list->tail->next, nullptr);
}

TEST(DoublyLinkedListStruct, Test2) {
    DoublyLinkedList<int64_t> *list = new DoublyLinkedList<int64_t>();

    list->push_back(1);
    list->push_front(2);
    list->pop_back();

    EXPECT_EQ(list->head->prev, nullptr);
    EXPECT_EQ(list->head->data, 2);
    EXPECT_EQ(list->head->next, nullptr);

    EXPECT_EQ(list->tail->prev, nullptr);
    EXPECT_EQ(list->tail->data, 2);
    EXPECT_EQ(list->tail->next, nullptr);
}

TEST(DoublyLinkedListStruct, Test3) {
    DoublyLinkedList<int64_t> *list = new DoublyLinkedList<int64_t>();

    list->push_back(1);
    list->push_front(2);
    list->pop_front();

    EXPECT_EQ(list->head->prev, nullptr);
    EXPECT_EQ(list->head->data, 1);
    EXPECT_EQ(list->head->next, nullptr);

    EXPECT_EQ(list->tail->prev, nullptr);
    EXPECT_EQ(list->tail->data, 1);
    EXPECT_EQ(list->tail->next, nullptr);
}

TEST(DoublyLinkedListStruct, Test4) {
    DoublyLinkedList<int64_t> *list = new DoublyLinkedList<int64_t>();

    list->push_back(1);
    list->push_front(2);
    list->push_back(3);

    EXPECT_EQ(list->head->prev, nullptr);
    EXPECT_EQ(list->head->data, 2);
    EXPECT_EQ(list->head->next->data, 1);
    EXPECT_EQ(list->head->next->next->data, 3);
    EXPECT_EQ(list->head->next->next->next, nullptr);

    EXPECT_EQ(list->tail->prev->prev->prev, nullptr);
    EXPECT_EQ(list->tail->prev->prev->data, 2);
    EXPECT_EQ(list->tail->prev->data, 1);
    EXPECT_EQ(list->tail->data, 3);
    EXPECT_EQ(list->tail->next, nullptr);

    EXPECT_EQ(list->find_item(1), true);
    EXPECT_EQ(list->find_item(2), true);
    EXPECT_EQ(list->find_item(3), true);
    EXPECT_EQ(list->find_item(4), false);
}

TEST(DoublyLinkedListStruct, Test5) {
    DoublyLinkedList<int64_t> *list = new DoublyLinkedList<int64_t>();

    list->push_back(1);
    list->pop_front();

    EXPECT_EQ(list->head, nullptr);

    EXPECT_EQ(list->tail, nullptr);
}

TEST(DoublyLinkedListStruct, Test6) {
    DoublyLinkedList<int64_t> *list = new DoublyLinkedList<int64_t>();

    list->push_back(1);
    list->pop_back();

    EXPECT_EQ(list->head, nullptr);

    EXPECT_EQ(list->tail, nullptr);
}

TEST(DoublyLinkedListStruct, Test7) {
    DoublyLinkedList<int64_t> *list = new DoublyLinkedList<int64_t>();

    list->push_back(1);
    list->push_back(1);
    list->pop_front();
    list->pop_back();

    EXPECT_EQ(list->head, nullptr);

    EXPECT_EQ(list->tail, nullptr);
}

TEST(DoublyLinkedListStruct, Test8) {
    DoublyLinkedList<int64_t> *list = new DoublyLinkedList<int64_t>();

    list->push_back(1);
    list->push_back(2);
    list->push_back(3);
    list->pop_front();
    list->pop_back();

    EXPECT_EQ(list->head->prev, nullptr);
    EXPECT_EQ(list->head->data, 2);
    EXPECT_EQ(list->head->next, nullptr);

    EXPECT_EQ(list->tail->prev, nullptr);
    EXPECT_EQ(list->tail->data, 2);
    EXPECT_EQ(list->tail->next, nullptr);
}
