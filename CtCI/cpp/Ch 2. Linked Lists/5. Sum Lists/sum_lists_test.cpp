#include "sum_lists.h"

#include <gtest/gtest.h>

using namespace std;
using namespace linked_lists;

TEST(CH2_5_SUM_LISTS, SINGLE_DIGIT) {
    LinkedList<int> list1({1});
    LinkedList<int> list2({5});
    LinkedList<int> output;
    
    list1.print();
    std::cout << "+" << std::endl;
    list2.print();
    sumLists(list1, list2, output);
    std::cout << "=" << std::endl;
    output.print();
    
    ASSERT_EQ(output.size(), 1);
    ASSERT_EQ(output.visit(0), 6);
}

TEST(CH2_5_SUM_LISTS, OVERFLOW_DIGIT) {
    LinkedList<int> list1({9});
    LinkedList<int> list2({1});
    LinkedList<int> output;
    
    list1.print();
    std::cout << "+" << std::endl;
    list2.print();
    sumLists(list1, list2, output);
    std::cout << "=" << std::endl;
    output.print();

    ASSERT_EQ(output.size(), 2);
    ASSERT_EQ(output.visit(0), 0);
    ASSERT_EQ(output.visit(1), 1);
}

TEST(CH2_5_SUM_LISTS, TWO_DIGITS) {
    LinkedList<int> list1({5, 1});
    LinkedList<int> list2({2, 2});
    LinkedList<int> output;
    
    list1.print();
    std::cout << "+" << std::endl;
    list2.print();
    sumLists(list1, list2, output);
    std::cout << "=" << std::endl;
    output.print();

    ASSERT_EQ(output.size(), 2);
    ASSERT_EQ(output.visit(0), 7);
    ASSERT_EQ(output.visit(1), 3);
}

TEST(CH2_5_SUM_LISTS, TWO_DIGITS_OVERFLOW) {
    LinkedList<int> list1({5, 1});
    LinkedList<int> list2({5, 8});
    LinkedList<int> output;
    
    list1.print();
    std::cout << "+" << std::endl;
    list2.print();
    sumLists(list1, list2, output);
    std::cout << "=" << std::endl;
    output.print();

    ASSERT_EQ(output.size(), 3);
    ASSERT_EQ(output.visit(0), 0);
    ASSERT_EQ(output.visit(1), 0);
    ASSERT_EQ(output.visit(2), 1);
}

TEST(CH2_5_SUM_LISTS, DIFFERENT_INPUT_SIZES) {
    LinkedList<int> list1({5});
    LinkedList<int> list2({5, 8});
    LinkedList<int> output;
    
    list1.print();
    std::cout << "+" << std::endl;
    list2.print();
    sumLists(list1, list2, output);
    std::cout << "=" << std::endl;
    output.print();

    ASSERT_EQ(output.size(), 2);
    ASSERT_EQ(output.visit(0), 0);
    ASSERT_EQ(output.visit(1), 9);
}