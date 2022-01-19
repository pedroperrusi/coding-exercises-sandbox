enable_testing()

add_executable(
  ch1_2_permutation_test
  "permutation_test.cpp"
)

target_link_libraries(
  ch1_2_permutation_test
  gtest_main
)

gtest_discover_tests(ch1_2_permutation_test)