#pragma once

#include <cstdint>
#include <functional>

template <std::equality_comparable T>
struct SinglyLinkedList {
    struct Node {
        T data;
        Node *next;

        explicit Node(T data) {
            this->data = data;
            this->next = nullptr;
        }

        ~ Node() = default;
    };

    Node *head;
    Node *tail;

    explicit SinglyLinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void push_back(T data) {
        if (this->tail == nullptr) {
            this->tail = new Node(data);
            this->head = tail;
        } else {
            this->tail->next = new Node(data);
            this->tail = this->tail->next;
        }
    }

    void push_front(T data) {
        if (this->head == nullptr) {
            this->head = new Node(data);
            this->tail = this->head;
        } else {
            Node *new_head = new Node(data);
            new_head->next = this->head;
            this->head = new_head;
        }
    }

    void pop_back() {
        if (this->tail != nullptr) {
            if (this->head->next == nullptr) {
                delete this->head;
                this->head = nullptr;
                this->tail = nullptr;
            } else {
                Node *new_tail = this->head;
                while (new_tail->next->next != nullptr) {
                    new_tail = new_tail->next;
                }
                if (new_tail->next != nullptr) {
                    delete new_tail->next;
                }
                new_tail->next = nullptr;
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
