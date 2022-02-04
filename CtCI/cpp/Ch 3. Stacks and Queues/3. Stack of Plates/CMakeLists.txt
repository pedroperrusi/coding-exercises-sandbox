enable_testing()

add_executable(
  ch3_3_stack_of_plates
  "stack_of_plates_test.cpp"
)

target_link_libraries(
  ch3_3_stack_of_plates
  stacks_and_queues
  gtest_main
)

gtest_discover_tests(ch3_3_stack_of_plates)