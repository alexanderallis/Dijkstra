//
// Created by Alexander Allis on 10/10/22.
//

#ifndef KOSARAJU_SHARIR_READ_INPUT_H
#define KOSARAJU_SHARIR_READ_INPUT_H

#include "LinkedList.h"

int readFile(const std::string & , std::vector<std::pair<int, int>> & , int &, int &);

int getPairsFromStdIn(std::vector<LinkedList> & treePairs, int & numberOfVertices, int & numberOfEdges);

#endif //KOSARAJU_SHARIR_READ_INPUT_H