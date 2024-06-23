#include "wormHole.h"

#include <iostream>
using namespace std;

WormHole::WormHole(){

}
WormHole::~WormHole(){

}
void WormHole::addEntry(Point input){
    //ckeck for duplicated
    this->entries.push_back(input);

}
bool WormHole::isEntry(Point input){
    for(const auto& point :  this->entries){
        if(point == input)
            return true;
    }
    return false;
}
string WormHole::showCell(Point){
    return "4";
}
const vector<Point> WormHole::creatFromMap(Point startLocation,vector<vector<int>> map){
    cout << "helll\n";
    vector<Point> ans;
    for(int i {} ; i < map.size() ; ++i){
        for(int j {} ; j < map.at(i).size() ; ++j){
            if(map.at(i).at(j) == 4)
                ans.push_back({i,j});
        }
    }

    return ans;   
}
const vector<Point> WormHole::specialEffect(){
    return {};
}