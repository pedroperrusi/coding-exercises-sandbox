#include "stack_min.h"

#include <gtest/gtest.h>

#include <stdexcept>

using namespace stack;

TEST(CH3_2_MIN_STACK, PUSH_MIN) {
    StackMin<int> stack;
    stack.push(5);
    stack.push(6);
    ASSERT_EQ(stack.getMin(), 5);
    stack.push(3);
    ASSERT_EQ(stack.getMin(), 3);
}

TEST(CH3_2_MIN_STACK, EMPTY) {
    StackMin<int> stack;
    ASSERT_THROW(stack.getMin(), std::length_error);
}

TEST(CH3_2_MIN_STACK, POP_MIN) { 
    StackMin<int> stack;
    stack.push(5);
    stack.push(6);
    stack.push(3);
    ASSERT_EQ(stack.getMin(), 3);
    stack.pop();
    ASSERT_EQ(stack.getMin(), 5);
} 