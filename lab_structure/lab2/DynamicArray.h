#ifndef DYN_ARR_H
#define DYN_ARR_H

#include <cstdint>
#include <stdexcept>

template<typename T>
class DynamicArray {
private:
    T* data;
    std::int64_t size = 0; 
    std::int64_t capacity; 
    

public:
    DynamicArray();
    DynamicArray(std::int64_t capacity); // parametrized ctor
    DynamicArray(const DynamicArray<T>& other);
    ~DynamicArray(); // destructor

    void push_back(T x);
    void remove(std::int64_t idx);
    T& get(std::int64_t idx);

    std::int64_t get_size() const;
    bool isEmpty() const;

    T& operator[](std::int64_t idx);
}


#include "DynamicArray.cc"

#endif // DYN_ARR_H