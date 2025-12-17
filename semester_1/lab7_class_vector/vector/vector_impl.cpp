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
}

Vector::Vector(const Vector& other) : size_(other.size_), capacity_(other.capacity_) {
    if (capacity_ > 0) {
        data_ = new int[capacity_];
        for (size_t i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    }
}

Vector& Vector::operator=(const Vector& other) {
    if (this != &other) {
        delete[] data_;
        size_ = other.size_;
        capacity_ = other.capacity_;
        if (capacity_ > 0) {
            data_ = new int[capacity_];
            for (size_t i = 0; i < size_; ++i) {
                data_[i] = other.data_[i];
            }
        }
        else {
            data_ = nullptr;
        }
    }
    return *this;
}

Vector::~Vector() {
    delete[] data_;
}

void Vector::Swap(Vector& other) {
    int* temp_data = data_;
    data_ = other.data_;
    other.data_ = temp_data;

    size_t temp_size = size_;
    size_ = other.size_;
    other.size_ = temp_size;

    size_t temp_capacity = capacity_;
    capacity_ = other.capacity_;
    other.capacity_ = temp_capacity;
}

int& Vector::operator[](size_t index) {
    return data_[index];
}

const int& Vector::operator[](size_t index) const {
    return data_[index];
}


int& Vector::At(size_t index) {
    if (index >= size_) {
        throw std::out_of_range("Index out of range!");
    }
    return data_[index];
}

const int& Vector::At(size_t index) const {
    if (index >= size_) {
        throw std::out_of_range("Index out of range!");
    }
    return data_[index];
}

size_t Vector::Size() const {
    return size_;
}

size_t Vector::Capacity() const {
    return capacity_;
}

void Vector::PushBack(int value) {
    if (size_ >= capacity_) {
        size_t new_capacity;
        if (capacity_ == 0) {
            new_capacity = 1;
        } else {
            new_capacity = capacity_ * 2;
        }
        Allocate(new_capacity);
    }
    data_[size_] = value;
    ++size_;
}

void Vector::PopBack() {
    if (size_ > 0) {
        --size_;
    }
}

void Vector::Clear() {
    size_ = 0;
}

void Vector::Reserve(size_t new_capacity) {
    if (new_capacity > capacity_) {
        Allocate(new_capacity);
    }
}

std::ostream& operator<<(std::ostream& os, const Vector& v) {
    os << "[";
    for (size_t i = 0; i < v.Size(); ++i) {
        if (i > 0) {
            os << ", ";
        }
        os << v[i];
    }
    os << "]";
    return os;
}
