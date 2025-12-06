#ifndef STACK_CC
#define STACK_CC

#include "stack.h"
#include <iostream>
#include <stdexcept>
#include <exception>

template <typename T>
Stack<T>::Stack(std::int64_t max_size): max_limit(max_size) {
    if (max_size < 1) {
        throw std::invalid_argument("Max size < 1");
    }
}

template <typename T>
void Stack<T>::push(T x) {
    if (arr.get_size() >= max_limit) {
        throw std::overflow_error("Stack overflow");
    }
    arr.push_back(x);
}

template <typename T>
T Stack<T>::top() {
    if (isEmpty()) {
        throw std::underflow_error("Stack is empty");
    }
    return arr.get(arr.get_size() - 1);
}

template <typename T>
T Stack<T>::pop() {
    if (isEmpty()) {
        throw std::underflow_error("Stack is empty");
    }
    T val = top(); 
    arr.remove(arr.get_size() - 1); 
    return val;
}

template <typename T>
bool Stack<T>::isEmpty() {  
    return arr.isEmpty();
}

// для size() в Queue
template <typename T>
std::int64_t Stack<T>::size() {
    return arr.get_size();
}

#endif // STACK_CC