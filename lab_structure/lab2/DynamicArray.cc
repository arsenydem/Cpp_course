#ifndef DYNAMIC_ARRAY_CC
#define DYNAMIC_ARRAY_CC

#include "DynamicArray.h"
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <exception>

template <typename T>
DynamicArray<T>::DynamicArray() {
    this->size = 0;
    this->capacity = 8;
    this->data = new T[this->capacity];
}

template <typename T>
DynamicArray<T>::DynamicArray(std::int64_t capacity) {
    if (capacity < 1) {
        throw std::invalid_argument("Capacity < 1");
    }
    this->size = 0;
    this->capacity = capacity;
    this->data = new T[this->capacity];
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& other) {
    this->size = other.size;
    this->capacity = other.capacity;
    this->data = new T[this->capacity];

    for (std::int64_t i = 0; i < size; ++i) {
        this->data[i] = other.data[i];
    }
}

template <typename T>
DynamicArray<T>::~DynamicArray() {
    if (this->data) {
        delete[] this->data;
    }
}

template <typename T>
void DynamicArray<T>::push_back(T x) {
    if (size >= capacity) {
        std::int64_t newCapacity = capacity * 2;
        T* tempArray = new T[newCapacity];
        for (std::int64_t i = 0; i < size; ++i) {
            tempArray[i] = this->data[i];
        }
        delete[] data;
        data = tempArray;
        capacity = newCapacity;
    }
    data[size] = x;
    size++;
}

 

template <typename T>
void DynamicArray<T>::remove(std::int64_t idx) {
    if (idx < 0 || idx >= size) {
       throw std::invalid_argument("Out of range");
    }
    for (std::int64_t i = idx; i < size - 1; ++i) {
        data[i] = data[i + 1];
    }
    size--;
}

template <typename T>
T& DynamicArray<T>::get(std::int64_t idx) {
    if (idx < 0 || idx >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[idx];
}


template <typename T>
T& DynamicArray<T>::operator[](std::int64_t idx) {
    return get(idx);
}

template <typename T>
std::int64_t DynamicArray<T>::get_size() const {
    return size;
}

template <typename T>
bool DynamicArray<T>::isEmpty() const {
    return size == 0;
}

#endif // DYNAMIC_ARRAY_CC