#include <iostream>

namespace linked_lists {

template <typename T>
class Node {
  public:
  
    Node<T>* next = nullptr;
    T data;

    Node(T d) : data(d) {}

    virtual ~Node() { delete next; }

    void push_back(T d) {
        Node* node = new Node<T>(d);
        // iterate to the last element
        Node* n_ptr;
        for (n_ptr = this; n_ptr->next != nullptr; n_ptr = n_ptr->next) {}
        n_ptr->next = node;
    }


    T visit() {
        return this->data;
    }

    void set(T data) {
        this->data = data;
    }

};

template <typename T>
T visit(const Node<T>& node, size_t idx) {
    size_t i = 0;
    for (const Node<T>* n_ptr = &node; n_ptr != nullptr; n_ptr = n_ptr->next) {
        if (i == idx) return n_ptr->data;
        i++;
    }
    return T();
}

template <typename T>
void print(const Node<T>& node) {
    const Node<T>* n_ptr;
    for (n_ptr = &node; n_ptr->next != nullptr; n_ptr = n_ptr->next) {
        std::cout << n_ptr->data << " -> ";
    }
    std::cout << n_ptr->data << std::endl;
}

template <typename T>
size_t size(const Node<T>& node) {
    size_t size = 0;
    for (const Node<T>* n_ptr = &node; n_ptr != nullptr; n_ptr = n_ptr->next) size++;
    return size;
}

}