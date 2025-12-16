#ifndef VECTOR_IMPL_H
#define VECTOR_IMPL_H

#include <iostream>
#include <initializer_list>
#include <stdexcept>

class Vector {
private:
    int* data_ = nullptr;
    size_t size_ = 0;
    size_t capacity_ = 0;

    void Allocate(size_t new_capacity);

public:
    Vector() = default;

    explicit Vector(size_t n);
    Vector(std::initializer_list<int> init);
    Vector(const Vector& other);
    Vector& operator=(const Vector& other);
    ~Vector();
}
