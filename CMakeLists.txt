cmake_minimum_required(VERSION 3.21)
project(Dijkstra2)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(Google_tests)

add_executable(Dijkstra2 main.cpp
        Dijkstra_lib/BinaryHeap.cpp Dijkstra_lib/BinaryHeap.h
        Dijkstra_lib/HeapMap.cpp Dijkstra_lib/HeapMap.h
        Dijkstra_lib/Vertex.cpp Dijkstra_lib/Vertex.h
        Dijkstra_lib/Weight.cpp Dijkstra_lib/Weight.h
        Dijkstra_lib/LinkedList.cpp Dijkstra_lib/LinkedList.h
        Dijkstra_lib/Node.cpp Dijkstra_lib/Node.h
        Dijkstra_lib/read_input.cpp Dijkstra_lib/read_input.h
        Dijkstra_lib/read_file.cpp Dijkstra_lib/read_file.h
        )

