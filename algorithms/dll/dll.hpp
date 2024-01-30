#pragma once

#include <cstdint>
#include <functional>

template <std::equality_comparable T>
struct DoublyLinkedList {
    struct Node {
        T data;
        Node *prev;
        Node *next;

        explicit Node(T data) {
            this->data = data;
            this->prev = nullptr;
            this->next = nullptr;
        }

        ~ Node() = default;
    };

    Node *head;
    Node *tail;

    explicit DoublyLinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void push_back(T data) {
        if (this->tail == nullptr) {
            this->tail = new Node(data);
            this->head = tail;
        } else {
            this->tail->next = new Node(data);
            this->tail->next->prev = this->tail;
            this->tail = this->tail->next;
        }
    }

    void push_front(T data) {
        if (this->head == nullptr) {
            this->head = new Node(data);
            this->tail = this->head;
        } else {
            this->head->prev = new Node(data);
            this->head->prev->next = this->head;
            this->head = this->head->prev;
        }
    }

    void pop_back() {
        if (this->tail != nullptr) {
            if (this->head->next == nullptr) {
                delete this->head;
                this->head = nullptr;
                this->tail = nullptr;
            } else {
                Node *new_tail = this->tail->prev;
                this->tail->prev->next = nullptr;
                this->tail->prev = nullptr;
                delete this->tail;
                this->tail = new_tail;
            }
        }
    }

    void pop_front() {
        if (this->head != nullptr) {
            if (this->head->next == nullptr) {
                delete this->head;
                this->head = nullptr;
                this->tail = nullptr;
            } else {
                Node *new_head = this->head->next;
                this->head->next->prev = nullptr;
                this->head->next = nullptr;
                delete this->head;
                this->head = new_head;
            }
        }
    }

    bool find_item(T data) {
        Node *current = this->head;
        while (current != nullptr) {
            if (current->data == data) {
                return true;
            } else {
                current = current->next;
            }
        }
        return false;
    }
};
