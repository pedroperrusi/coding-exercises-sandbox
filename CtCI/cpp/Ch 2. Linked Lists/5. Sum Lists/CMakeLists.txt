enable_testing()

add_executable(
  ch2_5_sum_lists_test
  "sum_lists_test.cpp"
)

target_link_libraries(
  ch2_5_sum_lists_test
  linked_lists
  gtest_main
)

gtest_discover_tests(ch2_5_sum_lists_test)