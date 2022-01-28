#include <unordered_map>

#include "linked_lists_unique.h"

using namespace linked_lists::unique;

void sumLists(LinkedList<int>& list1, LinkedList<int>& list2,
              LinkedList<int>& output) {
    output.clean();
    auto node_1_ptr = list1.getRoot();
    auto node_2_ptr = list2.getRoot();
    int carry = 0;
    while (node_1_ptr || node_2_ptr) {
        int value = carry;
        if (node_1_ptr) value += node_1_ptr->visit();
        if (node_2_ptr) value += node_2_ptr->visit();
        if (value >= 10) {
            carry = 1;
            value -= 10;
        } else {
            carry = 0;
        }
        output.push_back(value);
        if (node_1_ptr) node_1_ptr = node_1_ptr->getNext();
        if (node_2_ptr) node_2_ptr = node_2_ptr->getNext();
    }
    if (carry) output.push_back(carry);
}
