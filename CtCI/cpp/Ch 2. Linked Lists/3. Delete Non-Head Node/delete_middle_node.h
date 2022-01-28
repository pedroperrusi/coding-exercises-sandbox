#include "linked_lists_unique.h"

using namespace linked_lists::unique;

/**
 * @brief Deleting a node in the middle means its note the list head or tail node.
 * It is trivial to delete it, since it always has a following neighboor.
 * First copy its value and neighboor information, and then delete the neighboor.
 * As we're using smart pointers for the next pointer it is pretty straightforward to avoid memory leaks
 * Time Complexity O(1)
 * Space Complexity O(1)
 */
template <typename T>
void deleteMiddleNode(Node<T>* node) {
        node->set(node->next->visit());
        node->next = std::move(node->next->next);
}
