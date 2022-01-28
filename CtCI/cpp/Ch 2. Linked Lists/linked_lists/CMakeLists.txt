add_library(linked_lists INTERFACE) 
target_include_directories(linked_lists INTERFACE "./") 
enable_testing()
add_executable(
  ch2_linked_lists_test
  "test/linked_lists_unique_test.cpp"
  "test/linked_lists_raw_test.cpp"
)
target_link_libraries(
  ch2_linked_lists_test
  linked_lists
  gtest_main
)
gtest_discover_tests(ch2_linked_lists_test)