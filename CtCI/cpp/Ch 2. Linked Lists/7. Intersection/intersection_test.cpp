#include "intersection.h"

#include <gtest/gtest.h>

#include "linked_lists_shared.h"

using namespace std;
using namespace linked_lists::shared;

TEST(CH2_7_INTERSECTION, NO_INTERSECTION) {
    LinkedList<int> list1({0, 1, 2});
    LinkedList<int> list2({0, 1, 2});
    ASSERT_FALSE(findIntersection(list1, list2));
}

TEST(CH2_7_INTERSECTION, INTERSECT_AT_LAST) {
    LinkedList<int> list1({0, 3, 9});
    LinkedList<int> list2({12});
    auto intersection = list2.getRoot();
    list1.push_back(intersection);
    // 0 -> 3 -> 9 - |-> 12
    //               |-> 12
    auto output = findIntersection(list1, list2);
    ASSERT_TRUE(output);
    ASSERT_EQ(output->visit(), 12);
    ASSERT_EQ(intersection, output);
}

TEST(CH2_7_INTERSECTION, INTERSECT_AT_MIDDLE) {
    LinkedList<int> list1({0, 3, 9});
    list1.print();

    auto intersection = list1.getRoot()->next;
    std::cout << "Intersection: " << intersection << std::endl;

    LinkedList<int> list2;
    list2.push_back(intersection);
    list2.print();
    // 0 -|-> 3 -> 9
    //    |-> 3 -> 9
    auto output = findIntersection(list1, list2);
    ASSERT_TRUE(output);
    ASSERT_EQ(output->visit(), 3);
    ASSERT_EQ(intersection, output);
}

TEST(CH2_7_INTERSECTION, BOOK_EXAMPLE) {
    LinkedList<int> list1({4, 6, 7});
    list1.print();

    auto intersection = list1.getRoot()->getNext()->getNext();  // 7
    std::cout << "Intersection: " << intersection << std::endl;

    LinkedList<int> list2({3, 1, 5, 9});
    list2.push_back(intersection);
    list2.print();

    auto output = findIntersection(list1, list2);
    ASSERT_TRUE(output);
    ASSERT_EQ(output->visit(), 7);
    ASSERT_EQ(intersection, output);
}

TEST(CH2_7_INTERSECTION, IGNORE_VALUES) {
    LinkedList<int> list1({4, 6, 7});
    list1.print();

    LinkedList<int> list2({4, 6, 7});
    list2.print();

    auto output = findIntersection(list1, list2);
    ASSERT_FALSE(output);
}