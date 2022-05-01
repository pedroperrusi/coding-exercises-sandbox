#pragma once
#include <iostream>
#include <algorithm>

class BinaryTreeNode {
public:
    BinaryTreeNode *_left = nullptr;
    BinaryTreeNode *_right = nullptr;
    int _data;

    BinaryTreeNode(int data) { _data = data; }

    ~BinaryTreeNode() {
        delete _left;
        delete _right;
    }

    void addLeft(int data) {
        if (_left) {
            _left->_data = data;
            return;
        }
        _left = new BinaryTreeNode(data);
        return;
    }

    void addRight(int data) {
        if (_right) {
            _right->_data = data;
            return;
        }
        _right = new BinaryTreeNode(data);
        return;
    }
};

inline int getHeight(BinaryTreeNode* root) {
    if (!root) return 0;
    return std::max(getHeight(root->_left), getHeight(root->_right)) + 1;
}

// computes height but returns -1 when tree is not balanced
inline int checkHeight(BinaryTreeNode* root) {
    if (!root) return 0;
    // left branch
    int left_height = checkHeight(root->_left);
    if (left_height == -1) return -1;
    // right branch
    int right_height = checkHeight(root->_right);
    if (right_height == -1) return -1;
    // check for balanced
    if (std::abs(left_height - right_height) > 1) return -1;
    return std::max(left_height, right_height) + 1;
}

inline bool isBalanced(BinaryTreeNode* root) {
    if (!root) return false;
    if (checkHeight(root) == -1) return false;
    return true;
}