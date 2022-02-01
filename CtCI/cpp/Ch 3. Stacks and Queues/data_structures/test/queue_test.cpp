#include "queue.h"

#include <gtest/gtest.h>

using namespace queue;

TEST(CH3_QUEUE, CONSTRUCTOR_PEEK) {
    Queue<int> queue({1});
    ASSERT_EQ(queue.peek(), 1);
}

TEST(CH3_QUEUE, CONSTRUCTOR_POP) {
    Queue<int> queue({1, 2, 3});
    ASSERT_EQ(queue.pop(), 1);
    ASSERT_EQ(queue.pop(), 2);
    ASSERT_EQ(queue.pop(), 3);
}

TEST(CH3_QUEUE, RANGE_ERROR) {
    Queue<int> queue;
    EXPECT_THROW(queue.pop(), std::range_error);
    EXPECT_THROW(queue.peek(), std::range_error);
}
 
TEST(CH3_QUEUE, POP_REMOVES) {
    Queue<int> queue({1});
    ASSERT_EQ(queue.pop(), 1);
    EXPECT_THROW(queue.peek(), std::range_error);
}