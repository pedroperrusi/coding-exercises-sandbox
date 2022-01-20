enable_testing()

add_executable(
  ch1_5_one_away_test
  "one_away_test.cpp"
)

target_link_libraries(
  ch1_5_one_away_test
  gtest_main
)

gtest_discover_tests(ch1_5_one_away_test)