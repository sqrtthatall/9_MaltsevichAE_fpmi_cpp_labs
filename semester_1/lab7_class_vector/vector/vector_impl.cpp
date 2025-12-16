#include "vector_impl.h"
#include <iostream>


void Vector::Allocate(size_t new_capacity) {
    if (new_capacity == 0) {
        data_ = nullptr;
        capacity_ = 0;
        return;
    }
    int* new_data = new int[new_capacity];
    if (data_ != nullptr) {
        for (size_t i = 0; i < size_; ++i) {
            new_data[i] = data_[i];
        }
        delete[] data_;
    }
    data_ = new_data;
    capacity_ = new_capacity;
}

Vector::Vector(size_t n) : size_(n), capacity_(n) {
    if (n > 0) {
        data_ = new int[capacity_]();
    }
}

Vector::Vector(std::initializer_list<int> init) : size_(init.size()), capacity_(init.size()) {
    if (capacity_ > 0) {
        data_ = new int[capacity_];
        size_t i = 0;
        for (const int& val : init) {
            data_[i++] = val;
        }
    }
