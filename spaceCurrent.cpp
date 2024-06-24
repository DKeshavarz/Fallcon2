#include "spaceCurrent.h"

 #include <stdexcept>
 #include <iostream>

using namespace std;

void SpaceCurrent::addEntry(Point input){
    //validation
    this->entries.push_back(input);
}
bool SpaceCurrent::isEntry(Point input){
    for(const auto& point : this->entries)
        if(input.getX() == point.getX() and input.getX() == point.getX())//todo:replace with ==
            return true;

    return false;
}

void SpaceCurrent::addLine(Point input){
    //validation like dublicated
    this->line.push_back(input);
}
bool SpaceCurrent::isLine(Point input){
    for(const auto& point : this->line)
        if(input.getX() == point.getX() and input.getX() == point.getX())//todo:replace with ==
            return true;

    return false;
}

std::string SpaceCurrent::showCell(Point input){
    if(isEntry(input))
        return "1";
    return "2";
}

const vector<Point> SpaceCurrent::creatFromMap (Point startLocation,vector<vector<int>> map){
    vector<Point> ans;
    dfs(ans,map,startLocation);

    cout << "vector<Point> SpaceCurrent::creatFromMap -> ans is:";
    for(const auto& x : ans)
        cout << x.getX() << ' ' << x.getY() << "   ";
    return ans;
}
const vector<Point> SpaceCurrent::specialEffect(){
    return vector<Point>();
}

void SpaceCurrent::dfs(vector<Point>& ans,vector<vector<int>> map , Point start){
    int x {start.getX()} , y {start.getY()};
    
    try{
        if(map.at(x).at(y) == 1 || map.at(x).at(y) == 2){
            if(map.at(x).at(y) == 1) this->entries.push_back({x,y});
            else                     this->line.push_back({x,y});
            ans.push_back({x,y});
            dfs(ans,map,{x+1,y});dfs(ans,map,{x-1,y});
            dfs(ans,map,{x,y+1});dfs(ans,map,{x+1,y-1});
        }

    }catch(const out_of_range& err){
        return;
    }
}