enable_testing()

add_executable(
  ch2_3_delete_middle_node_test
  "delete_middle_node_test.cpp"
)

target_link_libraries(
  ch2_3_delete_middle_node_test
  linked_lists
  gtest_main
)

gtest_discover_tests(ch2_3_delete_middle_node_test)