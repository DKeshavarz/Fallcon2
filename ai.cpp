#include <vector>

#include "ai.h"
using namespace std;
AI::AI(){

}
void AI::setMap(int col , int row){
    this->map.assign(col, vector<int> (row , 0));
}

const vector<vector<int>>& AI::getMap(){
    return this -> map;
}