#include "palindrome.h"

#include <gtest/gtest.h>

using namespace std;
using namespace linked_lists::unique;

TEST(CH2_6_PALINDROME, TWO_LETTERS) {
    LinkedList<char> list1({'A', 'A'});
    LinkedList<char> list2({'A', 'B'});
    
    ASSERT_TRUE(isPalindrome(list1));
    ASSERT_FALSE(isPalindrome(list2));
}

TEST(CH2_6_PALINDROME, IMPAIR_LETTERS) {
    LinkedList<char> list1({'A', 'C', 'A'});
    LinkedList<char> list2({'A', 'B', 'C', 'B', 'D'});
    
    ASSERT_TRUE(isPalindrome(list1));
    ASSERT_FALSE(isPalindrome(list2));
}

