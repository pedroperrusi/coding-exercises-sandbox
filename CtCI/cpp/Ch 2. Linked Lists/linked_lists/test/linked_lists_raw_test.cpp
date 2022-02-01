#include "linked_lists_raw.h"

#include <gtest/gtest.h>

using namespace std;

TEST(CH2_LINKED_LISTS_RAW, CONSTRUCTOR) {
    linked_lists::raw::Node<int> node(0);
    ASSERT_EQ(node.visit(), 0);
    ASSERT_FALSE(node.next);
    linked_lists::raw::LinkedList<int> list;
    ASSERT_EQ(list.size(), 0);
    ASSERT_FALSE(list.getRoot());
}

TEST(CH2_LINKED_LISTS_RAW, VISIT) {
    linked_lists::raw::LinkedList<int> list;
    for (int i = 0; i < 10; i++) list.push_back(i);
    list.print();
    for (int i = 0; i < 10; i++) {
        ASSERT_EQ(list.visit(i), i);
    }
}

TEST(CH2_LINKED_LISTS_RAW, SIZE) {
    linked_lists::raw::LinkedList<int> list;
    for (int i = 0; i < 10; i++) list.push_back(i);
    list.print();
    ASSERT_EQ(list.size(), 10);
}

TEST(CH2_LINKED_LISTS_RAW, CLEAN) {
    linked_lists::raw::LinkedList<int> list;
    for (int i = 0; i < 10; i++) list.push_back(i);
    ASSERT_TRUE(list.getRoot());
    list.clean();
    ASSERT_FALSE(list.getRoot());
}

TEST(CH2_LINKED_LISTS_RAW, PUSH_FRONT) {
    linked_lists::raw::LinkedList<int> list;
    for (int i = 0; i < 10; i++) list.push_front(i);
    list.print();
    for (int i = 0; i < 10; i++) {
        ASSERT_EQ(list.visit(i), 9 - i);
    }
}

TEST(CH2_LINKED_LISTS_RAW, PUSH_BACK_NODES) {
    linked_lists::raw::LinkedList<int> list;
    auto node = new linked_lists::raw::Node<int>(0);
    list.push_back(node);
    ASSERT_TRUE(node);
    ASSERT_TRUE(list.getRoot());
    ASSERT_EQ(list.getRoot(), node);
}

TEST(CH2_LINKED_LISTS_RAW, PUSH_FRONT_NODES) {
    linked_lists::raw::LinkedList<int> list;
    auto node = new linked_lists::raw::Node<int>(0);
    list.push_front(node);
    ASSERT_TRUE(node);
    ASSERT_TRUE(list.getRoot());
    ASSERT_EQ(list.getRoot(), node);
}

// Results in memory leak if using automatic destructor
// TODO: Decide weather give entire power to the user or not.
// TEST(CH2_LINKED_LISTS_RAW, SHARED_NODE) {
//     linked_lists::raw::LinkedList<int> list1;
//     auto node = new linked_lists::raw::Node<int>(0);
//     list1.push_back(node);

//     list1.print();
//     ASSERT_TRUE(node);

//     linked_lists::raw::LinkedList<int> list2;
//     list2.push_back(node);
//     list2.print();

//     ASSERT_EQ(list1.getRoot(), list2.getRoot());
// }