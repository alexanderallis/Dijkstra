//
// Created by Alexander Allis on 11/17/22.
//

#ifndef DIJKSTRA_BINARYHEAP_H
#define DIJKSTRA_BINARYHEAP_H


#include <vector>
#include <map>
#include "Weight.h"
#include "Vertex.h"
#include "HeapMap.h"


class BinaryHeap {
public:
    std::vector<Vertex> heapList;
    HeapMap heapMap;  // operates in O(1)

    BinaryHeap();
    explicit BinaryHeap(const std::vector<Vertex>&);
    BinaryHeap* add(Vertex);
    void heapify_down(int);
    void heapify_up(int);
    Vertex * getParent(Vertex &);
    Vertex remove(Vertex);
    void removeRecursive(int indexOfVertex);
    Vertex heap_extract_min();
    bool isEmpty() const;
    void heapDecreaseDistance(Vertex * v, int);
    void heapDecreaseDistance(int key, int d);
    int getLocation(Vertex & v);
    int getLocation(int vertex);

private:

    void swapVertices(Vertex i, Vertex j);


};

#endif //DIJKSTRA_BINARYHEAP_H