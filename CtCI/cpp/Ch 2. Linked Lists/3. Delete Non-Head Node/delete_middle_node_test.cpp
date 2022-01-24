#include "delete_middle_node.h"

#include <gtest/gtest.h>

using namespace std;
using namespace linked_lists;

TEST(CH2_3_MIDDLE_NON_HEAD_NODE, MIDDLE_NODE) {
    LinkedList<int> list({0, 1, 2});

    list.print();
    deleteMiddleNode<int>(list.getRoot()->getNext());
    list.print();

    ASSERT_EQ(list.visit(0), 0);
    ASSERT_EQ(list.visit(1), 2);
    ASSERT_EQ(list.size(), 2);
}
