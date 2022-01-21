#include "permutation.h"

#include <gtest/gtest.h>

#include <iostream>
#include <string>
#include <vector>

using namespace std;

TEST(CH1_PERMUTATION_Sorting, SINGLE_CHARACTER) {
    EXPECT_TRUE(isPermutationBySorting("a", "a"));
}

TEST(CH1_PERMUTATION_Sorting, TrivialCaseSensitive) {
    EXPECT_TRUE(isPermutationBySorting("aA", "Aa"));
    EXPECT_FALSE(isPermutationBySorting("aA", "Ab"));
}

TEST(CH1_PERMUTATION_Sorting, TwoExamples) {
    EXPECT_TRUE(isPermutationBySorting("arara", "arara"));
    EXPECT_TRUE(isPermutationBySorting("dog", "god"));
}

TEST(CH1_PERMUTATION_Counting, SINGLE_CHARACTER) {
    EXPECT_TRUE(isPermutationByCounting("a", "a"));
}

TEST(CH1_PERMUTATION_Counting, TrivialCaseSensitive) {
    EXPECT_TRUE(isPermutationByCounting("aA", "Aa"));
    EXPECT_FALSE(isPermutationByCounting("aA", "Ab"));
}

TEST(CH1_PERMUTATION_Counting, TwoExamples) {
    EXPECT_TRUE(isPermutationBySorting("arara", "arara"));
    EXPECT_TRUE(isPermutationBySorting("dog", "god"));
}