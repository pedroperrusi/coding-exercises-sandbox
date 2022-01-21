#include <iostream>

namespace linked_lists {

template <typename T>
class Node {
  public:
  
    Node<T>* next = nullptr;
    T data;

    Node(T d) : data(d) {}

    virtual ~Node() { delete next; }

    inline T visit() { return this->data; }

    inline void set(T data) { this->data = data; }

};

template <typename T>
class LinkedList {
  private:
    Node<T>* root = nullptr;

  public:
    LinkedList(): root(nullptr) {}
    virtual ~LinkedList() { delete root; }

    inline Node<T>* getRoot() { return root; }

    void push_back(T d) {
        Node<T>* node = new Node<T>(d);
        if (root == nullptr) {
            root = node;
            return;
        }
        // iterate to the last element
        Node<T>* n_ptr = root;
        while(n_ptr->next != nullptr) { 
            n_ptr = n_ptr->next; 
        }
        n_ptr->next = node;
    }

    T visit(size_t idx) {
        size_t i = 0;
        for (const Node<T>* n_ptr = getRoot(); n_ptr != nullptr; n_ptr = n_ptr->next) {
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
        for (const Node<T>* n_ptr = getRoot(); n_ptr != nullptr; n_ptr = n_ptr->next) size++;
        return size;
    }

};

}