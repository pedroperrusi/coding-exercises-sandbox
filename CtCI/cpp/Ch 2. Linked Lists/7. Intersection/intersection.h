#include <unordered_map>

#include "linked_lists_shared.h"

using namespace linked_lists::shared;

inline NodePtr<int> findIntersection(LinkedList<int>& list1,
                                     LinkedList<int>& list2) {
    // Lists that intercept must have the same number of tail nodes after interception
    // So the length offset between lists must come from different nodes before the intersection
    auto node1_ptr = list1.getRoot();
    auto node2_ptr = list2.getRoot();
    int offset = list1.size() - list2.size();
    if (offset > 0) {  // if list 1 is bigger, advance it of offset nodes
        for (int i = 0; i < offset; i++) {
            node1_ptr = node1_ptr->getNext();
        }
    } else if (offset < 0) {
        for (int i = 0; i < std::abs(offset); i++) {
            node2_ptr = node2_ptr->getNext();
        }
    }
    // now, sublists should be the same size
    // go through each element checking whether or not they intercept
    while (node1_ptr && node2_ptr) {
        if (node1_ptr == node2_ptr) return node1_ptr;
        node1_ptr = node1_ptr->getNext();
        node2_ptr = node2_ptr->getNext();
    }
    return nullptr;
}
