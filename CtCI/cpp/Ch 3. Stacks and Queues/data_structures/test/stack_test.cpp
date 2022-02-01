#include "stack.h"

#include <gtest/gtest.h>

using namespace stack;

TEST(CH3_STACKS, CONSTRUCTOR_PEEK) {
    Stack<int> stack({1});
    ASSERT_EQ(stack.peek(), 1);
}

TEST(CH3_STACKS, CONSTRUCTOR_POP) {
    Stack<int> stack({1, 2, 3});
    ASSERT_EQ(stack.pop(), 3);
    ASSERT_EQ(stack.pop(), 2);
    ASSERT_EQ(stack.pop(), 1);
}

TEST(CH3_STACKS, RANGE_ERROR) {
    Stack<int> stack;
    EXPECT_THROW(stack.pop(), std::range_error);
    EXPECT_THROW(stack.peek(), std::range_error);
}

TEST(CH3_STACKS, POP_REMOVES) {
    Stack<int> stack({1});
    ASSERT_EQ(stack.pop(), 1);
    EXPECT_THROW(stack.peek(), std::range_error);
}