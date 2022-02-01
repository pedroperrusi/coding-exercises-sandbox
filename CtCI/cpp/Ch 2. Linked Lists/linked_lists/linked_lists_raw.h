#pragma once
#include <iostream>

namespace linked_lists::raw {

template <typename T>
class Node {
   public:
    Node<T>* next = nullptr;
    T data;

    explicit Node(T d) : data(d) {}

    virtual ~Node() {
        delete next;
        next = nullptr;
    }

    inline T visit() { return this->data; }

    inline void set(T data) { this->data = data; }

    inline Node<T>* getNext() const { return next; }
};

template <typename T>
class LinkedList {
   private:
    Node<T>* root = nullptr;

   public:
    LinkedList() : root(nullptr) {}
    /* List initialization */
    LinkedList(std::initializer_list<T> list) {
        for (const auto& item : list) push_back(item);
    }

    virtual ~LinkedList() { clean(); }

    inline Node<T>* getRoot() { return root; }

    void clean() {
        delete root;
        root = nullptr;
    }

    void push_front(Node<T>* node) {
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
        Node<T>* node = new Node<T>(d);
        push_front(node);
    }

    void push_back(T d) {
        Node<T>* node = new Node<T>(d);
        push_back(node);
    }

    void push_back(Node<T>* node) {
        if (root == nullptr) {
            root = node;
            return;
        }
        // iterate to the last element
        Node<T>* n_ptr = root;
        while (n_ptr->next != nullptr) {
            n_ptr = n_ptr->next;
        }
        n_ptr->next = node;
    }

    T visit(size_t idx) {
        size_t i = 0;
        for (const Node<T>* n_ptr = getRoot(); n_ptr != nullptr;
             n_ptr = n_ptr->next) {
            if (i == idx) return n_ptr->data;
            i++;
        }
        return T();
    }

    void print() {
        const Node<T>* n_ptr;
        for (n_ptr = getRoot(); n_ptr->next != nullptr; n_ptr = n_ptr->next) {
            std::cout << n_ptr->data << " -> ";
        }
        std::cout << n_ptr->data << std::endl;
    }

    size_t size() {
        size_t size = 0;
        for (const Node<T>* n_ptr = getRoot(); n_ptr != nullptr;
             n_ptr = n_ptr->next)
            size++;
        return size;
    }
};

}  // namespace linked_lists::raw