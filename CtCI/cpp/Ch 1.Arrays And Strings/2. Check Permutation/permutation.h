#include <string>
#include <vector>
#include <iostream>
#include <bitset>
#include <algorithm> // for sort() 

using namespace std;

namespace{

// Without using data-structures we can resort to sorting algorithms to avoid nested loops (O(n^2))
// Time Complexity bounded by sort: O(nlog(n))
// Space complexity bounded by sort: (?)
bool isPermutationBySorting(string str1, string str2) {
	if (str1.size() != str2.size()) return false;
	sort(str1.begin(), str1.end());
	sort(str2.begin(), str2.end());
	return str1 == str2;
}

// Without using data-structures we can resort to sorting algorithms to avoid nested loops (O(n^2))
// Time Complexity bounded by sort: O(n)
// Space complexity bounded by sort: O(n)
bool isPermutationByCounting(string str1, string str2) {
	if (str1.size() != str2.size()) return false;
	vector<int> letter_count(128);  // assuming an ASCII2 character set
	for (char c1 : str1) {
		// for each letter in str1 add one to the array
		letter_count[c1]++;
	}
	for (char c2 : str2) {
		// for each letter in str2 subtract one to the array
		letter_count[c2]--;
		if (letter_count[c2] < 0) return false;
	}
	return true;
}

}