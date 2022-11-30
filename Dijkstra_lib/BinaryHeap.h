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
    BinaryHeap(int sizeOfHeap);

    std::vector<Vertex> heapList;
    HeapMap heapMap;  // operates in O(1)

    BinaryHeap();
    explicit BinaryHeap(const std::vector<Vertex>&);
    BinaryHeap* add(Vertex);
    void heapify_down(int);
    void heapify_up(int);
    Vertex * getParent(Vertex &);
    Vertex remove(Vertex);
    Vertex heap_extract_min();
    bool isEmpty() const;
    void heapDecreaseDistance(Vertex * v, float);
    void heapDecreaseDistance(int key, int d);
    int getLocation(Vertex & v);
    int getLocation(int vertex);
    void swapVertices(Vertex i, Vertex j);


    BinaryHeap *add(int vertex, float weight);

    BinaryHeap *add(int vertex, const std::string &weight);

    bool inQueue(Vertex v);
};

#endif //DIJKSTRA_BINARYHEAP_H
