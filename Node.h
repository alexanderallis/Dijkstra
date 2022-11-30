//
// Created by Alexander Allis on 9/1/22.
//

#ifndef GALE_SHAPELY_NODE_H
#define GALE_SHAPELY_NODE_H

#include "Vertex.h"

class Node {
    public:
        Node();
        Vertex data;
        Node* next;
    private:
};



#endif //GALE_SHAPELY_NODE_H
