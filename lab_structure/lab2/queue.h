#ifndef QUEUE_H
#define QUEUE_H

#include "stack.h"
#include <cstdint> 

template <typename T>
class Queue {
private:
    Stack<T> inStack;
    Stack<T> outStack;

public:
    Queue(std::int64_t capacity = 100); 
    
    void enqueue(T x);
    T dequeue();
    bool isEmpty();
    std::int64_t size();
};

#include "queue.cc"

#endif // QUEUE_H