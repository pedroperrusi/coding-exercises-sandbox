#include "linked_lists.h"
#include <iostream>
#include <unordered_map>


using namespace std;
using Node = linked_lists::Node<int>;

namespace{

// Remove duplicates using a temporary hash table to map unique values encountered
// Time complexity O(N)
// Space complexity O(N) 
void removeDups(Node& root){ 
    unordered_map<int, bool> occurrences;  // boolean hash-table
    Node* previous;
    for (Node* n_ptr = &root; n_ptr != nullptr; n_ptr = n_ptr->next) {
        int key = n_ptr->visit();
        if (!occurrences.count(key)) {
            occurrences[key] = true;
            previous = n_ptr;
        } else {
            previous->next = n_ptr->next;
            n_ptr->next = nullptr;
            delete n_ptr;
            n_ptr = previous;
        }
    }
 }

// Remove duplicates using with two concurrent pointers
// Time complexity O(N)
// Space complexity O(1) 
 void removeDupsNoBuffer(Node& root){ 
    Node* slow_ptr = &root;
    while (slow_ptr != nullptr) {
        int value = slow_ptr->visit();
        Node* runner_ptr = slow_ptr;
        // remove any future occurrences
        while (runner_ptr != nullptr) {
            Node* next_ptr = runner_ptr->next;
            if (value == next_ptr->visit()) {
                runner_ptr->next = next_ptr->next;
                // detach and delete it
                next_ptr->next = nullptr;
                delete next_ptr;
            }
            runner_ptr = runner_ptr->next;
        }
        slow_ptr = slow_ptr->next;
    }
 }

}