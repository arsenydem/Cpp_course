#ifndef QUEUE_CC
#define QUEUE_CC

#include "queue.h"
#include <stdexcept> 

template <typename T>
Queue<T>::Queue(std::int64_t capacity) : inStack(capacity), outStack(capacity) {

}

template <typename T>
void Queue<T>::enqueue(T x) {
    try {
        inStack.push(x);
    } catch (const std::overflow_error& e) {
        throw std::overflow_error("Queue overflow");
    }
}

template <typename T>
T Queue<T>::dequeue() {
    if (outStack.isEmpty()) {
        while (!inStack.isEmpty()) {
            outStack.push(inStack.pop());
        }
    }

    if (outStack.isEmpty()) {
        throw std::underflow_error("Queue is empty");
    }

    return outStack.pop();
}

template <typename T>
bool Queue<T>::isEmpty() {
    return inStack.isEmpty() && outStack.isEmpty();
}

template <typename T>
std::int64_t Queue<T>::size() {
    return inStack.size() + outStack.size();
}

#endif // QUEUE_CC