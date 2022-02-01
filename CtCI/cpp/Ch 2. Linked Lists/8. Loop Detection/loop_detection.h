#include <unordered_map>

#include "linked_lists_shared.h"

using namespace linked_lists::shared;

/**
 * @brief Slow runner and fast runner approach.
 * While slow advances with 1 step per iteration, fast advances 2.
 * Slow and fast should intercept in LOOP_SIZE - K, where K is the number of nodes before the loop
 * 
 * @param list 
 * @return NodePtr<int> 
 */
inline NodePtr<int> detectLoop(LinkedList<int>& list) {
    auto slow_ptr = list.getRoot();
    auto fast_ptr = slow_ptr;
    while (fast_ptr && fast_ptr->getNext()) {
        slow_ptr = slow_ptr->getNext();
        fast_ptr = fast_ptr->getNext()->getNext();
        if (slow_ptr == fast_ptr) break;
    }
    if (slow_ptr != fast_ptr) return nullptr;  // if there's no loop
    // now nodes should be K units before the loop starting node
    // to compute K, we restart slow_ptr to advance it with fast in the same pace.
    slow_ptr = list.getRoot();
    while (slow_ptr != fast_ptr) {
        slow_ptr = slow_ptr->getNext();
        fast_ptr = fast_ptr->getNext();
    }
    // after k interactions, return slow_ptr
    return slow_ptr;
}
