#include "linked_lists.h"
#include <iostream>
#include <unordered_map>


using namespace std;
using Node = linked_lists::Node<int>;

namespace{

void removeDups(Node* list_ptr){ 
    unordered_map<int, bool> occurrences;  // boolean hash-table
    Node* previous;
    for (Node* n_ptr = list_ptr; n_ptr != nullptr; n_ptr = n_ptr->next) {
        int key = n_ptr->visit();
        if (!occurrences.count(key)) {
            occurrences[key] = true;
            previous = n_ptr;
        } else {
            previous->next = n_ptr->next;
            n_ptr = previous;
        }
    }
 }

}