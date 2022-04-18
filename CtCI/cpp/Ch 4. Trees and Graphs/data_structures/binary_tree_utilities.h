#pragma once

#include "binary_tree_node.h"

namespace tree::utilities {
template <typename T>
bool search(const NodePtr<T> node, T data) {
    if (!node) return false;
    if (node->visit() == data) return true;
    return (search(node->getLeft(), data) || search(node->getRight(), data));
}

template <typename T>
size_t getHeight(const NodePtr<T> node) {
    if (!node) return 0;
    return (std::max(getHeight<T>(node->getLeft()),
                     getHeight<T>(node->getRight())) +
            1);
}

template <typename T>
void printNode(const NodePtr<T> node, const std::string& prefix = "",
               bool isLeft = false) {
    if (node) {
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──");

        // print the value of the node
        std::cout << node->visit() << std::endl;

        // enter the next tree level - left and right branch
        printNode<T>(node->getLeft(), prefix + (isLeft ? "│   " : "    "),
                     true);
        printNode<T>(node->getRight(), prefix + (isLeft ? "│   " : "    "),
                     false);
    }
}
}  // namespace tree::utilities