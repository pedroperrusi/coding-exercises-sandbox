#include "fixed_multi_stack.h"

#include <gtest/gtest.h>

#include <stdexcept>

TEST(CH3_1_THREE_IN_ONE_FIXED_STACK, PUSH_PEEK) {
    FixedMultiStack<int, 9, 3> stack;
    stack.push(0, 10);
    ASSERT_EQ(stack.peek(0), 10);
}

TEST(CH3_1_THREE_IN_ONE_FIXED_STACK, PUSH_POP) {
    FixedMultiStack<int, 9, 3> stack;
    stack.push(0, 10);
    ASSERT_EQ(stack.pop(0), 10);
}

TEST(CH3_1_THREE_IN_ONE_FIXED_STACK, POP_OUT_OF_RANGE) {
    FixedMultiStack<int, 9, 3> stack;
    stack.push(0, 10);
    ASSERT_EQ(stack.pop(0), 10);
    EXPECT_THROW(stack.pop(0), std::range_error);
}

TEST(CH3_1_THREE_IN_ONE_FIXED_STACK, PEEK_OUT_OF_RANGE) {
    FixedMultiStack<int, 9, 3> stack;
    EXPECT_THROW(stack.peek(0), std::range_error);
}

TEST(CH3_1_THREE_IN_ONE_FIXED_STACK, STACK_ID_OUT_OF_RANGE) {
    FixedMultiStack<int, 9, 3> stack;
    EXPECT_THROW(stack.peek(3), std::range_error);
    EXPECT_THROW(stack.push(3, 10), std::range_error);
    EXPECT_THROW(stack.pop(3), std::range_error);
    EXPECT_THROW(stack.pop(300), std::range_error);
}

TEST(CH3_1_THREE_IN_ONE_FIXED_STACK, EMPTY_INDEX_MAPPING) {
    FixedMultiStack<int, 9, 3> stack;
    stack.print();
    ASSERT_EQ(stack.getStackIndex(0), 0);
    ASSERT_EQ(stack.getStackIndex(1), 3);
    ASSERT_EQ(stack.getStackIndex(2), 6);
}

TEST(CH3_1_THREE_IN_ONE_FIXED_STACK, MULTISTACK_PUSH_PEEK) {
    FixedMultiStack<int, 9, 3> stack;
    stack.push(0, 10);
    stack.push(1, 20);
    stack.push(2, 30);
    stack.print();
    ASSERT_EQ(stack.peek(0), 10);
    ASSERT_EQ(stack.peek(1), 20);
    ASSERT_EQ(stack.peek(2), 30);
}

TEST(CH3_1_THREE_IN_ONE_FIXED_STACK, INDEX_MAPPING) {
    FixedMultiStack<int, 9, 3> stack;
    stack.push(0, 10);
    stack.push(0, 11);
    stack.push(1, 20);
    stack.push(1, 21);
    stack.push(2, 30);
    stack.push(2, 31);
    stack.print();
    ASSERT_EQ(stack.getStackIndex(0), 1);
    ASSERT_EQ(stack.getStackIndex(1), 4);
    ASSERT_EQ(stack.getStackIndex(2), 7);
}

TEST(CH3_1_THREE_IN_ONE_FIXED_STACK, MULTIPLE_PUSH) {
    FixedMultiStack<int, 9, 3> stack;
    stack.push(0, 10);
    stack.push(0, 11);
    stack.push(1, 20);
    stack.push(1, 21);
    stack.push(2, 30);
    stack.push(2, 31);
    stack.print();
    ASSERT_EQ(stack.peek(0), 11);
    ASSERT_EQ(stack.peek(1), 21);
    ASSERT_EQ(stack.peek(2), 31);
}

TEST(CH3_1_THREE_IN_ONE_FIXED_STACK, FULL_STACK) {
    FixedMultiStack<int, 9, 3> stack;
    stack.push(0, 10);
    stack.push(0, 11);
    stack.push(0, 12);
    stack.print();
    ASSERT_THROW(stack.push(0, 13), std::length_error);
    ASSERT_EQ(stack.peek(0), 12);
}

TEST(CH3_1_THREE_IN_ONE_FIXED_STACK, MULTIPLE_POP) {
    FixedMultiStack<int, 9, 3> stack;
    stack.push(0, 10);
    stack.push(0, 11);
    stack.push(1, 20);
    stack.push(1, 21);
    stack.push(2, 30);
    stack.push(2, 31);
    stack.print();
    ASSERT_EQ(stack.pop(0), 11);
    ASSERT_EQ(stack.pop(0), 10);
    ASSERT_EQ(stack.pop(1), 21);
    ASSERT_EQ(stack.pop(1), 20);
    ASSERT_EQ(stack.pop(2), 31);
    ASSERT_EQ(stack.pop(2), 30);
}