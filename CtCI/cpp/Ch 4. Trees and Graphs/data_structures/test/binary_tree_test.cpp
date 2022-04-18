#include "binary_tree.h"
#include <gtest/gtest.h>

using namespace tree;

TEST(CH4_TREE, CONSTRUCTOR_PEEK) {
    BinaryTree<int> tree;

    ASSERT_TRUE(tree.isEmpty());
}

TEST(CH4_TREE, INSERTION_PRINT) {
    BinaryTree<int> tree;

    for (int i = 0; i < 10; i++) tree.insert(i);
    
    ASSERT_FALSE(tree.isEmpty());

    tree.print();
}

TEST(CH4_TREE, GET_HEIGHT) {
    BinaryTree<int> tree;

    for (int i = 0; i < 10; i++) tree.insert(i);

    tree.print();

    ASSERT_EQ(tree.height(), 4);
}

TEST(CH4_TREE, SEARCH) {
    BinaryTree<int> tree;

    for (int i = 0; i < 10; i++) tree.insert(i);

    tree.print();

    ASSERT_TRUE(tree.search(0));
    ASSERT_TRUE(tree.search(4));
    ASSERT_FALSE(tree.search(-1));
    ASSERT_FALSE(tree.search(11));    
}