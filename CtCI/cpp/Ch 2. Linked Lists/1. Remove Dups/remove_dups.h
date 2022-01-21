#include "linked_lists.h"
#include <iostream>
#include <unordered_map>


using namespace std;
using LinkedList = linked_lists::LinkedList<int>;
using Node = linked_lists::Node<int>;

namespace{

// Remove duplicates using a temporary hash table to map unique values encountered
// Time complexity O(N)
// Space complexity O(N) 
void removeDups(LinkedList& list){ 
    unordered_map<int, bool> occurrences;  // boolean hash-table
    Node* previous;
    for (Node* n_ptr = list.getRoot(); n_ptr != nullptr; n_ptr = n_ptr->getNext()) {
        int key = n_ptr->visit();
        if (!occurrences.count(key)) {
            occurrences[key] = true;
            previous = n_ptr;
        } else {
            previous->next = std::move(n_ptr->next);
            n_ptr = previous;
        }
    }
 }

// Remove duplicates using with two concurrent pointers
// Time complexity O(N)
// Space complexity O(1) 
 void removeDupsNoBuffer(LinkedList& list){ 
    Node* slow_ptr = list.getRoot();
    while (slow_ptr != nullptr) {
        int value = slow_ptr->visit();
        Node* runner_ptr = slow_ptr;
        // remove any future occurrences
        while (runner_ptr != nullptr) {
            Node* next_ptr = runner_ptr->getNext();
            if (value == next_ptr->visit()) {
                runner_ptr->next = std::move(next_ptr->next);
            }
            runner_ptr = runner_ptr->getNext();
        }
        slow_ptr = slow_ptr->getNext();
    }
 }

}