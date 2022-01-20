#include <gtest/gtest.h>

#include "linked_lists.h"

using namespace std;

TEST(CH2_LINKED_LISTS, CONSTRUCTOR) {
	linked_lists::Node<int> node(0);
	ASSERT_EQ(node.visit(), 0);
}

TEST(CH2_LINKED_LISTS, VISIT) {
	linked_lists::Node<int> node(0);
	for (int i = 1; i < 10; i++) node.push_back(i);
    node.print();
	for (int i = 0; i < 10; i++) {
        ASSERT_EQ(node.visit(i), i);
    }
}

TEST(CH2_LINKED_LISTS, SIZE) {
	linked_lists::Node<int> node(0);
	for (int i = 1; i < 10; i++) node.push_back(i);
    node.print();
	ASSERT_EQ(node.size(), 10);
}
