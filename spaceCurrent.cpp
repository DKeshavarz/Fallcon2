#include "spaceCurrent.h"

#include <stdexcept>
#include <iostream>

using namespace std;

SpaceCurrent::SpaceCurrent(){
}
SpaceCurrent::~SpaceCurrent(){
    // cout << "~SpaceCurrent() -> ";
    // for(const auto& i : this->getEntries())
    //     cout << i << " - ";
    // cout << '\n';
    // for(const auto& i : this->line)
    //     cout << i << " - ";
    // cout << '\n';
}

void SpaceCurrent::addLine(Point input){
    //validation like dublicated
    this->line.push_back(input);
}
bool SpaceCurrent::isLine(Point input)const{
    for(const auto& point : this->line)
        if(input == point)
            return true;

    return false;
}

std::string SpaceCurrent::showCell(Point input)const{
    if(isEntry(input))
        return "1";
    return "2";
}

const vector<Point> SpaceCurrent::creatFromMap (Point startLocation,const vector<vector<int>>& map){
    vector<Point> ans;
    vector<vector<int>> tmp = (map);
    dfs(ans,tmp,startLocation);

    return ans;
}
const vector<Point> SpaceCurrent::specialEffect(Point loacation)const{
    bool flag {true};

    vector <Point> ans {this->line};
    for(const auto& tmpPoint : this->constGetEntries()){
        if(tmpPoint != loacation){
            ans.push_back(tmpPoint);
        }else{
            flag = false;
        }
    }

    if(flag){
        throw invalid_argument("You can't use spaceCurrent from here");
    }
    return ans;
}

void SpaceCurrent::dfs(vector<Point>& ans,vector<vector<int>>& map , Point start){
    int x {start.getX()} , y {start.getY()};
    
    try{
        if(map.at(x).at(y) == 1 || map.at(x).at(y) == 2){
            
            if(map.at(x).at(y) == 1) this->getEntries().push_back({x,y});
            else                     this->line.push_back({x,y});
            map[x][y] = 0;  // dangrous line
            ans.push_back({x,y});
            dfs(ans,map,{x+1,y});dfs(ans,map,{x-1,y});
            dfs(ans,map,{x,y+1});dfs(ans,map,{x+1,y-1});
        }

    }catch(const out_of_range& err){
        return;
    }
}
bool SpaceCurrent::canCollision(const Point& location)const{
    for(const auto& point : this->constGetEntries()){
        if(point == location)
            return true;
    }
    return false;
}