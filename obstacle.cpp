#include "obstacle.h"

#include <iostream>

using namespace std;

Obstacle::Obstacle(){
    
}
Obstacle::~Obstacle(){
    
}
vector<Point>& Obstacle::getEntries(){
    return this->entries;
}
const vector<Point>& Obstacle::getEntries()const{
    return this->entries;
}
