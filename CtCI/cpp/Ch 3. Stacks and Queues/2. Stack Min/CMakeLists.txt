enable_testing()

add_executable(
  ch3_2_stack_min
  "stack_min_test.cpp"
)

target_link_libraries(
  ch3_2_stack_min
  stacks_and_queues
  gtest_main
)

gtest_discover_tests(ch3_2_stack_min)