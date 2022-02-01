enable_testing()

add_executable(
  ch2_5_intersection_test
  "intersection_test.cpp"
)

target_link_libraries(
  ch2_5_intersection_test
  linked_lists
  gtest_main
)

gtest_discover_tests(ch2_5_intersection_test)