enable_testing()

add_executable(
  ch1_1_is_unique
  "1. Is_unique.cpp"
)

add_executable(
  ch1_1_is_unique_test
  "1. Is_unique_test.cpp"
)

target_link_libraries(
  ch1_1_is_unique_test
  gtest_main
)

gtest_discover_tests(ch1_1_is_unique_test)