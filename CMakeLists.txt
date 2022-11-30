cmake_minimum_required(VERSION 3.21)
project(Dijkstra2)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(Google_tests)

add_executable(Dijkstra main.cpp
        BinaryHeap.cpp BinaryHeap.h
        HeapMap.cpp HeapMap.h
        Vertex.cpp Vertex.h
        Weight.cpp Weight.h
        LinkedList.cpp LinkedList.h
        Node.cpp Node.h
        read_input.cpp read_input.h
        Dijkstras_Algorithm.cpp Dijkstras_Algorithm.h
        )

