#include <iostream>
#include "LinkedList.h"
#include "BinaryHeap.h"
#include "Dijkstras_Algorithm.h"
#include "read_input.h"


int main() {

    std::vector<LinkedList> tree;
    int numberOfVertices;
    int numberOfEdges;
    std::vector<Vertex> setS;

    // Read the file and get a tree in the form of an adjacency list
    getPairsFromStdIn(tree, numberOfVertices, numberOfEdges);

    // Build the heap
    auto *heap = new BinaryHeap(numberOfVertices);
    heap->add(1, 0);  // Assume that vertex number 1 is the source vertex
    for(int i = 2; i <= numberOfVertices; i++) {
        heap->add(i, "inf");  // Set all other vertices to infinity
    }

    setS.resize(numberOfVertices);

    // Run Dijkstra's Algorithm
    dijkstras_algorithm(heap, &tree, setS);

    // Calculate Results
    auto paths = std::vector<std::vector<int>>(numberOfVertices);
    getPaths(paths, setS);


    // Print Results
    Vertex vertex;

    std::cout << "Vertex 1" << std::endl;
    std::cout << "Shortest Distance is 0" << std::endl;
    std::cout << "Shortest Path is 1 1" << std::endl << std::endl;

    for(int i = 1; i <= numberOfVertices - 1; i++) {

        vertex = setS.at(i);

        std::cout << "Vertex " << i + 1 << std::endl;
        std::cout << "Shortest Distance is " << vertex.getDistanceInt() << std::endl;

        std::cout << "Shortest Path is ";

        for(auto x = paths.at(i).crbegin() ; x!=paths.at(i).crend() ; x++){
            std::cout << *x << " ";
        }
        std::cout << std::endl << std::endl;

    }

    return 0;
}

