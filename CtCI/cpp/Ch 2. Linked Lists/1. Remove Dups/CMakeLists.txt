enable_testing()

add_executable(
  ch2_1_remove_dups_test
  "remove_dups_test.cpp"
)

target_link_libraries(
  ch2_1_remove_dups_test
  linked_lists
  gtest_main
)

gtest_discover_tests(ch2_1_remove_dups_test)