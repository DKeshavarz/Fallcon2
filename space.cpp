#include "space.h"
#include "wormHole.h"
#include "spaceCurrent.h"

#include <iostream>
#include <sstream>
#include <unordered_map>
#include <stdexcept>
#include <fstream> 

using namespace std;

Space::Space(int row , int column){
    if(row <= 0 or column <= 0)
        throw invalid_argument("Invalid map size");

    map.assign(row,vector<shared_ptr<Obstacle>> (column));
    this->spacecrafts.push_back(Spacecraft());
}
Space::Space(){
    loadMap();
}
Space::~Space(){

}
string Space::showMap()const{

    if(0 > this-> spacecraftIndex or this->spacecrafts.size() <= this-> spacecraftIndex)
        throw out_of_range("Current spacecraft dosn't exist");

    ostringstream out;
    const Spacecraft& mySpacecraft = this->spacecrafts.at(spacecraftIndex); //only for simple access 
    
    for(int i {} ; i < this->map.size() ; ++i){
        out << '|';
        for(int j {} ; j < this->map.at(i).size() ; ++j){
            if(i == mySpacecraft.getPoint().getX() and j == mySpacecraft.getPoint().getY()){
                out << " * ";
            }else if(map.at(i).at(j) == nullptr){
                out << "   ";
            }else{
                out << " " <<map.at(i).at(j)->showCell(Point{i,j}) << " ";
            }
            out << "|";
        }
        out << '\n';
        for(int j {} ; j < this->map.at(i).size() ; ++j)
            out << "----";
        out << '\n';
        
    }
    return out.str();
}
void Space::moveSpacecraft(char dir){
    Spacecraft& mySpacecraft = this->spacecrafts.at(spacecraftIndex); // can be a function
   
    Point newPoint = mySpacecraft.getMoveToDir(dir) + mySpacecraft.getPoint();
    
    mySpacecraft.moveTo(newPoint,getCell(newPoint));
}
void Space::specialMoveSpacecraft(){
    Spacecraft& mySpacecraft = this->spacecrafts.at(spacecraftIndex); // can be function
    mySpacecraft.useSpecialMove(getCell(mySpacecraft.getPoint()));
}
void Space::loadMap(){
    ifstream inputFile {this->fileName};

    if(!inputFile.is_open()){
        throw runtime_error("Can't open " + fileName);
    }
    int mapRow , mapColumn;
    inputFile >> mapRow >> mapColumn;
    map.assign(mapRow,vector<shared_ptr<Obstacle>> (mapColumn));

    int spacecraftX , spacecraftY , spacecraftEnergy;
    inputFile >> spacecraftX >> spacecraftY >> spacecraftEnergy;
    Spacecraft spacecraft = Spacecraft(Point{spacecraftX,spacecraftY},spacecraftEnergy);
    this->spacecrafts.push_back(spacecraft);

    vector<vector<int>> tmpMapHolder(mapRow,vector<int>(mapColumn,-1));
    for(int i {}; i < mapRow ; ++i){
        for(int j {}; j < mapColumn ; ++j){
            inputFile >>tmpMapHolder[i][j] ;        
        }
    }

    addObstacle(tmpMapHolder);

    inputFile.close();
}
void Space::addObstacle(vector<vector<int>> numericMap){
    shared_ptr<Obstacle> obstaclePtr;
    //cout << "Space::addObstacle -> start \n";
    for(int i {} ; i < numericMap.size() ; ++i){
        for(int j {} ; j < numericMap.at(i).size() ; ++j){
            if(this->map.at(i).at(j) != nullptr){
                //empty on purpose
            }else if(numericMap.at(i).at(j) == 4){
                obstaclePtr = shared_ptr<Obstacle> (new WormHole());
            }else if(numericMap.at(i).at(j) == 3){

            }else if(numericMap.at(i).at(j) == 2 or numericMap.at(i).at(j) == 1){
                obstaclePtr = shared_ptr<Obstacle> (new SpaceCurrent());
            }
            
            if(obstaclePtr){
                for(const auto& point : obstaclePtr->creatFromMap({i,j},numericMap)){
                    this->map[point.getX()][point.getY()] =obstaclePtr;
                }
            }
            
            obstaclePtr.reset();
        }
    }
}

bool Space::isOnMap(int i,int j){
    return !( 0 > i or i >= map.size() or 0 > j or j >= map.back().size() );
}
bool Space::isOnMap(const Point& point){
    return this->isOnMap(point.getX(),point.getY());
}
const Obstacle* const Space::getCell(const Point& point){
    if(!this->isOnMap(point))
        throw invalid_argument("postion is outside the map");
    
    return this->map.at(point.getX()).at(point.getY()).get();
}
