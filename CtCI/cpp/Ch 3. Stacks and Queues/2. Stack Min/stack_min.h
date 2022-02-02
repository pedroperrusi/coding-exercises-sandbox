#pragma once

#include <limits>
#include <stdexcept>

#include "stack.h"

namespace stack {

/**
 * @brief Use inheritance to implement a stack which keeps track of the minimum element.
 * 
 * @tparam T 
 */
template <typename T>
class StackMin : public Stack<T> {
   private:
    Stack<T> _min_stack;

   public:
    virtual inline void push(T item) override {
        if (Stack<T>::isEmpty() || item <= _min_stack.peek()) {
            _min_stack.push(item);
        }
        Stack<T>::push(item);
    }

    virtual inline T pop() override {
        T value = Stack<T>::pop();
        if (value == _min_stack.peek()) _min_stack.pop();
        return value;
    }

    inline T getMin() {
        if (Stack<T>::isEmpty()) throw std::length_error("Stack is empty");
        return _min_stack.peek();
    }
};
}  // namespace stack