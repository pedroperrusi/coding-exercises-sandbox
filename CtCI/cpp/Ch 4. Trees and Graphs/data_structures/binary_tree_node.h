#pragma once
#include <exception>
#include <iostream>
#include <memory>
#include <queue>

namespace tree {

/**
* @brief Hidden BinaryTreeNode class
*/
template <typename T>
class BinaryTreeNode {
   public:
    T _data;

    using Ptr = std::shared_ptr<BinaryTreeNode>;
    std::pair<Ptr, Ptr> _children = {nullptr, nullptr};

    explicit BinaryTreeNode(T d) : _data(d) {}

    inline T visit() { return _data; }

    inline void addLeft(Ptr _node) { _children.first = _node; }

    inline void createLeft(T d) {
        addLeft(std::make_shared<BinaryTreeNode>(d));
    }

    inline void addRight(Ptr _node) { _children.second = _node; }

    inline void createRight(T d) {
        addRight(std::make_shared<BinaryTreeNode>(d));
    }

    inline Ptr getLeft() { return _children.first; }

    inline Ptr getRight() { return _children.second; }
}; 

/** Alias to BinaryTreeNode Smart Pointer */
template <typename T>
using NodePtr = typename BinaryTreeNode<T>::Ptr;

}  // namespace tree