//
// Created by Alexander Allis on 9/1/22.
//

#ifndef GALE_SHAPELY_LINKEDLIST_H
#define GALE_SHAPELY_LINKEDLIST_H

#include <vector>
#include "Node.h"

class LinkedList {
    public:
        LinkedList();
//        explicit LinkedList(const std::vector<int>&);
//        ~LinkedList();
        void add(int, int);
        void add(int vertex, float weight);
//        void addTail(int);
        Vertex pop();
        int isEmpty() const;
        void clearList();

    private:
        Node* listPointer{};
        Node* tail{};
        int hasNext() const;

};

#endif //GALE_SHAPELY_LINKEDLIST_H
