#include "wormHole.h"

#include <iostream>
using namespace std;

WormHole::WormHole(){

}
WormHole::~WormHole(){

}
void WormHole::addEntry(Point input){
    //ckeck for duplicated
    this->getEntries().push_back(input);

}
bool WormHole::isEntry(Point input){
    for(const auto& point :  this->getEntries()){
        if(point == input)
            return true;
    }
    return false;
}
string WormHole::showCell(Point)const{
    return "4";
}
const vector<Point> WormHole::creatFromMap(Point startLocation,const vector<vector<int>>& map){
    vector<Point> ans;
    for(int i {} ; i < map.size() ; ++i){
        for(int j {} ; j < map.at(i).size() ; ++j){
            if(map.at(i).at(j) == 4){
                ans.push_back({i,j});
                this->getEntries().push_back({i,j});
            }  
        }
    }

    return ans;   
}
const vector<Point> WormHole::specialEffect(){
    return {};
}
bool WormHole::canCollision(const Point& lacation)const{
    return true;
}