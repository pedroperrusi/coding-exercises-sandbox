enable_testing()

add_executable(
  ch2_2_return_kth_to_last
  "return_kth_to_last_test.cpp"
)

target_link_libraries(
  ch2_2_return_kth_to_last
  linked_lists
  gtest_main
)

gtest_discover_tests(ch2_2_return_kth_to_last)