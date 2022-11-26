//
// Created by Alexander Allis on 11/23/22.
//

#ifndef DIJKSTRA_WEIGHT_H
#define DIJKSTRA_WEIGHT_H

#include <string>

class Weight {
public:
    int value;
    bool infinity;
    Weight();
    explicit Weight(int);
    explicit Weight(const std::string & str);
    void set(int val);
    void set(const std::string& str);
    int get() const;
    bool operator < (Weight w) const;
    bool operator < (int) const;
    bool operator > (Weight w) const;
    bool operator > (int) const;
    bool operator == (Weight w) const;
    bool operator == (int) const;
    bool isInf() const;

    void changeWeight(int i);
};


#endif //DIJKSTRA_WEIGHT_H
