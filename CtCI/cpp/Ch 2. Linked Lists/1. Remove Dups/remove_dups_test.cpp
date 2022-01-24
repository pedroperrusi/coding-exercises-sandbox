#include "remove_dups.h"

#include <gtest/gtest.h>

using namespace std;
using LinkedList = LinkedList;

TEST(CH2_REMOVE_DUPS, REMOVE_DUPS_SIDE_BY_SIDE) {
    LinkedList list({0, 0});

    list.print();
    removeDups(list);
    list.print();

    ASSERT_EQ(list.visit(0), 0);
    ASSERT_EQ(list.size(), 1);
}

TEST(CH2_REMOVE_DUPS, REMOVE_DUPS) {
    LinkedList list({0, 1, 0, 1, 0});

    list.print();
    removeDups(list);
    list.print();

    ASSERT_EQ(list.visit(0), 0);
    ASSERT_EQ(list.visit(1), 1);
    ASSERT_EQ(list.size(), 2);
}

TEST(CH2_REMOVE_DUPS_NO_BUFFER, REMOVE_DUPS_SIDE_BY_SIDE) {
    LinkedList list({0, 0});

    list.print();
    removeDupsNoBuffer(list);
    list.print();

    ASSERT_EQ(list.visit(0), 0);
    ASSERT_EQ(list.size(), 1);
}

TEST(CH2_REMOVE_DUPS_NO_BUFFER, REMOVE_DUPS) {
    LinkedList list({0, 1, 0, 1, 0});

    list.print();
    removeDupsNoBuffer(list);
    list.print();

    ASSERT_EQ(list.visit(0), 0);
    ASSERT_EQ(list.visit(1), 1);
    ASSERT_EQ(list.size(), 2);
}
