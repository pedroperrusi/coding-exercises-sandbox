#pragma once
#include <exception>
#include <iostream>
#include <memory>

namespace queue {

/**
 * @brief Queue data structure
 *
 * @tparam T typename of the data container
 */
template <typename T>
class Queue {
   private:
    /**
     * @brief Hidden QueueNode class
     */
    class QueueNode {
       public:
        using Ptr = std::shared_ptr<QueueNode>;

        explicit QueueNode(T d) : _data(d) {}

        inline T peek() { return _data; }

        Ptr _next = nullptr;
        T _data;
    };
    /** Alias to QueueNode Smart Pointer */
    using NodePtr = typename QueueNode::Ptr;

    /**
     * @brief Helper function to create new nodes
     */
    inline static NodePtr createNode(T d) {
        return std::make_shared<QueueNode>(d);
    }

    NodePtr _first = nullptr;
    NodePtr _last = nullptr;

   public:
    /* Default Constructor */
    Queue() {}

    /* Copy Constructor */
    Queue(const Queue<T>&) = default;

    /* List initialization */
    explicit Queue(std::initializer_list<T> list) {
        for (const auto& item : list) add(item);
    }

    /* Copy Assignment */
    Queue<T>& operator=(const Queue<T>&) = default;

    /* Move Assignment */
    Queue<T>& operator=(Queue<T>&&) = default;

    virtual ~Queue() {}

    inline void add(T data) {
        NodePtr node = createNode(data);
        if (isEmpty()) {
            _first = node;
            _last = _first;
            return;
        }
        _last->_next = node;
        _last = node;
    }

    inline T pop() {
        if (isEmpty()) throw std::range_error("Queue is empty");
        T item = _first->peek();
        _first = _first->_next;
        if (!_first) _last = nullptr;  // reched the end of the line
        return item;
    }

    inline T peek() {
        if (!_first) throw std::range_error("Queue is empty");
        return _first->peek();
    }

    inline bool isEmpty() { return _first == nullptr; }
};

}  // namespace queue