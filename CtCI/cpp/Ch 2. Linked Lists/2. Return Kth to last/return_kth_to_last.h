#include "linked_lists_unique.h"

using namespace linked_lists::unique;

/**
 * @brief Trivial solution when you already know the size of the linked_list
 * In our case, the size function is O(N), so we need to loop through the list once more to return kth element
 * Time Complexity O(N)
 * Space Complexity O(1)
 */
template <typename T>
T returnKthToLastTrivial(LinkedList<T>& list, size_t k) {
    return list.visit(list.size() - k - 1);
}

/**
 * @brief To solve it using a single loop, we use two pointers separated by a k offset
 * Time Complexity O(N)
 * Space Complexit O(1)
 * @tparam T 
 * @param list 
 * @param k 
 * @return T 
 */
template <typename T>
T returnKthToLastSingleLoop(LinkedList<T>& list, size_t k) {
    Node<T>* node_ptr = list.getRoot();
    Node<T>* look_ahead_ptr = node_ptr;
    // advance look ahead pointer by an offset of k
    for(size_t i = 0; i < k; i++) look_ahead_ptr = look_ahead_ptr->getNext();
    // Loop both pointers until look ahead finds the end
    while (look_ahead_ptr->getNext()) {
        node_ptr = node_ptr->getNext();
        look_ahead_ptr = look_ahead_ptr->getNext();
    }
    return node_ptr->visit();
}
