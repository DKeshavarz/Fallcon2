#include "spacecraft.h"

#include <cctype>
#include <iostream>
#include <vector>

using namespace std; 

Spacecraft::Spacecraft():
moveOptions {{'a',{0,-1}} , {'d',{0,1}} , {'w',{-1,0}} , {'s',{1,0}}}
{
    
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
const std::unordered_map<char,Point>& Spacecraft::getMoveOptions(){
    return this->moveOptions;
}