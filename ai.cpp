#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

#include "ai.h"
using namespace std;
AI::AI(){

}
void AI::setMap(int col , int row){
    this->map.assign(col, vector<int> (row , 0));
}

const vector<vector<int>>& AI::getMap()const{
    return this -> map;
}

void AI::printMap(){
    for(const auto& x : this->map){
        for(const auto& y : x){
            cout << y << ' ';
        }
        cout << '\n';
    }
}

char AI::suggest(std::vector<std::vector<bool>> exist, std::vector<std::vector<Obstacle*>> cells , Point loc){
    vector<pair<int,char>> dir;
    unordered_map <char,char> revers {{'a','d'} , {'d','a'} , {'w','s'} , {'s','w'}};

    dir.push_back({check(loc+Point{0,-1},cells[1][0]),'a'});
    dir.push_back({check(loc+Point{0, 1},cells[1][2]),'d'});
    dir.push_back({check(loc+Point{-1,0},cells[0][1]),'w'});
    dir.push_back({check(loc+Point{1, 0},cells[2][1]),'s'});

    sort(dir.begin() , dir.end());
    if( dir.back().first == 0 and this->design.size() > 0){
        char ans = design.top();
        design.pop();
        return ans;
    }
    
    this->design.push(revers[dir.back().second]);
    return dir.back().second;
}

void AI::update(Point curr){
    int x = curr.getX();
    int y = curr.getY();

    for (int i {-1} ; i <= 1 ; i++){
        for (int j {-1} ; j <= 1 ; j++){
            if((i+x >= 0 and i+x < map.size()) and (j+y >= 0 and j+y < map.back().size())){
                this->map[i+x][j+y] = 1;
            }
        }
    }
}
int AI::check (Point loc , Obstacle* object){
    int x = loc.getX();
    int y = loc.getY();

    if(!( (x >= 0 and x < map.size()) and (y >= 0 and y < map.back().size()) )){
        return -1;
    }

    if(object != nullptr and !object->canCollision(loc))
        return -1;

    int tmp {};
    for (int i {-1} ; i <= 1 ; i++){
        for (int j {-1} ; j <= 1 ; j++){
            if((i+x >= 0 and i+x < map.size()) and (j+y >= 0 and j+y < map.back().size())){
                tmp += map[i+x][j+y] == 0;
            }
        }
    }

    return tmp;

}