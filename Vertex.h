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
//    Vertex(int i, int j) {
//        this->vertex = i;
//        this->distance = Weight(j);
//    };
    Vertex(int i, float f) {
        this->vertex = i;
        this->distance = Weight(f);
    }
    Vertex(int i, const std::string& j) {
        this->vertex = i;
        this->distance = Weight(j);
    }
    Vertex(int i, int j, float f) {
        this->vertex = i;
        this->precedingVertex = j;
        this->distance = Weight(f);
    }
    int getVertex() const {
        return this->vertex;
    }
    int getPrecedingVertex() const {
        return this->precedingVertex;
    }
    Weight getWeight() const {
        return this->distance;
    }
    float getDistanceInt() const {
        return this->distance.getWeightFloat();
    }
    void setDistance(float v) {
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
