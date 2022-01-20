#include <string>
#include <vector>
#include <iostream>
#include <bitset>
#include <algorithm> // for sort() 

using namespace std;

namespace{

// Detects if str1 and str2 are one character away from one another.
// Acceptable operations to fix are replacement, insertion or removal.
// Time complexity O(N)
// Space complexity O(N)
bool oneAway(const string str1, const string str2) {
	int len_difference = str1.size() - str2.size();
	if (abs(len_difference) > 1) return false;
	
	// only one error allowed
	bool error_detected = false;

	// Replacement detection
	if (len_difference == 0) { 
		for (auto i = 0; i < str1.size(); i++) {
			if (str1[i] != str2[i]) {
				if (error_detected) return false;
				error_detected = true;
			}
		}
	} 
	// insertion or removal (1-shift away)
	else {
		size_t i = 0;
		size_t j = 0; 
		while (i < str1.size() && j < str2.size()) {
			if (str1[i] != str2[j]) {
				if (error_detected) return false;
				error_detected = true;
				// shift index of the longer string
				if (len_difference > 0) i++;
				else j++;
			}
			i++;
			j++;
		}
	}
	return true;
}

}