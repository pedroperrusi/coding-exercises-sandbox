#include "one_away.h"

#include <gtest/gtest.h>

#include <iostream>
#include <string>
#include <vector>

using namespace std;

TEST(CH1_ONE_AWAY, EMPTY_STRINGS) { EXPECT_TRUE(oneAway("", "")); }

TEST(CH1_ONE_AWAY, BIG_LENGTH_DIFFERENCE) {
    EXPECT_FALSE(oneAway("", "hello world!"));
    EXPECT_FALSE(oneAway("hello world!", ""));
    EXPECT_FALSE(oneAway("hello worl", "hello world!"));
}

TEST(CH1_ONE_AWAY, REPLACEMENT) {
    EXPECT_TRUE(oneAway("balloon", "yalloon"));
    EXPECT_TRUE(oneAway("balloon", "balloof"));
}

TEST(CH1_ONE_AWAY, INSERTION_REMOVAL) {
    EXPECT_TRUE(oneAway("balloon", "alloon"));
    EXPECT_TRUE(oneAway("balloon", "balloo"));
}