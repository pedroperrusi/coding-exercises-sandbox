enable_testing()

add_executable(
  ch3_1_three_in_one_test
  "fixed_multi_stack_test.cpp"
)

target_link_libraries(
  ch3_1_three_in_one_test
  stacks_and_queues
  gtest_main
)

gtest_discover_tests(ch3_1_three_in_one_test)