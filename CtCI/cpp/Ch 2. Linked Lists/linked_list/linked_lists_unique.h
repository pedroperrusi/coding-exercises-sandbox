#include <iostream>
#include <memory>

namespace linked_lists {

/**
 * @brief Single linked list node class
 * Designed to be the owner of next element.
 * Warning: memory deallocation is not automatic
 * Explicit calls for deallocation should either assign to null, or move the smart pointer.
 * Options:
 *      node->next = nullptr;
 *      node->next = std::move(other_node);
 * Raw pointers obtained with getNext do not own the neighboor and cannot delete it.
 * @tparam T typename of the data container
 */
template <typename T>
class Node {
   public:
    std::unique_ptr<Node<T>> next = nullptr;
    T data;

    Node(T d) : data(d) {}

    inline T visit() { return this->data; }
    inline void set(T data) { this->data = data; }
    inline Node<T>* getNext() const { return next.get(); }
};

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
    std::unique_ptr<Node<T>> root = nullptr;

    /* Default Constructor */
    LinkedList() {}

    /* Copy Constructor */
    LinkedList(const LinkedList<T>& list) = delete;

    /* List initialization */
    LinkedList(std::initializer_list<T> list) {
        for (const auto& item : list) push_back(item);
    }

    /* Copy Assignment */
    LinkedList<T>& operator=(const LinkedList<T>& list) = delete;

    /* Move Assignment */
    LinkedList<T>& operator=(LinkedList<T>&& list) {
        if (this != &list) {
            clean();
            root = std::move(list.root);
        }
        return *this;
    };

    virtual ~LinkedList() { clean(); }

    inline Node<T>* getRoot() const { return root.get(); }

    void clean() {
        while (root) {
            root = std::move(root->next);
        }
    }

    void push_front(T d) {
        auto node = std::make_unique<Node<T>>(d);
        if (root == nullptr) {
            root = std::move(node);
            return;
        }
        // copy root to node
        node->next = std::move(root->next);
        node->set(root->visit());
        // change root and point it to node
        root->set(d);
        root->next = std::move(node);
    }

    void push_back(T d) {
        auto node = std::make_unique<Node<T>>(d);
        if (root == nullptr) {
            root = std::move(node);
            return;
        }
        // else, iterate to the last element
        Node<T>* n_ptr = getRoot();
        while (n_ptr->next != nullptr) {
            n_ptr = n_ptr->getNext();
        }
        n_ptr->next = std::move(node);
    }

    T visit(size_t idx) {
        size_t i = 0;
        for (const Node<T>* n_ptr = getRoot(); n_ptr != nullptr;
             n_ptr = n_ptr->getNext()) {
            if (i == idx) return n_ptr->data;
            i++;
        }
        return T();
    }

    void print() {
        const Node<T>* n_ptr;
        for (n_ptr = getRoot(); n_ptr->next != nullptr;
             n_ptr = n_ptr->getNext()) {
            std::cout << n_ptr->data << " -> ";
        }
        std::cout << n_ptr->data << std::endl;
    }

    size_t size() {
        size_t size = 0;
        for (const Node<T>* n_ptr = getRoot(); n_ptr != nullptr;
             n_ptr = n_ptr->getNext())
            size++;
        return size;
    }
};

}  // namespace linked_lists