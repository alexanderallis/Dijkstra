//
// Created by Alexander Allis on 11/23/22.
//

#ifndef DIJKSTRA_WEIGHT_H
#define DIJKSTRA_WEIGHT_H

#include <string>

class Weight {
public:
    float value;
    bool infinity;
    Weight();
    explicit Weight(float);
    explicit Weight(const std::string & str);
    void setWeight(float val);
    void set(const std::string& str);
    float getWeightFloat() const;
    bool operator < (Weight w) const;
    bool operator < (float) const;
    bool operator > (Weight w) const;
    bool operator > (float) const;
    bool operator == (Weight w) const;
    bool operator == (float) const;
    float operator + (Weight w) const;
    bool isInf() const;

    void setToInfinity();
};


#endif //DIJKSTRA_WEIGHT_H
