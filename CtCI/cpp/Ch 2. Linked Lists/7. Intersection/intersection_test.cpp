#include <gtest/gtest.h>

#include "intersection.h"
#include "linked_lists_raw.h"

using namespace std;
using namespace linked_lists::raw;

TEST(CH2_7_INTERSECTION, NO_INTERSECTION) {
    LinkedList<int> list1({0, 1, 2});
    LinkedList<int> list2({0, 1, 2});
    ASSERT_FALSE(findIntersection(list1, list2));
}

// TEST(CH2_7_INTERSECTION, INTERSECT_AT_LAST) {
//     LinkedList<int> list1({0, 3, 9});
//     LinkedList<int> list2({12});
//     Node<int>* intersection = list2.getRoot();
//     list1.push_back(intersection);
//     // 0 -> 3 -> 9 |
//     //              -> 12
//     Node<int>* output = findIntersection(list1, list2);
//     ASSERT_TRUE(output);
//     ASSERT_EQ(output->visit(), 12);
//     ASSERT_EQ(intersection, output);
// }