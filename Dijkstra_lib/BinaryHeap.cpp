//
// Created by Alexander Allis on 11/23/22.
//

#include "BinaryHeap.h"
#include "Vertex.h"
#include <vector>

BinaryHeap::BinaryHeap() = default;

/*
 * Must use this constructor. Default constructor does not work
 * with this program. Must initialize heapMap to the size of the heap.
 * Args:
 *  int sizeOfHeap: the final, maximum size of the heap
 */
BinaryHeap::BinaryHeap(int sizeOfHeap) {
    this->heapMap = HeapMap(sizeOfHeap);
}

/*
 * Constructor. Takes a vector of vertices and adds them to the
 * binary heap.
 */
BinaryHeap::BinaryHeap(const std::vector<Vertex> & vertexList) {
    this->heapMap = HeapMap((int) vertexList.size());
    for(auto & i : vertexList) {
        this->add(i);
    }
}

/*
 * Adds an object of type Vertex to the binary heap.
 */
BinaryHeap * BinaryHeap::add(Vertex v) {

    this->heapList.push_back(v);
    heapMap.emplace(v, (int) this->heapList.size() - 1);

    heapify_up(getLocation(v));
    return this;
}

BinaryHeap * BinaryHeap::add(int vertex, float weight) {
    Vertex v = Vertex(vertex, weight);
    this->add(v);
    return this;
}

BinaryHeap * BinaryHeap::add(int vertex, const std::string& weight) {
    Vertex v = Vertex(vertex, weight);
    this->add(v);
    return this;
}

/*
 * returns the index of a vertex in the binary heap list.
 * Args: Vertex v.
 * Returns: the index of v in heapList.
 */
int BinaryHeap::getLocation(Vertex & v) {
    return this->heapMap.getLocation(v);
}

/*
 * Returns the index of a vertex in the binary heap list.
 * Args: int vertexKey: the key value of the vertex to be found
 * Returns: (int) the index of the vertex in heapList
 */
int BinaryHeap::getLocation(int vertexKey) {
    return this->heapMap.getLocation(vertexKey);
}

bool BinaryHeap::inQueue(Vertex v) {
    return this->heapMap.getLocation(v.vertex) != -1;
}

/*
 * Decreases the distance field in an object of type Vertex. Calls
 * heapify_up() and heapify_down() to preserve the definition of
 * a binary heap.
 * Args:
 *  Vertex v: the object to change
 *  int d: the new value of the distance field.
 */
void BinaryHeap::heapDecreaseDistance(Vertex * v, float d) {
    int indexOfV = getLocation(*v);
    this->heapList.at(indexOfV).setDistance(d);
    heapify_up(indexOfV);
    heapify_down(indexOfV);
}

/*
 * Decreases the distance field of an object of type Vertex.
 * Args:
 *  int key: the key value of the Vertex object to change
 *  int d: the new distance
 */
void BinaryHeap::heapDecreaseDistance(int key, int d) {
    Vertex * vertex = &this->heapList.at(getLocation(key));
    vertex->setDistance(d);
    heapify_up(getLocation(key));
    heapify_down(getLocation(key));
}

/*
 * Returns the parent of a vertex according to binary heap rules.
 * Args:
 *  Vertex v: the object of type Vertex in question.
 * Returns:
 *  Vertex *: a pointer to the parent.
 */
Vertex * BinaryHeap::getParent(Vertex & v) {
    int indexOfV = getLocation(v);
    if(indexOfV == 0) return &v;
    int place = indexOfV + 1;
    return &heapList.at((place / 2) - 1);
}

/*
 * Performs heapify-up procedure on a vertex
 * Args:
 *  int i: the index of the vertex to heapify-up
 */
void BinaryHeap::heapify_up(int i) {
    Vertex v = this->heapList.at(i);
    int place = i + 1;
    if(place > 1) {
        Vertex * j = getParent(v);
        if(v.distance < j->distance) {
            swapVertices(v, *j);
            heapify_up(getLocation(*j));  //TODO: CHECK LOGIC HERE
        }
    }
}

/*
 * Swaps two vertices in heapList.
 * Args:
 *  Vertex i, Vertex j: the objects of type Vertex to swap
 */
void BinaryHeap::swapVertices(Vertex i, Vertex j) {

    // Swap vertices in heapList
    Vertex temp = j;
    this->heapList.at(getLocation(j)) = i;
    this->heapList.at(getLocation(i)) = temp;

    // Swap values in map
    heapMap.swapLocations(i, j);

}

/*
 * Finds the minimum value in the heap and removes it.
 * Returns: an object of type Vertex
 */
Vertex BinaryHeap::heap_extract_min() {
    return this->remove(this->heapList.at(0));
//    removeRecursive(0);
}

/*
 * Removes a vertex from the heap
 * Args:
 *  Vertex V: the vertex to remove
 * Returns:
 *  Vertex: the removed vertex
 */
Vertex BinaryHeap::remove(Vertex v) {

    if(this->heapList.size() == 1) {
        Vertex returnV = this->heapList.at(0);
        this->heapList.resize(0);
        return returnV;
    }

    int indexOfV = getLocation(v);
    Vertex lastVertexInHeap = heapList.at(heapList.size() - 1);
    // Swap vertices in list
    swapVertices(v, lastVertexInHeap);  // Includes calls to heapify-up and heapify-down
    // Set index in heapMap to -1 to show that it's removed
    heapMap.remove(v.vertex);
    // Resize list to remove last element
    heapList.resize(heapList.size() - 1);


    heapify_down(indexOfV);
    heapify_up(indexOfV);
    return v;
}

/*
 * Performs heapify-down procedure to maintain the definition
 * of a binary heap. Calls itself recursively.
 * Args:
 *  int i: The location (index) of the heapify-down procedure
 */
void BinaryHeap::heapify_down(int i) {
    Vertex v = this->heapList.at(i);
    int heapListSize = (int) heapList.size();
    int j = 0;
    int left;
    int right;
    int place = i + 1;  // Place is the index starting at 1. It is used for the 2*i, 2*i+1 math to build the tree.

    if(2 * place > heapListSize) {
        return;
    }
    else if(2 * place < heapListSize) {
        left = 2 * place - 1;  // Subtract 1 to get hte actual index
        right = 2 * place;  // complete expression is 2*place+1-1, where we wubtract 1 forthe final index
        if (heapList.at(left).distance < heapList.at(right).distance)
            j = left;
        else
            j = right;
    }
    else if(2 * place == heapListSize)
        j = 2 * place - 1;  // subtract 1 to get the actual index
    if(heapList.at(j).distance < v.distance) {
        // Swap values in heapList
        swapVertices(heapList.at(i), heapList.at(j));
        heapify_down(j);
    }
}

/*
 * Returns true if the heap if empty, false otherwise.
 */
bool BinaryHeap::isEmpty() const {
    return this->heapList.empty();
}