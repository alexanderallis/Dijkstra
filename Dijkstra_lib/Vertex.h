//
// Created by Alexander Allis on 11/23/22.
//

#ifndef DIJKSTRA_VERTEX_H
#define DIJKSTRA_VERTEX_H

#include "Weight.h"

class Vertex {
public:
    int vertex;
    Weight distance;
    Vertex() = default;
    Vertex(int i, int j) {
        this->vertex = i;
        this->distance = Weight(j);
    };
    void change_distance(int v) {
        this->distance.changeWeight(v);
    };
};

#endif //DIJKSTRA_VERTEX_H
