#ifndef STACK_H
#define STACK_H

#include "DynamicArray.h"
#include <cstdint>
#include <stdexcept>

template <typename T>
class Stack {
private:
    DynamicArray<T> arr; 
    std::int64_t max_limit; 

public:
    Stack(std::int64_t max_size = 100);
    
    void push(T x);
    T pop();
    T top();
    bool isEmpty();
    std::int64_t size(); // для size() в Queue
};

#include "stack.cc"

#endif // STACK_H