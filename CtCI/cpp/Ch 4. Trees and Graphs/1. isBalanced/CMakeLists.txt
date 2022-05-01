enable_testing()

add_executable(
  ch4_1_is_balanced
  "isBalanced_test.cpp"
)

target_link_libraries(
  ch4_1_is_balanced
  trees_and_graphs
  gtest_main
)

gtest_discover_tests(ch4_1_is_balanced)