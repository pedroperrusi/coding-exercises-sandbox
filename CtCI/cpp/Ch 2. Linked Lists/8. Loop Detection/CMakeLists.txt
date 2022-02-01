enable_testing()

add_executable(
  ch2_8_loop_detection_test
  "loop_detection_test.cpp"
)

target_link_libraries(
  ch2_8_loop_detection_test
  linked_lists
  gtest_main
)

gtest_discover_tests(ch2_8_loop_detection_test)