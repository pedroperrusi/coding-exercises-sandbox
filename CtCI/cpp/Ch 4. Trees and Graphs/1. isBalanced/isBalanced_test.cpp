#include "isBalanced.h"

#include <gtest/gtest.h>

TEST(BINARY_TREE, INIT) {
    BinaryTreeNode node(0);
    ASSERT_TRUE(node._data == 0);
    ASSERT_TRUE(node._left == nullptr);
    ASSERT_TRUE(node._right == nullptr);
}

TEST(BINARY_TREE, INSERT_NODES) {
    BinaryTreeNode node(0);
    node.addLeft(1);
    node.addRight(2);
    ASSERT_TRUE(node._left->_data == 1);
    ASSERT_TRUE(node._right->_data == 2);
}

TEST(BINARY_TREE, IS_NOT_BALANCED) {
    BinaryTreeNode node(0);
    node.addLeft(1);
    node._left->addLeft(2);
    ASSERT_FALSE(isBalanced(&node));
} 

TEST(BINARY_TREE, CHECK_HEIGHT) {
    BinaryTreeNode node(0);
    node.addLeft(1);
    node._left->addLeft(2);
    ASSERT_NE(checkHeight(&node), getHeight(&node));
} 

TEST(BINARY_TREE, IS_PERFECTLY_BALANCED) {
    BinaryTreeNode node(0);
    node.addLeft(1);
    node.addRight(2);
    ASSERT_TRUE(isBalanced(&node));
} 

TEST(BINARY_TREE, IS_BALANCED) {
    BinaryTreeNode node(0);
    node.addLeft(1);
    node.addRight(2);
    node._left->addRight(4);
    ASSERT_TRUE(isBalanced(&node));
}  