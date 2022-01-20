enable_testing()

add_executable(
  ch1_4_palindrome_permutation_test
  "palindrome_permutation_test.cpp"
)

target_link_libraries(
  ch1_4_palindrome_permutation_test
  gtest_main
)

gtest_discover_tests(ch1_4_palindrome_permutation_test)