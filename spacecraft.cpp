#include "spacecraft.h"

#include <cctype>
#include <iostream>

using namespace std; 

Spacecraft::Spacecraft(){
    
}
Point Spacecraft::getPoint(){
    return this-> location;
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