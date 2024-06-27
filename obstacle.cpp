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
const vector<Point>& Obstacle::constGetEntries()const{
    return this->entries;
}
void Obstacle::addEntry(Point input){
    //validation
    this->entries.push_back(input);
}
bool Obstacle::isEntry(Point input)const{
    for(const auto& point : this->entries)
        if(point == input)
            return true;

    return false;
}
