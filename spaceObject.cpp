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
    vector<Point> ans;
    //needs better validation
    const vector<Point> planetDirections {{0,0}/*stay*/,{1,0}/*down*/,{0,1}/*right*/,{1,1}/*down right*/};
    const vector<Point> enteryDirection  {{2,0}/*down*/,{2,1}/*down*/,{1,2}/*right*/,{0,2}/*right*/
                                         ,{-1,1}/*up*/,{-1,0}/*up*/ ,{0,-1}/*left*/,{1,-1}/*left*/};

    for(const auto& dir : planetDirections){
        this->planet.push_back(dir+loacation);
        ans.push_back(dir+loacation);
    }
    for(const auto& dir : enteryDirection){
        this->getEntries().push_back(dir+loacation);
        ans.push_back(dir+loacation);
    }

    return ans;
}
const vector<Point> SpaceObject::specialEffect(Point loacation)const{
    if(!this->isEntry(loacation)){
        throw invalid_argument("can not use spaceobject here");
    }

    int i {};
    vector<Point> way;
    while(this->constGetEntries().at(i) != loacation)++i;

    for(int j {0} ;  j < 4 ; ++j){
        way.push_back(this->constGetEntries().at((i+j)%constGetEntries().size()));
    }

    return way;
}