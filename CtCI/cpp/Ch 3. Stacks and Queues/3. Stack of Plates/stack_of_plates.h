#pragma once

#include <cstddef>

#include "stack.h"

namespace stack {

/**
 * @brief Create a Stack handler class that know its size.
 * 
 * @tparam T 
 */
template <typename T>
class StampedStack : public Stack<T> {
   private:
    size_t _size = 0;

   public:
    virtual inline void push(T item) override {
        Stack<T>::push(item);
        _size++;
    }

    virtual inline T pop() override {
        T value = Stack<T>::pop();
        _size--;
        return value;
    }

    virtual inline size_t getSize() { return _size; }

    using NodePtr = typename Stack<T>::NodePtr;
    virtual inline NodePtr get() { return this->_top; }
};

/**
 * @brief Set of stacks implemented with smart pointers to prevent unecessary stack copies
 * With less memory copies, runtime efficiency can improve for large types T.
 * 
 * TODO: could inherit from StackInterface so the interface is compatible.
 * 
 * @tparam T 
 */
template <typename T, std::size_t MAX_SIZE = 3>
class SetOfStacks {
   private:
    // Using pointers to avoid creation of temporary stacks
    // alias to shared pointer
    using StampedStackPtr = std::shared_ptr<StampedStack<T>>;

    /**
     * @brief Create a new Stack object
     */
    inline StampedStackPtr createStack() {
        return std::make_shared<StampedStack<T>>();
    }

    /**
     * @brief Creates a new Stack object with an item
     */
    inline StampedStackPtr createStack(T item) {
        auto new_stack_ptr = createStack();
        new_stack_ptr->push(item);
        return new_stack_ptr;
    }

    StampedStack<StampedStackPtr> _stack_of_stacks;

   public:
    virtual inline void push(T item) {
        // if stack is empty
        if (_stack_of_stacks.getSize() == 0) {
            return _stack_of_stacks.push(createStack(item));
        }
        // if not empty, check its size
        auto top_stack_ptr = _stack_of_stacks.peek();
        if (top_stack_ptr->getSize() > MAX_SIZE) {
            return _stack_of_stacks.push(createStack(item));
        }
        // no new stack needed, just push it
        return top_stack_ptr->push(item);
    }

    virtual inline T pop() {
        auto top_stack_ptr = _stack_of_stacks.peek();
        T output = top_stack_ptr->pop();
        // if last stack has no plate left, remove it
        if (top_stack_ptr->getSize() == 0) _stack_of_stacks.pop();
        return output;
    }

    virtual inline T peek() { return _stack_of_stacks.peek()->peek(); }
};
}  // namespace stack