//
// Created by Alexander Allis on 11/29/22.
//

#include <vector>
#include "Vertex.h"
#include "BinaryHeap.h"
#include "LinkedList.h"

/*
 * Implements Dijkstra's Algorithm.
 * Args:
 *  BinaryHeap
 *  Vector of Linked Lists (Adjacency Representation) of the tree. Ex: vertex vertex weight
 *  Vector of objects of type <Vertex>.
 * Returns:
 *  Vector of objects of type <Vertex> which represent the vertices visited by the algorithm.
 *  Each vertex includes a field for the "previous vertex" which is the vertex by which the algorithm
 *  arrived at the present one.
 */
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

/*
 * Calculates the results of Dijkstra's algorithm by reversing the path from destination
 * vertices to the origin.
 * Args:
 *  Vector<Vector<int>> a list of paths. Index is the destination vertex. Stored by this function in reverse order.
 *  Vector<Vertex> the list of vertex and previous vertex pairs through which to trace the paths.
 */
void getPaths(std::vector<std::vector<int>> & paths, std::vector<Vertex> setS) {

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
}