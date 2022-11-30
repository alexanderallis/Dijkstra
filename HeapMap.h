//
// Created by Alexander Allis on 11/23/22.
//

#ifndef DIJKSTRA_HEAPMAP_H
#define DIJKSTRA_HEAPMAP_H


#include "Vertex.h"

class HeapMap {

    int * list;

public:
    int size;

    HeapMap();

    HeapMap(int size);

    void emplace(int vertex, int location);

    void emplace(Vertex, int);

    void remove(int vertex);

    void swapLocations(int i, int indexB);

    int getLocation(int vertex);

    int getLocation(Vertex & v);

    void swapLocations(Vertex & vertexA, Vertex & vertexB);
};


#endif //DIJKSTRA_HEAPMAP_H
