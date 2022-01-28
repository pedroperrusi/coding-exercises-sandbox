#include "partition.h"

#include <gtest/gtest.h>

using namespace std;
using namespace linked_lists::unique;

TEST(CH2_4_PARTITION, NO_WORK_HERE) {
    LinkedList<int> list({0, 2, 3});

    list.print();
    partitionWithSublists(list, 5);
    list.print();

    ASSERT_EQ(list.visit(0), 0);
    ASSERT_EQ(list.visit(1), 2);
    ASSERT_EQ(list.visit(2), 3);
}

TEST(CH2_4_PARTITION, TWO_ELEMENTS) {
    LinkedList<int> list({2, 0});

    list.print();
    partitionWithSublists(list, 1);
    list.print();

    ASSERT_EQ(list.visit(0), 0);
    ASSERT_EQ(list.visit(1), 2);
}

TEST(CH2_4_PARTITION, LONG_LIST_ELEMENTS) {
    LinkedList<int> list({10, 5, 3, 1});

    list.print();
    partitionWithSublists(list, 2);
    list.print();

    ASSERT_EQ(list.visit(0), 1);
    ASSERT_EQ(list.size(), 4);
}
