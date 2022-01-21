#include <gtest/gtest.h>

#include "linked_lists.h"

using namespace std;

TEST(CH2_LINKED_LISTS, CONSTRUCTOR) {
	linked_lists::Node<int> node(0);
	ASSERT_EQ(node.visit(), 0);
	linked_lists::LinkedList<int> list;
	ASSERT_EQ(list.size(), 0);
}

TEST(CH2_LINKED_LISTS, VISIT) {
	linked_lists::LinkedList<int> list;
	for (int i = 0; i < 10; i++) list.push_back(i);
    list.print();
	for (int i = 0; i < 10; i++) {
        ASSERT_EQ(list.visit(i), i);
    }
}

TEST(CH2_LINKED_LISTS, SIZE) {
	linked_lists::LinkedList<int> list;
	for (int i = 0; i < 10; i++) list.push_back(i);
    list.print();
	ASSERT_EQ(list.size(), 10);
}
