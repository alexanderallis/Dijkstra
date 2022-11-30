//
// Created by Alexander Allis on 11/23/22.
//

#ifndef DIJKSTRA_VERTEX_H
#define DIJKSTRA_VERTEX_H

#include "Weight.h"

class Vertex {
public:
    int vertex;
    int precedingVertex = 1;
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
    int getVertex() {
        return this->vertex;
    }
    int getPrecedingVertex() {
        return this->precedingVertex;
    }
    Weight getWeight() {
        return this->distance;
    }
    int getDistanceInt() const {
        return this->distance.getWeightInt();
    }
    void setDistance(int v) {
        this->distance.setWeight(v);
    };
    void setToInfinity() {
        this->distance.setToInfinity();
    }
    void setPrecedingVertex(int p) {
        this->precedingVertex = p;
    }
};

#endif //DIJKSTRA_VERTEX_H
