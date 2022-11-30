# 'Google_test' is the subproject name
project(Google_tests)

# 'lib' is the folder with Google Test sources
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# 'Google_Tests_run' is the target name
# 'test1.cpp tests2.cpp' are source files with tests
add_executable(Google_Tests_run BinaryHeapTests.cpp)

add_library(Dijkstra_lib ../Dijkstra_lib/BinaryHeap.cpp ../Dijkstra_lib/HeapMap.cpp ../Dijkstra_lib/Vertex.cpp ../Dijkstra_lib/Weight.cpp ../Dijkstra_lib/Dijkstras_Algorithm.cpp ../Dijkstra_lib/Dijkstras_Algorithm.h)

target_link_libraries(Google_Tests_run Dijkstra_lib)

target_link_libraries(Google_Tests_run gtest gtest_main)