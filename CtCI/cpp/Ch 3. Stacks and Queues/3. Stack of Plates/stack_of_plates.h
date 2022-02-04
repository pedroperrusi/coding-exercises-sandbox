#pragma once

#include <cstddef>

#include "stack.h"

namespace stack {

/**
 * @brief Set of stacks implemented with smart pointers to prevent unecessary stack copies.
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
    using StackPtr = std::shared_ptr<Stack<T>>;
    Stack<StackPtr> _stack_of_stacks;
    Stack<size_t> _stack_of_sizes;

    /**
     * @brief Create a new Stack object
     */
    inline StackPtr createStack() { return std::make_shared<Stack<T>>(); }

    /**
     * @brief Creates a new Stack object with an item
     */
    inline void addNewStack(T item) {
        auto new_stack_ptr = createStack();
        new_stack_ptr->push(item);
        _stack_of_stacks.push(new_stack_ptr);
        _stack_of_sizes.push(0);
    }

   public:
    virtual inline void push(T item) {
        // if stack is empty
        if (_stack_of_sizes.isEmpty()) return addNewStack(item);
        // if not empty, check its size
        if (_stack_of_sizes.peek() > MAX_SIZE) return addNewStack(item);
        // no new stack needed, just push a new item
        auto top_stack_ptr = _stack_of_stacks.peek();
        top_stack_ptr->push(item);
        auto new_size = _stack_of_sizes.peek() + 1;
        _stack_of_sizes.swap(new_size);
    }

    virtual inline T pop() {
        auto top_stack_ptr = _stack_of_stacks.peek();
        T output = top_stack_ptr->pop();
        // if last stack has no plate left, remove it
        if (_stack_of_sizes.peek() == 0) _stack_of_stacks.pop();
        return output;
    }

    virtual inline T peek() { return _stack_of_stacks.peek()->peek(); }
};
}  // namespace stack