#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

// Dijkstra's Algorithm
//Dijkstra_Algorithm(vector<LinkedList>)


// Old Dijkstra's Algorithm
//void dijkstras_algo(const std::vector<LinkedList>& tree, int s) {
//    // create an empty priority queue
//    auto * priorityQueue = new BinaryHeap();
//    int graphSize = (int) tree->size();
//    for(int i = 0; i < tree->size(); i++) {
//        vertex v{};
//        v.key = i;
//        v.distance = std::numeric_limits<float>::infinity();
//        priorityQueue->add(v);
//    }
//    vertex originVertex{};
//    originVertex.key = s;
//    originVertex.distance = 0;
//    priorityQueue->add(originVertex);
//    while(!priorityQueue->isEmpty()) {  // while there are still vertices in V
//        vertex vertexU = priorityQueue->heap_extract_min();
//        while(!tree->at(vertexU).isEmpty) {  // for each edge (u,v) E E leaving u
//            vertex edgeUV = tree->at(vertexU).pop();
//            vertex v = priorityQueue->find(edgeUV.key);
//            if(v.distance > vertexU.distance + edgeUV.distance) {
//                v.distance = vertexU.distance + edgeUV.distance;
//            }
//        }
//    }