#pragma once

#include "binary_tree_node.h"
#include "binary_tree_utilities.h"

namespace tree {

/**
 * @brief BinaryTree data structure
 *
 * @tparam T typename of the data container
 */
template <typename T>
class BinaryTree {
   public:
    NodePtr<T> _root = nullptr;

    /* Default Constructor */
    BinaryTree() {}

    /* Copy Constructor */
    BinaryTree(const BinaryTree<T>&) = default;

    /* List initialization */
    explicit BinaryTree(std::initializer_list<T> list) = delete;

    /* Copy Assignment */
    BinaryTree<T>& operator=(const BinaryTree<T>&) = default;

    /* Move Assignment */
    BinaryTree<T>& operator=(BinaryTree<T>&&) = default;

    virtual ~BinaryTree() {}

    inline bool isEmpty() { return _root == nullptr; }

    inline NodePtr<T> get() { return _root; }

    inline size_t height() { return utilities::getHeight<T>(_root); }

    inline void print() { utilities::printNode<T>(_root); }

    inline bool search(T data) { return utilities::search<T>(_root, data); }

    inline NodePtr<T> insert(NodePtr<T> node) {
        if (!_root) {
            _root = node;
            return _root;
        }
        std::queue<NodePtr<T>> queue;
        queue.push(_root);
        while (!queue.empty()) {
            auto q_node = queue.front();
            queue.pop();
            auto left = q_node->getLeft();
            auto right = q_node->getRight();
            // if found a leaf node, add element
            if (!left) {
                q_node->addLeft(node);
                break;
            }
            // else, add it to the queue
            queue.push(left);
            // if found a leaf node, add element
            if (!right) {
                q_node->addRight(node);
                break;
            }
            // else, add it to the queue
            queue.push(right);
        }
        return _root;
    }

    inline NodePtr<T> insert(T data) {
        auto node = std::make_shared<BinaryTreeNode<T>>(data);
        return insert(node);
    }
};

}  // namespace tree