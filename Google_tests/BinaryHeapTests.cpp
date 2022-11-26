//
// Created by Alexander Allis on 11/23/22.
//

#include "gtest/gtest.h"
#include "../Dijkstra_lib/BinaryHeap.h"

class BinaryHeapTestFixture : public ::testing::Test {

protected:
    virtual void SetUp()
    {
        std::vector<Vertex> vertices = {
            {1,1},{2,2},{3,3},{4,4},{5,5},{6,6},{7,7},{8,8},{9,9},{10,10}
        };
        heap = new BinaryHeap(vertices);
    }

    virtual void TearDown() {
        delete heap;
    }

    BinaryHeap * heap;
};

TEST_F(BinaryHeapTestFixture, constructorTest){

    ASSERT_EQ(heap->getLocation(1), 0);
    ASSERT_EQ(heap->getLocation(2), 1);
    ASSERT_EQ(heap->getLocation(3), 2);
    ASSERT_EQ(heap->getLocation(4), 3);
    ASSERT_EQ(heap->getLocation(5), 4);
    ASSERT_EQ(heap->getLocation(6), 5);
    ASSERT_EQ(heap->getLocation(7), 6);
    ASSERT_EQ(heap->getLocation(8), 7);
    ASSERT_EQ(heap->getLocation(9), 8);
    ASSERT_EQ(heap->getLocation(10), 9);

}

TEST_F(BinaryHeapTestFixture, addTest) {
    Vertex v = Vertex(11, 0);
    heap->add(v);
    Vertex min = heap->heap_extract_min();
    ASSERT_EQ(min.vertex, 11);
}

TEST_F(BinaryHeapTestFixture, decreaseDistanceTestOne){

    heap->heapDecreaseDistance(10, 0);
    Vertex min = heap->heap_extract_min();

    ASSERT_EQ(min.vertex, 10);

}

TEST_F(BinaryHeapTestFixture, decreaseDistanceTestTwo) {

    heap->heapDecreaseDistance(1,0);
    Vertex min = heap->heap_extract_min();

    ASSERT_EQ(min.vertex, 1);
}

TEST_F(BinaryHeapTestFixture, decreaseDistanceTestThree) {

    heap->heapDecreaseDistance(8,0);
    Vertex min = heap->heap_extract_min();

    ASSERT_EQ(min.vertex, 8);
}

TEST_F(BinaryHeapTestFixture, decreaseDistanceTestFour) {

    heap->heapDecreaseDistance(1,0);
    Vertex min = heap->heap_extract_min();

    ASSERT_EQ(min.vertex, 1);
}

TEST_F(BinaryHeapTestFixture, decreaseDistanceTestFive) {

    heap->heapDecreaseDistance(10,0);
    Vertex min = heap->heap_extract_min();
    ASSERT_EQ(min.vertex, 10);

    heap->heapDecreaseDistance(9,0);
    min = heap->heap_extract_min();
    ASSERT_EQ(min.vertex, 9);

    heap->heapDecreaseDistance(8,0);
    min = heap->heap_extract_min();
    ASSERT_EQ(min.vertex, 8);

    heap->heapDecreaseDistance(7,0);
    min = heap->heap_extract_min();
    ASSERT_EQ(min.vertex, 7);

    heap->heapDecreaseDistance(6,0);
    min = heap->heap_extract_min();
    ASSERT_EQ(min.vertex, 6);

    heap->heapDecreaseDistance(5,0);
    min = heap->heap_extract_min();
    ASSERT_EQ(min.vertex, 5);

    heap->heapDecreaseDistance(4,0);
    min = heap->heap_extract_min();
    ASSERT_EQ(min.vertex, 4);

    heap->heapDecreaseDistance(3,0);
    min = heap->heap_extract_min();
    ASSERT_EQ(min.vertex, 3);

    heap->heapDecreaseDistance(2,0);
    min = heap->heap_extract_min();
    ASSERT_EQ(min.vertex, 2);

    heap->heapDecreaseDistance(1,0);
    min = heap->heap_extract_min();
    ASSERT_EQ(min.vertex, 1);

}

TEST_F(BinaryHeapTestFixture, parentTestOne) {
    Vertex * child = &heap->heapList.at(0);
    Vertex * parent = heap->getParent(*child);
    ASSERT_EQ(parent->vertex, child->vertex);
}

