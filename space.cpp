#include "space.h"

#include <iostream>
#include <sstream>
#include <unordered_map>

using namespace std;

Space::Space() :
map(2,vector<Obstacle*> (5,nullptr)){
    this->spacecrafts.push_back(Spacecraft());
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
    Spacecraft& mySpacecraft = this->spacecrafts.at(spacecraftIndex);
    for(int i {} ; i < this->map.size() ; ++i){
        out << '|';
        for(int j {} ; j < this->map.at(i).size() ; ++j){
            if(i == mySpacecraft.getPoint().getX() and j == mySpacecraft.getPoint().getY()){
                out << '*';

            }else if(map.at(i).at(j) == nullptr){
                out << ' ';
            }
        }
        out << "|\n";
    }
    return out.str();
}
void Space::moveSpacecraft(char dir){
    Spacecraft& mySpacecraft = this->spacecrafts.at(spacecraftIndex); // can befunction

    const unordered_map<char,Point>& movment {mySpacecraft.getMoveOptions()};

    Point newPoint = movment.at(dir) + mySpacecraft.getPoint();
    if( 0 > newPoint.getX() or newPoint.getX() >= map.size() or 
        0 > newPoint.getY() or newPoint.getY() >= map.back().size() ){
            cout << "not valid\n";
            return;
    }

    mySpacecraft.moveTo(newPoint);
}
