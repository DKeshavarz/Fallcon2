#include "spaceObject.h"

#include <iostream>
using namespace std;

SpaceObject::SpaceObject(){

}
SpaceObject::~SpaceObject(){

}

string SpaceObject::showCell(Point loacation)const{
    if(this->isEntry(loacation))
        return "+";

    return "3";
}

bool SpaceObject::canCollision(const Point& loacation)const{
    if(this->isEntry(loacation))
        return true;

    return false;
}
const vector<Point> SpaceObject::creatFromMap (Point loacation,const vector<vector<int>>& map){
    //needs better validation
    const vector<Point> directions {{0,0}/*stay*/,{1,0}/*down*/,{0,1}/*right*/,{1,1}/*down right*/};
    
    for(const auto& dir : directions){
        this->planet.push_back(dir+loacation);
    }

    return {this->planet};
}
const vector<Point> SpaceObject::specialEffect(Point)const{

}