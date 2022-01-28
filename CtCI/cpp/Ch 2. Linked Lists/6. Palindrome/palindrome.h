#include <unordered_map>

#include "linked_lists_unique.h"

using namespace linked_lists::unique;

/**
 * @brief Check if its palindrome by inversing the list and checking element by element
 * 
 * Time Complexity O(N) as we go through the list N + N/2 times
 * Space Complexity O(N) as we need a copy of the entire list
 */
bool isPalindrome(LinkedList<char>& list) {
    // create a new list with the inverse of the elements of list
    LinkedList<char> reversed;
    size_t size = 0;  // avoid another loop to find list size
    for (auto ptr = list.getRoot(); ptr; ptr = ptr->getNext()) {
        reversed.push_front(ptr->visit());
        size++;
    }
    // Compare both lists until first half of the list
    auto forward_ptr = list.getRoot();
    auto reversed_ptr = reversed.getRoot();
    size_t half = (size_t)(size / 2);  // if impair, middle element doesn't matter
    for (size_t i = 0; i < half; i++) {
        if (forward_ptr->visit() != reversed_ptr->visit()) return false;
        forward_ptr = forward_ptr->getNext();
        reversed_ptr = reversed_ptr->getNext();
    }
    return true;
}
