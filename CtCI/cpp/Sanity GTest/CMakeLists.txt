enable_testing()

add_executable(
  sanity_test
  "sanity_test.cpp"
)

target_link_libraries(
  sanity_test
  gtest_main
)

gtest_discover_tests(sanity_test)