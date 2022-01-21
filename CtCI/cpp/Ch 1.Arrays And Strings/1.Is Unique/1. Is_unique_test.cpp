#include <gtest/gtest.h>

#include "1. Is_unique.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

TEST(CH1_IS_UNIQUE, TRIVIAL_TRUE) {
	EXPECT_TRUE(isUniqueChars("a"));
}

TEST(CH1_IS_UNIQUE, TRIVIAL_FALSE) {
	EXPECT_FALSE(isUniqueChars("aa"));
}

TEST(CH1_IS_UNIQUE, NOT_CASE_SENSITIVE) {
	EXPECT_FALSE(isUniqueChars("aA"));
}

TEST(CH1_IS_UNIQUE, MIXED_TESTING) {
	vector<string> words = {"abcde", "hello", "apple", "kite", "padle"};
	vector<bool> expects = {true, false, false, true, true};
    for (size_t i = 0; i < words.size(); i++)
    {
        EXPECT_EQ(expects[i], isUniqueChars(words[i]));
    }
}

TEST(CH1_IS_UNIQUE_noDS, TRIVIAL_TRUE) {
	EXPECT_TRUE(isUniqueChars_noDS("a"));
}

TEST(CH1_IS_UNIQUE_noDS, TRIVIAL_FALSE) {
	EXPECT_FALSE(isUniqueChars_noDS("aa"));
}

TEST(CH1_IS_UNIQUE_noDS, NOT_CASE_SENSITIVE) {
	EXPECT_FALSE(isUniqueChars_noDS("aA"));
}

TEST(CH1_IS_UNIQUE_noDS, MIXED_TESTING) {
	vector<string> words = {"abcde", "hello", "apple", "kite", "padle"};
	vector<bool> expects = {true, false, false, true, true};
    for (size_t i = 0; i < words.size(); i++)
    {
        EXPECT_EQ(expects[i], isUniqueChars_noDS(words[i]));
    }
}
