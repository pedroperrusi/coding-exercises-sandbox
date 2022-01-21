#include <gtest/gtest.h>

#include "remove_dups.h"

using namespace std;

TEST(CH2_REMOVE_DUPS, REMOVE_DUPS_SIDE_BY_SIDE) {
	linked_lists::Node<int> list(0);
	list.push_back(0);
	ASSERT_EQ(visit(list, 0), 0);
	ASSERT_EQ(visit(list, 1), 0);
	ASSERT_EQ(size(list), 2);

	print(list);
	removeDups(list);
	print(list);

	ASSERT_EQ(visit(list, 0), 0);
	ASSERT_EQ(size(list), 1);
}

TEST(CH2_REMOVE_DUPS, REMOVE_DUPS) {
	linked_lists::Node<int> list(0);
	list.push_back(1);
	list.push_back(0);
	list.push_back(1);
	list.push_back(0);
	ASSERT_EQ(visit(list, 0), 0);
	ASSERT_EQ(visit(list, 1), 1);
	ASSERT_EQ(visit(list, 2), 0);
	ASSERT_EQ(visit(list, 3), 1);
	ASSERT_EQ(visit(list, 4), 0);
	ASSERT_EQ(size(list), 5);

	print(list);
	removeDups(list);
	print(list);

	ASSERT_EQ(visit(list, 0), 0);
	ASSERT_EQ(visit(list, 1), 1);
	ASSERT_EQ(size(list), 2);
}

TEST(CH2_REMOVE_DUPS_NO_BUFFER, REMOVE_DUPS_SIDE_BY_SIDE) {
	linked_lists::Node<int> list(0);
	list.push_back(0);
	ASSERT_EQ(visit(list, 0), 0);
	ASSERT_EQ(visit(list, 1), 0);
	ASSERT_EQ(size(list), 2);

	print(list);
	
	removeDupsNoBuffer(list);
	print(list);

	ASSERT_EQ(visit(list, 0), 0);
	ASSERT_EQ(size(list), 1);
}

TEST(CH2_REMOVE_DUPS_NO_BUFFER, REMOVE_DUPS) {
	linked_lists::Node<int> list(0);
	list.push_back(1);
	list.push_back(0);
	list.push_back(1);
	list.push_back(0);
	ASSERT_EQ(visit(list, 0), 0);
	ASSERT_EQ(visit(list, 1), 1);
	ASSERT_EQ(visit(list, 2), 0);
	ASSERT_EQ(visit(list, 3), 1);
	ASSERT_EQ(visit(list, 4), 0);
	ASSERT_EQ(size(list), 5);

	print(list);
	removeDupsNoBuffer(list);
	print(list);

	ASSERT_EQ(visit(list, 0), 0);
	ASSERT_EQ(visit(list, 1), 1);
	ASSERT_EQ(size(list), 2);
}
