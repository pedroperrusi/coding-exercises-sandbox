#include <gtest/gtest.h>

#include "palindrome_permutation.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;


TEST(CH1_PALINDROME_PERMUTATION, NONE_CHARACTER) {
	EXPECT_FALSE(isPalindromePermutation(""));
}

TEST(CH1_PALINDROME_PERMUTATION, SINGLE_CHARACTER) {
	EXPECT_TRUE(isPalindromePermutation("a"));
}

TEST(CH1_PALINDROME_PERMUTATION, PALINDROME) {
	EXPECT_TRUE(isPalindromePermutation("aa"));
	EXPECT_TRUE(isPalindromePermutation("abba"));
	EXPECT_TRUE(isPalindromePermutation("wow"));
	EXPECT_TRUE(isPalindromePermutation("arara"));
}

TEST(CH1_PALINDROME_PERMUTATION, NOT_PALINDROME) {
	EXPECT_FALSE(isPalindromePermutation("abcd"));
	EXPECT_FALSE(isPalindromePermutation("qwerty"));
}

TEST(CH1_PALINDROME_PERMUTATION, getCharEncoding) {
	EXPECT_EQ(getCharEncoding('a'), 0);
	EXPECT_EQ(getCharEncoding('z'), 25);
	EXPECT_EQ(getCharEncoding(' '), -1);
	EXPECT_EQ(getCharEncoding('&'), -1);
}

TEST(CH1_PALINDROME_PERMUTATION, getCharEncodingNotLetter) {
	EXPECT_EQ(getCharEncoding(' '), -1);
	EXPECT_EQ(getCharEncoding('&'), -1);
}

TEST(CH1_PALINDROME_PERMUTATION, getCharEncodingCaseSensitive) {
	EXPECT_EQ(getCharEncoding('A'), getCharEncoding('a'));
	EXPECT_EQ(getCharEncoding('Z'), getCharEncoding('z'));
}

TEST(CH1_PALINDROME_PERMUTATION, PALINDROME_WITH_SYMBOLS_AND_SPACES) {
	EXPECT_TRUE(isPalindromePermutation("Tact Coa"));
	EXPECT_TRUE(isPalindromePermutation("T  ^$& a c t C o a *** "));
}