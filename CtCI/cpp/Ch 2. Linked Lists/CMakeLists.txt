# Subdirectory for chapter 2 exercises
add_library(linked_lists INTERFACE) 
target_include_directories(linked_lists INTERFACE "common/") 
enable_testing()
add_executable(
  ch2_linked_lists_test
  "common/linked_lists_test.cpp"
)
target_link_libraries(
  ch2_linked_lists_test
  linked_lists
  gtest_main
)
gtest_discover_tests(ch2_linked_lists_test)

add_subdirectory("1. Remove Dups")
add_subdirectory("2. Return Kth to last")
add_subdirectory("3. Delete Non-Head Node")
add_subdirectory("4. Paritition")