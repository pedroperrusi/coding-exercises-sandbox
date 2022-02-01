#pragma once
#include <exception>
#include <iostream>
#include <memory>

namespace stack {

/**
 * @brief Stack data structure
 *
 * @tparam T typename of the data container
 */
template <typename T>
class Stack {
   private:
    /**
     * @brief Hidden StackNode class
     */
    class StackNode {
       public:
        using Ptr = std::shared_ptr<StackNode>;

        explicit StackNode(T d) : _data(d) {}

        inline T peek() { return _data; }

        Ptr _next = nullptr;
        T _data;
    };
    /** Alias to StackNode Smart Pointer */
    using NodePtr = typename StackNode::Ptr;

    /**
     * @brief Helper function to create new nodes
     */
    inline static NodePtr createNode(T d) {
        return std::make_shared<StackNode>(d);
    }

    NodePtr _top = nullptr;

   public:
    /* Default Constructor */
    Stack() {}

    /* Copy Constructor */
    Stack(const Stack<T>& stack) = default;

    /* List initialization */
    explicit Stack(std::initializer_list<T> list) {
        for (const auto& item : list) push(item);
    }

    /* Copy Assignment */
    Stack<T>& operator=(const Stack<T>& list) = default;

    /* Move Assignment */
    Stack<T>& operator=(Stack<T>&& list) = default;

    virtual ~Stack() {}

    inline void push(T data) {
        NodePtr node = createNode(data);
        if (isEmpty()) {
            _top = node;
            return;
        }
        node->_next = _top;
        _top = node;
    }

    inline T pop() {
        if (isEmpty()) throw std::range_error("Stack is empty");
        T item = _top->peek();
        _top = _top->_next;
        return item;
    }

    inline T peek() {
        if (isEmpty()) throw std::range_error("Stack is empty");
        return _top->peek();
    }

    inline bool isEmpty() { return _top == nullptr; }
};

}  // namespace stack