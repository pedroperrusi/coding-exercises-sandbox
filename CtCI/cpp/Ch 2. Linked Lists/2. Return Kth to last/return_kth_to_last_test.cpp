#include "return_kth_to_last.h"

#include <gtest/gtest.h>

using namespace std;
using namespace linked_lists;

TEST(CH2_2_RETURN_KTH_TO_LAST_TRIVIAL, SINGLE_ELEMENT_LIST) {
    LinkedList<int> list({0});

    list.print();
    int last = returnKthToLastTrivial<int>(list, 0);
    list.print();

    ASSERT_EQ(last, 0);
}

TEST(CH2_2_RETURN_KTH_TO_LAST_TRIVIAL, RETURN_LAST_ELEMENT) {
    LinkedList<int> list({0, 1, 2});
 
    list.print();
    int last = returnKthToLastTrivial<int>(list, 0);
    list.print();

    ASSERT_EQ(last, 2); 
}

TEST(CH2_2_RETURN_KTH_TO_LAST_TRIVIAL, RETURN_SECOND_TO_LAST_ELEMENT) {
    LinkedList<int> list({0, 1, 2});

    list.print();
    int last = returnKthToLastTrivial<int>(list, 1);
    list.print();

    ASSERT_EQ(last, 1); 
}

TEST(CH2_2_RETURN_KTH_TO_LAST_SINGLE_LOOP, SINGLE_ELEMENT_LIST) {
    LinkedList<int> list({0});

    list.print();
    int last = returnKthToLastSingleLoop<int>(list, 0);
    list.print();

    ASSERT_EQ(last, 0);
}

TEST(CH2_2_RETURN_KTH_TO_LAST_SINGLE_LOOP, RETURN_LAST_ELEMENT) {
    LinkedList<int> list({0, 1, 2});

    list.print();
    int last = returnKthToLastSingleLoop<int>(list, 0);
    list.print();

    ASSERT_EQ(last, 2); 
}

TEST(CH2_2_RETURN_KTH_TO_LAST_SINGLE_LOOP, RETURN_SECOND_TO_LAST_ELEMENT) {
    LinkedList<int> list({0, 1, 2});

    list.print(); 
    int last = returnKthToLastSingleLoop<int>(list, 1);
    list.print();

    ASSERT_EQ(last, 1);  
}


 