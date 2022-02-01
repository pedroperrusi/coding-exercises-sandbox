#include "loop_detection.h"

#include <gtest/gtest.h>

#include "linked_lists_shared.h"

using namespace std;
using namespace linked_lists::shared;

TEST(CH2_7_INTERSECTION, NO_LOOP) {
    LinkedList<int> list({0, 1, 2});
    ASSERT_FALSE(detectLoop(list));
}

TEST(CH2_7_INTERSECTION, LOOPED_LIST) {
    LinkedList<int> list({0, 1, 2});
    list.push_back(list.getRoot());
    auto loop = detectLoop(list);
    ASSERT_TRUE(loop);
    ASSERT_EQ(loop, list.getRoot());
}

TEST(CH2_7_INTERSECTION, PREFIXED_LOOPED_LIST) {
    LinkedList<int> list({0, 1, 2});
    LinkedList<int> loop({3, 4, 5, 5, 4, 3});

    auto loop_node = list.getRoot()->getNext()->getNext();  // element 2

    loop.push_back(loop_node);
    list.push_back(loop.getRoot());

    auto detected_begining = detectLoop(list);

    ASSERT_TRUE(detected_begining); 
    ASSERT_EQ(detected_begining, loop_node);
}