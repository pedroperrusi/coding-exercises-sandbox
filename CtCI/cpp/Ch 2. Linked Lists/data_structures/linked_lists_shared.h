#pragma once
#include <iostream>
#include <memory>
#include <exception>

namespace linked_lists::shared {

/**
 * @brief Single linked list node class
 * Designed to have a shared copy of next element.
 * Warning: memory deallocation should happen when no more copies of the node go out of scope, or are assigned to nullptr.
 *
 * @tparam T typename of the data container
 */
template <typename T>
class Node {
   public:
    using Ptr = std::shared_ptr<Node<T>>;
    Ptr next = nullptr;
    T data;

    explicit Node(T d) : data(d) {}

    inline T visit() { return this->data; }
    inline void set(T data) { this->data = data; }
    inline Ptr getNext() const { return next; }
};

/**
 * @brief  Having an alias to call Node<T>::Ptr
 */
template <typename T>
using NodePtr = typename Node<T>::Ptr;

/**
 * @brief Create a Node object
 */
template <typename T>
static NodePtr<T> createNode(T data) {
    return std::make_shared<Node<T>>(data);
}

/**
 * @brief Single linked list class
 *
 * Ispired by
 *  - https://solarianprogrammer.com/2019/02/22/cpp-17-implementing-singly-linked-list-smart-pointers/
 *  
 * @tparam T typename of the data container
 */
template <typename T>
class LinkedList {
   public:
    NodePtr<T> root = nullptr;

    /* Default Constructor */
    LinkedList() {}

    /* Copy Constructor */
    LinkedList(const LinkedList<T>& list) = default;

    /* List initialization */
    explicit LinkedList(std::initializer_list<T> list) {
        for (const auto& item : list) push_back(item);
    }

    /* Copy Assignment */
    LinkedList<T>& operator=(const LinkedList<T>& list) = default;

    /* Move Assignment */
    LinkedList<T>& operator=(LinkedList<T>&& list) = default;

    virtual ~LinkedList() {}

    inline NodePtr<T> getRoot() const { return root; }

    void push_front(NodePtr<T>& node) {
        if (root == nullptr) {
            root = node;
            return;
        }
        // copy root to node
        T value = node->visit();
        node->next = root->next;
        node->set(root->visit());
        // change root and point it to node
        root->set(value);
        root->next = node;
    }

    void push_front(T d) {
        auto node = createNode(d);
        push_front(node);
    }

    void push_back(T d) {
        auto node = createNode(d);
        push_back(node);
    }

    void push_back(const NodePtr<T>& node) {
        if (root == nullptr) {
            root = node;
            return;
        }
        // iterate to the last element
        auto n_ptr = root;
        while (n_ptr->next != nullptr) {
            n_ptr = n_ptr->next;
        }
        n_ptr->next = node;
    }

    T visit(size_t idx) {
        size_t i = 0;
        for (auto n_ptr = getRoot(); n_ptr != nullptr;
             n_ptr = n_ptr->getNext()) {
            if (i == idx) return n_ptr->data;
            i++;
        }
        throw std::out_of_range("Index exceeds list size");
    }

    void print() {
        NodePtr<T> n_ptr;
        for (n_ptr = getRoot(); n_ptr->next != nullptr;
             n_ptr = n_ptr->getNext()) {
            std::cout << n_ptr->data << " -> ";
        }
        std::cout << n_ptr->data << std::endl;
    }

    size_t size() {
        size_t size = 0;
        for (auto n_ptr = getRoot(); n_ptr != nullptr; n_ptr = n_ptr->getNext())
            size++;
        return size;
    }
};

}  // namespace linked_lists::shared