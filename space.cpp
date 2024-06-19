#include "space.h"

#include <iostream>

using namespace std;

Space::Space() :
map(1,vector<Obstacle*> (1,nullptr)){
    
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