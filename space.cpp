#include "space.h"
#include "wormHole.h"

#include <iostream>
#include <sstream>
#include <unordered_map>
#include <stdexcept>
#include <fstream> 

using namespace std;

Space::Space(int row , int column){
    if(row <= 0 or column <= 0)
        throw invalid_argument("Invalid map size");
    map.assign(row,vector<Obstacle*> (column,nullptr));
    this->spacecrafts.push_back(Spacecraft());

}
Space::Space(){
    loadMap();
}
Space::~Space(){
    for(auto& x : this->map){
        for(auto& y : x){
            if(y != nullptr){
                delete y;
                y = nullptr;
            }
        }
    }         
}
string Space::showMap(){
 
    ostringstream out;
    Spacecraft& mySpacecraft = this->spacecrafts.at(spacecraftIndex); // ckeck if exist
    
    for(int i {} ; i < this->map.size() ; ++i){
        out << '|';
        for(int j {} ; j < this->map.at(i).size() ; ++j){
            if(i == mySpacecraft.getPoint().getX() and j == mySpacecraft.getPoint().getY()){
                out << '*';

            }else if(map.at(i).at(j) == nullptr){
                out << ' ';
            }else{
                out << map.at(i).at(j)->showCell(Point{i,j});
            }
        }
        out << "|\n";
    }
    return out.str();
}
void Space::moveSpacecraft(char dir){
    Spacecraft& mySpacecraft = this->spacecrafts.at(spacecraftIndex); // can befunction

    const unordered_map<char,Point>& movment {mySpacecraft.getMoveOptions()};

    Point newPoint;
    if(movment.count(dir))
        newPoint = movment.at(dir) + mySpacecraft.getPoint();
    else{
        cout << "invalid key\n";
        return;
    }
    if( 0 > newPoint.getX() or newPoint.getX() >= map.size() or 
        0 > newPoint.getY() or newPoint.getY() >= map.back().size() ){
            cout << "not valid\n";
            return;
    }

    mySpacecraft.moveTo(newPoint);
}
void Space::loadMap(){
    ifstream inputFile {this->fileName};

    if(!inputFile.is_open()){
        throw runtime_error("Can't open " + fileName);
    }
    int mapRow , mapColumn;
    inputFile >> mapRow >> mapColumn;
    map.assign(mapRow,vector<Obstacle*> (mapColumn,nullptr));

    int spacecraftX , spacecraftY , spacecraftEnergy;
    inputFile >> spacecraftX >> spacecraftY >> spacecraftEnergy;
    Spacecraft spacecraft = Spacecraft(Point{spacecraftX,spacecraftY},spacecraftEnergy);
    this->spacecrafts.push_back(spacecraft);

    for(int i {}; i < mapRow ; ++i){
        int tmp;
        for(int j {}; j < mapColumn ; ++j){
            inputFile >> tmp;
            if(map.at(i).at(j) == nullptr and tmp == 4){//worm hole
                this->map[i][j] = new WormHole();
            }
        }
    }

    inputFile.close();
}

