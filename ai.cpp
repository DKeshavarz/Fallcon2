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