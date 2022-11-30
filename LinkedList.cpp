//
// Created by Alexander Allis on 9/1/22.
//

#include <vector>
#include "Node.h"
#include "LinkedList.h"


LinkedList::LinkedList() {
    this -> listPointer = nullptr;
    this -> tail = nullptr;
}

void LinkedList::add(int vertex, float weight) {
    Node* nodePointer = new Node;
    auto* vertexPointer = new Vertex(vertex, weight);
    if (listPointer == nullptr) this -> tail = nodePointer;  // if first node created, set tail
    nodePointer->data = *vertexPointer;
    nodePointer->next = listPointer;
    listPointer = nodePointer;
}

int LinkedList::isEmpty() const {
    if (this -> listPointer != nullptr) return 0;
    else return 1;
}

int LinkedList::hasNext() const {
    if (this -> listPointer != nullptr && this->listPointer->next != nullptr) return 1;
    else return 0;
}

Vertex LinkedList::pop() {
    Node* tmp = listPointer;
    listPointer = listPointer -> next;
    return (tmp -> data);
}

void LinkedList::clearList() {
    Node* next;
    while(listPointer != nullptr){
        next = listPointer -> next;
        delete listPointer;
        listPointer = next;
    }
}