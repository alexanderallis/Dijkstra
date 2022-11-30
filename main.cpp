#include <iostream>
#include "./Dijkstra_lib/LinkedList.h"
#include "./Dijkstra_lib/BinaryHeap.h"
#include "./Dijkstra_lib/read_file.h"
#include "./Dijkstra_lib/adjacency_list.h"


std::vector<Vertex> dijkstras_algorithm(BinaryHeap * heap, std::vector<LinkedList> * tree, std::vector<Vertex> & setS) {

    Vertex dU;
    Vertex dV;

    // Outer while loop
    while(!heap->isEmpty()) {  // O(V + E) for the two while loops
        dU = heap->heap_extract_min();  // O(1)
        while(!tree->at(dU.getVertex() - 1).isEmpty()) {  // for each vertex incident to dU. O(1) for the computation
            dV = tree->at(dU.getVertex() - 1).pop();  // O(1)
            if(heap->inQueue(dV) && heap->heapList.at(heap->getLocation(dV.getVertex())).getWeight() > dU.getWeight() + dV.getWeight()) {  // O(1)
                heap->heapDecreaseDistance(&dV, dU.getWeight() + dV.getWeight());  // O(log(V))
                heap->heapList.at(heap->getLocation(dV)).setPrecedingVertex(dU.getVertex());  // Set preceding vertex
            }
        }
        setS.at(dU.getVertex() - 1) = dU;  // O(1)
    }

    return setS;
}

int main() {

    std::vector<LinkedList> tree;
    int numberOfVertices;
    int numberOfEdges;
    std::vector<Vertex> setS;

    // Read the file and get a tree in the form of an adjacency list
    readFile("Dijkstra_lib/input.txt", tree, numberOfVertices, numberOfEdges);

    // Build the heap
    auto *heap = new BinaryHeap(numberOfVertices);
    heap->add(1, 0);  // Assume that vertex number 1 is the source vertex
    for(int i = 2; i <= numberOfVertices; i++) {
        heap->add(i, "inf");  // Set all other vertices to infinity
    }

    setS.resize(numberOfVertices);

    // TODO: make algorithm accept decimals
    // Run Dijkstra's Algorithm
    dijkstras_algorithm(heap, &tree, setS);

    // Calculate Results
    auto paths = std::vector<std::vector<int>>(numberOfVertices);
    Vertex v;
    int pathIndex;

    for(int i = 1; i < paths.size(); i++) {
        pathIndex = setS.at(i).getVertex() - 1;
        v = setS.at(i);
        while(v.getVertex() != 1) {
            paths.at(pathIndex).push_back(v.getVertex());
            v = setS.at(v.getPrecedingVertex() - 1);
            if(v.getVertex() == 1) {
                paths.at(pathIndex).push_back(1);
            }
        }
    }

    // Print and Calculate Results
    Vertex vertex;
    int previousVertex;

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

