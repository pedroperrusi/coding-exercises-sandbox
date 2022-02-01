add_library(stacks_and_queues INTERFACE) 
target_include_directories(stacks_and_queues INTERFACE "./") 
enable_testing()
add_executable(
  ch3_stacks_and_queues_test
  "test/stack_test.cpp"
)
target_link_libraries(
  ch3_stacks_and_queues_test
  stacks_and_queues
  gtest_main
)
gtest_discover_tests(ch3_stacks_and_queues_test)