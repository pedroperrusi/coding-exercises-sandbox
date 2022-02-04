#include "stack_of_plates.h"

#include <gtest/gtest.h>

#include <stdexcept>

using namespace stack;

TEST(CH3_2_MIN_STACK, SINGLE_PUSH_PEEK) {
    SetOfStacks<int, 3> set_of_stacks;
    set_of_stacks.push(0);
    ASSERT_EQ(set_of_stacks.peek(), 0);
}

TEST(CH3_2_MIN_STACK, SINGLE_PUSH_POP) {
    SetOfStacks<int, 3> set_of_stacks;
    set_of_stacks.push(0);
    ASSERT_EQ(set_of_stacks.pop(), 0);
}
   
TEST(CH3_2_MIN_STACK, STACK_OVERFLOW) {
    SetOfStacks<int, 3> set_of_stacks;
    set_of_stacks.push(0);
    set_of_stacks.push(1);
    set_of_stacks.push(2);
    set_of_stacks.push(3);
    ASSERT_EQ(set_of_stacks.pop(), 3);
    ASSERT_EQ(set_of_stacks.pop(), 2);
    ASSERT_EQ(set_of_stacks.pop(), 1);
    ASSERT_EQ(set_of_stacks.pop(), 0);
}