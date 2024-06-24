#include "spacecraft.h"

#include <cctype>
#include <iostream>
#include <vector>

using namespace std; 

Spacecraft::Spacecraft(){ 
}
Spacecraft::Spacecraft(const Point& location,int inputEnergy){
    this->setPoint(location);
    this->setEnegy(inputEnergy);
}
void Spacecraft::setPoint(const Point& input){
    this->location = input;
}
void Spacecraft::moveTo(Point location){
    for(const auto[ch,point] : moveOptions){
        if(point+this->location == location){
            this->location = location;
            return;
        }
    }

    throw invalid_argument("Spacecraft can't go to that point");
}
const std::unordered_map<char,Point>& Spacecraft::getMoveOptions()const{
    return this->moveOptions;
}
void Spacecraft::setEnegy(int input){
    if(input < 0)
        throw out_of_range("Energy is invalid");
    this->energy = input;
}
