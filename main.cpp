#include <iostream>
#include "./Dijkstra_lib/LinkedList.h"
#include "./Dijkstra_lib/BinaryHeap.h"
#include "./Dijkstra_lib/read_file.h"
#include "./Dijkstra_lib/adjacency_list.h"


std::vector<int> dijkstras_algorithm(BinaryHeap * heap, std::vector<LinkedList> * tree, std::vector<int> & setS) {

    Vertex dU;
    Vertex dV;
    bool found = false;

    // Outer while loop
    while(!heap->isEmpty()) {  // O(V + E) for the two while loops
        dU = heap->heap_extract_min();  // O(1)
        while(!tree->at(dU.vertex - 1).isEmpty()) {  // for each vertex incident to dU. O(1) for the computation
            dV = tree->at(dU.vertex - 1).pop();  // O(1)
            if(heap->inQueue(dV) && heap->heapList.at(heap->getLocation(dV.vertex)).distance > dU.distance + dV.distance) {  // O(1)
                heap->heapDecreaseDistance(&dV, dU.distance + dV.distance);  // O(log(V))
            }
        }
        setS.emplace_back(dU.vertex);  // O(1)
    }

    return setS;
}

int main() {

    std::vector<LinkedList> tree;
    int numberOfVertices;
    int numberOfEdges;
    std::vector<int> setS;

    // Read the file and get a tree in the form of an adjacency list
    readFile("Dijkstra_lib/input.txt", tree, numberOfVertices, numberOfEdges);

    // Build the heap
    auto *heap = new BinaryHeap(numberOfVertices);
    heap->add(1, 0);  // Assume that vertex number 1 is the source vertex
    for(int i = 2; i <= numberOfVertices; i++) {
        heap->add(i, "inf");  // Set all other vertices to infinity
    }

    // TODO: make algorithm accept decimals
    // Run Dijkstra's Algorithm
    dijkstras_algorithm(heap, &tree, setS);

    // Print and Calculate Results
    for(int i = 1; i < numberOfVertices; i++) {

        std::cout << "Vertex " << i << std::endl;
        std::cout << "Shortest Distance is "
    }


    return 0;
}

