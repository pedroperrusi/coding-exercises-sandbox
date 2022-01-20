#include <string>
#include <vector>
#include <iostream>
#include <bitset>
#include <algorithm> // for sort() 

using namespace std;

namespace{

// Encode a a-z character in a integer value ranging from 0 to 25
// Not letter characters are assigned to -1
int getCharEncoding(const char c) {
	char lc = tolower(c);
	if (lc >= 'a' && lc <= 'z') return lc - 'a';
	return -1;
}

// Testing if a string is a palindrome permutation implies every letter is repeated an even nb of times, with the exception of the middle letter.
// We can use a bitset to count odd occurrence of letters in the string.
// If there's more than a bit activated after counting, it means the word is not a palindrome permutation.
// Here we assume our character set is defined by letters from a-z and not case sensitive.
// Time Complexity O(N)
// Space Complexity O(C), where C is the size of the character set (26 from a to z)
bool isPalindromePermutation(string str) {
	if (str.empty()) return false;
	bitset<28> odd_occurrences(0); // 1 if odd occurrence of one of the letters, 0 otherwise
	for (const auto ch : str) {
		int code = getCharEncoding(ch);
		odd_occurrences.flip(code);
	}
	// check for any 1 bit still on the bitset
	// only one is allowed for a palindrome permutation
	if (odd_occurrences.count() <= 1) return true;
	// otherwise the word is no palindrome permutation
	return false;
}

}