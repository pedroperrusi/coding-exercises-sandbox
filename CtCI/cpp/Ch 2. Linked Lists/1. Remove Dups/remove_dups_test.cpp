#include <gtest/gtest.h>

#include "remove_dups.h"

using namespace std;

TEST(CH2_REMOVE_DUPS, REMOVE_DUPS_SIDE_BY_SIDE) {
	linked_lists::LinkedList<int> list;
	list.push_back(0);
	list.push_back(0);
	ASSERT_EQ(list.visit(0), 0);
	ASSERT_EQ(list.visit(1), 0);
	ASSERT_EQ(list.size(), 2);

	list.print();
	removeDups(list);
	list.print();

	ASSERT_EQ(list.visit(0), 0);
	ASSERT_EQ(list.size(), 1);
}

TEST(CH2_REMOVE_DUPS, REMOVE_DUPS) {
	linked_lists::LinkedList<int> list;
	list.push_back(0);
	list.push_back(1);
	list.push_back(0);
	list.push_back(1);
	list.push_back(0);
	ASSERT_EQ(list.visit(0), 0);
	ASSERT_EQ(list.visit(1), 1);
	ASSERT_EQ(list.visit(2), 0);
	ASSERT_EQ(list.visit(3), 1);
	ASSERT_EQ(list.visit(4), 0);
	ASSERT_EQ(list.size(), 5);

	list.print();
	removeDups(list);
	list.print();

	ASSERT_EQ(list.visit(0), 0);
	ASSERT_EQ(list.visit(1), 1);
	ASSERT_EQ(list.size(), 2);
}

TEST(CH2_REMOVE_DUPS_NO_BUFFER, REMOVE_DUPS_SIDE_BY_SIDE) {
	linked_lists::LinkedList<int> list;
	list.push_back(0);
	list.push_back(0);
	ASSERT_EQ(list.visit(0), 0);
	ASSERT_EQ(list.visit(1), 0);
	ASSERT_EQ(list.size(), 2);

	list.print();
	removeDupsNoBuffer(list);
	list.print();

	ASSERT_EQ(list.visit(0), 0);
	ASSERT_EQ(list.size(), 1);
}

TEST(CH2_REMOVE_DUPS_NO_BUFFER, REMOVE_DUPS) {
	linked_lists::LinkedList<int> list;
	list.push_back(0);
	list.push_back(1);
	list.push_back(0);
	list.push_back(1);
	list.push_back(0);
	ASSERT_EQ(list.visit(0), 0);
	ASSERT_EQ(list.visit(1), 1);
	ASSERT_EQ(list.visit(2), 0);
	ASSERT_EQ(list.visit(3), 1);
	ASSERT_EQ(list.visit(4), 0);
	ASSERT_EQ(list.size(), 5);

	list.print();
	removeDupsNoBuffer(list);
	list.print();

	ASSERT_EQ(list.visit(0), 0);
	ASSERT_EQ(list.visit(1), 1);
	ASSERT_EQ(list.size(), 2);
}
