#include "linked_lists_unique.h"

#include <gtest/gtest.h>

using namespace std;
using namespace linked_lists::unique;

TEST(CH2_LINKED_LISTS, CONSTRUCTOR) {
    Node<int> node(0);
    ASSERT_EQ(node.visit(), 0);
    ASSERT_FALSE(node.next);
    LinkedList<int> list;
    ASSERT_EQ(list.size(), 0);
    ASSERT_FALSE(list.getRoot());
}

TEST(CH2_LINKED_LISTS, VISIT) {
    LinkedList<int> list;
    for (int i = 0; i < 10; i++) list.push_back(i);
    list.print();
    for (int i = 0; i < 10; i++) {
        ASSERT_EQ(list.visit(i), i);
    }
}

TEST(CH2_LINKED_LISTS, SIZE) {
    LinkedList<int> list;
    for (int i = 0; i < 10; i++) list.push_back(i);
    list.print();
    ASSERT_EQ(list.size(), 10);
}

TEST(CH2_LINKED_LISTS, DEALLOCATION) {
    LinkedList<int> list;
    list.push_back(0);
    list.push_back(1);
    ASSERT_TRUE(list.getRoot());
    auto node_ptr = list.getRoot();
    ASSERT_TRUE(node_ptr->getNext());
    node_ptr->next = nullptr;
    ASSERT_FALSE(node_ptr->getNext());
}

TEST(CH2_LINKED_LISTS, CLEAN) {
    LinkedList<int> list;
    for (int i = 0; i < 10; i++) list.push_back(i);
    ASSERT_TRUE(list.getRoot());
    list.clean();
    ASSERT_FALSE(list.getRoot());
}

TEST(CH2_LINKED_LISTS, PUSH_FRONT) {
    LinkedList<int> list;
    for (int i = 0; i < 10; i++) list.push_front(i);
    list.print();
    for (int i = 0; i < 10; i++) {
        ASSERT_EQ(list.visit(i), 9-i);
    }
}