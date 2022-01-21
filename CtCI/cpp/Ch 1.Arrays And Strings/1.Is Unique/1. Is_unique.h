#include <algorithm>  // for sort()
#include <bitset>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace {

// Assuming a fixed character set of 128 ASCII values:
// - Time Complexity O(min(c, n))
// - Space complexity O(c)
// where n is the size of the string and c is the size of the character set (128 in this case)
bool isUniqueChars(const string &str) {
    // Assuming our character set to be ASCII, the string may be as big as its char_set
    if (str.length() > 128) {
        return false;
    }
    // Reduce space usage by a factor of 8 using bitvector.
    // Each boolean otherwise occupies a size of 8 bits.
    bitset<128> bits(0);
    for (auto ch : str) {
        int val = tolower(ch);
        if (bits.test(val)) {
            return false;  // if character was prev. set, str is not unique
        }
        bits.set(val);
    }
    return true;
}

// Without using data-structures we can resort to sorting algorithms to avoid nested loops (O(n^2))
// Time Complexity bounded by sort: O(nlog(n))
// Space complexity bounded by sort: (?)
bool isUniqueChars_noDS(string str) {
    sort(str.begin(), str.end(), [](char a, char b) {
        return tolower(a) < tolower(b);
    });  // O(nlogn) sort from <algorithm>

    // compare two consecutive elements
    for (size_t i = 0; i < str.size() - 1; i++) {
        if (tolower(str[i]) == tolower(str[i + 1])) {
            return false;
        }
    }
    // if none matches, it is unique
    return true;
}
}  // namespace