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
void Spacecraft::moveTo(Point location,const Obstacle* const obstacle){
    if(obstacle and !obstacle->canCollision(location)){
        throw invalid_argument("can not have collision with this");
    }
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
const Point& Spacecraft::getMoveToDir(char direction)const{
    if(this->moveOptions.count(direction) == 0){
        throw invalid_argument("spacecraft dosn't have this direction ");
    }

    return this->moveOptions.at(direction);
}
void Spacecraft::useSpecialMove(const Obstacle* const obstacle){
    if(!obstacle){
        throw invalid_argument("There in no object in space");
    }

    const vector<Point> movment {obstacle->specialEffect(this->getPoint())};
    this->setPoint(movment.back());
}
void Spacecraft::setAISize(int col ,int row){
    this->myAI.setMap(col+1,row+1);
}

void Spacecraft::AImove(vector<vector<bool>> exist , vector<vector<Obstacle*>> cells){
    
    subEnergy();
    this->myAI.update(this->location);
    char dir = this->myAI.suggest(exist,cells,this->location);
    //this->myAI.printMap();
    this->moveTo(dir);
    
}
void Spacecraft::moveTo(char input){
    this->setPoint(getPoint() + moveOptions.at(input));
}

void Spacecraft::subEnergy(){
    this->energy--;
    if(this->energy < 0)
        throw invalid_argument("lack of energy");
}