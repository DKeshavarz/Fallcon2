#include "spacecraft.h"

#include <cctype>
#include <iostream>
#include <vector>

using namespace std; 

Spacecraft::Spacecraft()
{
    
}
Spacecraft::Spacecraft(Point location,int enrgy){
    this->setPoint(location);
    this->setEnegy(energy);
}
Point Spacecraft::getPoint(){
    return this-> location;
}
void Spacecraft::setPoint(Point input){
    this->location = input;
}
void Spacecraft::move(char dir){
    // use unordered map and overload  + in point
    // exeption handeling for unknown dir
    dir = tolower(dir);
    
    
}
void Spacecraft::moveTo(Point location){
    //ckeck location
    this->location = location;

}
const std::unordered_map<char,Point>& Spacecraft::getMoveOptions(){
    return this->moveOptions;
}
void Spacecraft::setEnegy(int input){
    if(input < 0)
        throw out_of_range("Energy is invalid");
    this->energy = input;
}
int Spacecraft::getEnergy(){
    return this->energy;
}