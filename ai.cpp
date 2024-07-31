#include <vector>
#include <iostream>

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

char AI::suggest(std::vector<std::vector<bool>> exist, std::vector<std::vector<Obstacle*>> cells){
    return 'w';
}