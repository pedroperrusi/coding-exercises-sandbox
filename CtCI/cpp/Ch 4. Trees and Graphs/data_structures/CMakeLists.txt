add_library(trees_and_graphs INTERFACE) 
target_include_directories(trees_and_graphs INTERFACE "./") 
enable_testing()
add_executable(
  ch4_trees_and_graphs_test
  "test/binary_tree_test.cpp"
)
target_link_libraries(
  ch4_trees_and_graphs_test
  trees_and_graphs
  gtest_main
)
gtest_discover_tests(ch4_trees_and_graphs_test)