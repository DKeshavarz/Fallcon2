#include "spacecraft.h"

#include <iostream>

using namespace std; 

Spacecraft::Spacecraft(){
    
}
Point Spacecraft::getPoint(){
    return this-> location;
}