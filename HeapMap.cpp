//
// Created by Alexander Allis on 11/23/22.
//

#include "HeapMap.h"
#include "Vertex.h"

HeapMap::HeapMap() = default;

HeapMap::HeapMap(int size) {
    this->size = size;
    list = new int[this->size];
}

void HeapMap::emplace(int vertex, int location) {
    list[vertex - 1] = location;
}

void HeapMap::emplace(Vertex v, int location) {
    list[v.vertex - 1] = location;
}

void HeapMap::remove(int vertex) {
    list[vertex - 1] = -1;
}

/*
 * Adjusted for indexes
 */
void HeapMap::swapLocations(int indexA, int indexB) {
    int temp = list[indexA];
    list[indexA] = list[indexB];
    list[indexB] = temp;
}

/*
 * Adjusted for vertices
 */
void HeapMap::swapLocations(Vertex & vertexA, Vertex & vertexB) {
    int temp = list[vertexA.vertex - 1];
    list[vertexA.vertex - 1] = list[vertexB.vertex - 1];
    list[vertexB.vertex - 1] = temp;
}

int HeapMap::getLocation(int vertexKey) {
    return list[vertexKey - 1];
}

int HeapMap::getLocation(Vertex & v) {
    return list[v.vertex - 1];
}



