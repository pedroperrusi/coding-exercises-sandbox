#include "1. Is_unique.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> words = {"abcde", "hello", "apple", "kite", "padle"};
    for (auto word : words) {
        cout << word << string(": ") << boolalpha << isUniqueChars(word)
             << endl;
    }
    cout << endl << "Using no Data Structures" << endl;
    for (auto word : words) {
        cout << word << string(": ") << boolalpha << isUniqueChars_noDS(word)
             << endl;
    }
    return 0;
}
