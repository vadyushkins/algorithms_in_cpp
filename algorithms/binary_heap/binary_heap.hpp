#pragma once

#include <cstdint>
#include <vector>

template <
    std::equality_comparable T,
    typename Container = std::vector<T>,
    typename Compare = std::greater<typename Container::value_type>
>
struct BinaryHeap {
    Container *container;
    Compare *compare;

    explicit BinaryHeap() {
        this->container = new Container();
        this->compare = new Compare();
    }

    ~ BinaryHeap() = default;

    void sift_up(std::size_t key) {
        if (this->container->size() > key) {
            while (
                key > 0 &&
                (*this->compare)(
                    this->container->begin()[(key - 1) >> 1],
                    this->container->begin()[key]
                ) == false
            ) {
                std::swap(
                    this->container->begin()[(key - 1) >> 1],
                    this->container->begin()[key]
                );
                key >>= 1;
            }
        }
    }

    void sift_down(std::size_t key) {
        if (this->container->size() > key) {
            while (
                (
                    2 * key + 1 < this->container->size() &&
                    (*this->compare)(
                        this->container->begin()[key],
                        this->container->begin()[2 * key + 1]
                    ) == false
                ) ||
                (
                    2 * key + 2 < this->container->size() &&
                    (*this->compare)(
                        this->container->begin()[key],
                        this->container->begin()[2 * key + 2]
                    ) == false
                )
            ) {
                if (2 * key + 2 < this->container->size()) {
                    if (
                        (*this->compare)(
                            this->container->begin()[2 * key + 1],
                            this->container->begin()[2 * key + 2]
                        ) == true
                    ) {
                        std::swap(
                            this->container->begin()[key],
                            this->container->begin()[2 * key + 1]
                        );
                        key = 2 * key + 1;
                    } else {
                        std::swap(
                            this->container->begin()[key],
                            this->container->begin()[2 * key + 2]
                        );
                        key = 2 * key + 2;
                    }
                } else {
                    std::swap(
                        this->container->begin()[key],
                        this->container->begin()[2 * key + 1]
                    );
                    key = 2 * key + 1;
                }
            }
        }
    }

    void push(T new_value) {
        this->container->push_back(new_value);
        this->sift_up(this->container->size() - 1);
    }

    void remove(size_t key) {
        if (this->container->size() > key) {
            std::swap(
                this->container->begin()[key],
                this->container->begin()[this->container->size() - 1]
            );
            this->container->pop_back();
            this->sift_down(key);
        }
    }

    void pop() {
        this->del(0);
    }

    void change(size_t key, T new_value) {
        if (this->container->size() > key && this->container->begin()[key] != new_value) {
            this->container->begin()[key] = new_value;
            if (
                key > 0 &&
                (*this->compare)(
                    this->container->begin()[(key - 1) >> 1],
                    this->container->begin()[key]
                ) == false
            ) {
                this->sift_up(key);
            } else {
                this->sift_down(key);
            }
        }
    }

    T top() {
        return this->container->begin()[0];
    }

    size_t size() {
        return this->container->size();
    }
};
