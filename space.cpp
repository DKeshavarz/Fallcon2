#include "space.h"

#include <iostream>
#include <sstream>

using namespace std;

Space::Space() :
map(2,vector<Obstacle*> (5,nullptr)){
    
}
Space::~Space(){
    for(auto& x : this->map){
        for(auto& y : x){
            if(y != nullptr){
                delete y;
                y = nullptr;
            }
        }
    }
                
}

string Space::showMap(){
    ostringstream out;
    for(int i {} ; i < this->map.size() ; ++i){
        out << '|';
        for(int j {} ; j < this->map.at(i).size() ; ++j){
            if(map.at(i).at(j) == nullptr){
                out << ' ';
            }
        }
        out << "|\n";
    }
    return out.str();
}