//
// Created by Alexander Allis on 11/29/22.
//

#ifndef DIJKSTRA2_DIJKSTRAS_ALGORITHM_H
#define DIJKSTRA2_DIJKSTRAS_ALGORITHM_H

#endif //DIJKSTRA2_DIJKSTRAS_ALGORITHM_H

#include <vector>
#include "Vertex.h"
#include "BinaryHeap.h"
#include "LinkedList.h"

std::vector<Vertex> dijkstras_algorithm(BinaryHeap * heap, std::vector<LinkedList> * tree, std::vector<Vertex> & setS);

void getPaths(std::vector<std::vector<int>> & paths, std::vector<Vertex> setS);