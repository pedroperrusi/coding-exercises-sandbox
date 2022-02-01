#include "linked_lists_shared.h"

#include <gtest/gtest.h>

using namespace std;
using namespace linked_lists::shared;

TEST(CH2_LINKED_LISTS_SHARED, CONSTRUCTOR) {
    Node<int> node(0);
    ASSERT_EQ(node.visit(), 0);
    ASSERT_FALSE(node.next);
    LinkedList<int> list;
    ASSERT_EQ(list.size(), 0);
    ASSERT_FALSE(list.getRoot());
}

TEST(CH2_LINKED_LISTS_SHARED, VISIT) {
    LinkedList<int> list;
    for (int i = 0; i < 10; i++) list.push_back(i);
    list.print();
    for (int i = 0; i < 10; i++) {
        ASSERT_EQ(list.visit(i), i);
    }
}

TEST(CH2_LINKED_LISTS_SHARED, SIZE) {
    LinkedList<int> list;
    for (int i = 0; i < 10; i++) list.push_back(i);
    list.print();
    ASSERT_EQ(list.size(), 10);
}

TEST(CH2_LINKED_LISTS_SHARED, DEALLOCATION) {
    LinkedList<int> list;
    list.push_back(0);
    list.push_back(1);
    ASSERT_TRUE(list.getRoot());
    auto node_ptr = list.getRoot();
    ASSERT_TRUE(node_ptr->getNext());
    node_ptr->next = nullptr;
    ASSERT_FALSE(node_ptr->getNext());
}

TEST(CH2_LINKED_LISTS_SHARED, PUSH_FRONT) {
    LinkedList<int> list;
    for (int i = 0; i < 10; i++) list.push_front(i);
    list.print();
    for (int i = 0; i < 10; i++) {
        ASSERT_EQ(list.visit(i), 9 - i);
    }
}

TEST(CH2_LINKED_LISTS_SHARED, PUSH_BACK_NODES) {
    LinkedList<int> list;
    auto node = createNode(0);
    list.push_back(node);
    ASSERT_TRUE(node);
    ASSERT_TRUE(list.getRoot());
    ASSERT_EQ(list.getRoot(), node);
}

TEST(CH2_LINKED_LISTS_SHARED, PUSH_FRONT_NODES) {
    LinkedList<int> list;
    auto node = createNode(0);
    list.push_front(node);
    ASSERT_TRUE(node);
    ASSERT_TRUE(list.getRoot());
    ASSERT_EQ(list.getRoot(), node);
}

TEST(CH2_LINKED_LISTS_SHARED, SHARED_NODE) {
    LinkedList<int> list1;
    auto node = createNode(0);
    list1.push_back(node);

    list1.print();
    ASSERT_TRUE(node);

    LinkedList<int> list2;
    list2.push_back(node);
    list2.print();

    ASSERT_EQ(list1.getRoot(), list2.getRoot());
}