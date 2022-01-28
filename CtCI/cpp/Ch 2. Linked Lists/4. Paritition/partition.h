#include <unordered_map>

#include "linked_lists_unique.h"

using namespace linked_lists::unique;

/**
 * @brief Creates 2 sublists and add elements along the way
 * 
 * Time Complexity O(N^2) as N times calling push_back
 * Space Complexity O(N)
 */
template <typename T>
void partitionWithSublists(LinkedList<T>& list, T pivot) {
    LinkedList<T> left_list, right_list;
    auto node_ptr = list.getRoot();
    while (node_ptr) {
        T value = node_ptr->visit();
        if (value < pivot) {
            left_list.push_back(value);
        } else {
            right_list.push_back(value);
        }
        node_ptr = node_ptr->getNext();
    }
    // join lists into original one
    list.clean();
    // if left list is empty, only copy right
    if (left_list.root) {
        list = std::move(left_list);
        // iterate until the end to get tail node
        Node<T>* node = list.getRoot();
        while (node->next) node = node->getNext();
        node->next = std::move(right_list.root);
    } else { // if left list is empty, simply copy right list
        list = std::move(right_list);
    }
    // destructors for left_list and right_list called to cleanup
}
