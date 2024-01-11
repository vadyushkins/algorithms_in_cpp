#include <gtest/gtest.h>

#include "sll.hpp"

TEST(SinglyLinkedListStruct, Test0) {
    SinglyLinkedList<int64_t> *list = new SinglyLinkedList<int64_t>();

    list->push_back(1);

    EXPECT_EQ(list->head->data, 1);
    EXPECT_EQ(list->head->next, nullptr);

    EXPECT_EQ(list->tail->data, 1);
    EXPECT_EQ(list->tail->next, nullptr);
}

TEST(SinglyLinkedListStruct, Test1) {
    SinglyLinkedList<int64_t> *list = new SinglyLinkedList<int64_t>();

    list->push_back(1);
    list->push_front(2);

    EXPECT_EQ(list->head->data, 2);
    EXPECT_EQ(list->head->next->data, 1);
    EXPECT_EQ(list->head->next->next, nullptr);

    EXPECT_EQ(list->tail->data, 1);
    EXPECT_EQ(list->tail->next, nullptr);
}

TEST(SinglyLinkedListStruct, Test2) {
    SinglyLinkedList<int64_t> *list = new SinglyLinkedList<int64_t>();

    list->push_back(1);
    list->push_front(2);
    list->pop_back();

    EXPECT_EQ(list->head->data, 2);
    EXPECT_EQ(list->head->next, nullptr);

    EXPECT_EQ(list->tail->data, 2);
    EXPECT_EQ(list->tail->next, nullptr);
}

TEST(SinglyLinkedListStruct, Test3) {
    SinglyLinkedList<int64_t> *list = new SinglyLinkedList<int64_t>();

    list->push_back(1);
    list->push_front(2);
    list->pop_front();

    EXPECT_EQ(list->head->data, 1);
    EXPECT_EQ(list->head->next, nullptr);

    EXPECT_EQ(list->tail->data, 1);
    EXPECT_EQ(list->tail->next, nullptr);
}

TEST(SinglyLinkedListStruct, Test4) {
    SinglyLinkedList<int64_t> *list = new SinglyLinkedList<int64_t>();

    list->push_back(1);
    list->push_front(2);
    list->push_back(3);

    EXPECT_EQ(list->head->data, 2);
    EXPECT_EQ(list->head->next->data, 1);
    EXPECT_EQ(list->head->next->next->data, 3);
    EXPECT_EQ(list->head->next->next->next, nullptr);

    EXPECT_EQ(list->tail->data, 3);
    EXPECT_EQ(list->tail->next, nullptr);

    EXPECT_EQ(list->find_item(1), true);
    EXPECT_EQ(list->find_item(2), true);
    EXPECT_EQ(list->find_item(3), true);
    EXPECT_EQ(list->find_item(4), false);
}

TEST(SinglyLinkedListStruct, Test5) {
    SinglyLinkedList<int64_t> *list = new SinglyLinkedList<int64_t>();

    list->push_back(1);
    list->pop_front();

    EXPECT_EQ(list->head, nullptr);

    EXPECT_EQ(list->tail, nullptr);
}

TEST(SinglyLinkedListStruct, Test6) {
    SinglyLinkedList<int64_t> *list = new SinglyLinkedList<int64_t>();

    list->push_back(1);
    list->pop_back();

    EXPECT_EQ(list->head, nullptr);

    EXPECT_EQ(list->tail, nullptr);
}
