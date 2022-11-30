//
// Created by Alexander Allis on 11/23/22.
//

#include <string>
#include "Weight.h"

/*
 * Default constructor initializes to infinity
 */
Weight::Weight() {
    this->value = -1;
    this->infinity = true;
};

//Weight::Weight(int value) {
//    this->setWeight(value);
//}

Weight::Weight(float value) {
    this->setWeight(value);
}

Weight::Weight(const std::string& str) {
    this->set(str);
}

void Weight::setWeight(float val) {
    this->value = val;
    this->infinity = false;
}

//void Weight::setWeight(int val) {
//    this->value = val;
//    this->infinity = false;
//}

void Weight::set(const std::string& str) {
    if(str == "inf") {
        this->infinity = true;
        value = -1;
    }
}

//int Weight::getWeightFloat() {
//    return this->value;
//}

//void Weight::setWeight(int i) {
//    this->value = i;
//    this->infinity = false;
//}

void Weight::setToInfinity() {
    this->infinity = true;
    this->value = -1;
}

float Weight::getWeightFloat() const {
    return this->value;
}

bool Weight::operator < (Weight w) const {
    if(w.isInf() && this->isInf()) {
        return false;
    }
    else if (w.isInf()) {
        return true;
    }
    else if (this->isInf()) {
        return false;
    }
    else {
        return this->value < w.value;
    }
}
// TODO: Fix definitions below like that above ^.
bool Weight::operator < (float i) const {
    if(this->isInf()) {
        return false;
    }
    else {
        return this->value < i;
    }
}

bool Weight::operator > (Weight w) const {
    if(w.isInf()) {
        return false;
    }
    else if(this->isInf()) {
        return true;
    }
    else {
        return this->value > w.value;
    }
}

bool Weight::operator > (float i) const {
    if(this->isInf()) {
        return true;
    }
    else {
        return this->value > i;
    }
}

bool Weight::operator == (Weight w) const {
    if(this->isInf() && w.isInf()) {
        return true;
    }
    else if(this->isInf() || w.isInf()) {
        return false;
    }
    else {
        return this->value == w.value;
    }
}

bool Weight::operator == (float i) const {
    if(this->isInf()) {
        return false;
    }
    else {
        return this->value == i;
    }
}

float Weight::operator + (Weight w) const {
    if(this->isInf() || w.isInf()) {
        return -1;
    }
    else {
        return this->value + w.value;
    }
}

bool Weight::isInf() const {
    if(this->infinity) return true;
    return false;
}

