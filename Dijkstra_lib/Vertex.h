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
    Vertex(int i, const std::string& j) {
        this->vertex = i;
        this->distance = Weight(j);
    }
    void setDistance(int v) {
        this->distance.setWeight(v);
    };
    void setToInfinity() {
        this->distance.setToInfinity();
    }
};

#endif //DIJKSTRA_VERTEX_H
