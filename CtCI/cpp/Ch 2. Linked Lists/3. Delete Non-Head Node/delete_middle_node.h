#include "linked_lists.h"

using namespace linked_lists;

/**
 * @brief Trivial solution when you already know the size of the linked_list
 * In our case, the size function is O(N), so we need to loop through the list once more to return kth element
 * Time Complexity O(1)
 * Space Complexity O(1)
 */
template <typename T>
void deleteMiddleNode(Node<T>* node) {
        node->set(node->next->visit());
        node->next = std::move(node->next->next);
}
