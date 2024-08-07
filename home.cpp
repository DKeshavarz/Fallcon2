#include "home.h"

#include <vector>
#include <iostream>

using namespace std;

string Home::showCell(Point)const{
    return "5";
}
bool Home::canCollision(const Point&)const{
    return true;
}
const vector<Point> Home::creatFromMap (Point start,const vector<vector<int>>&){
    return {start};
}
const vector<Point> Home::specialEffect(Point start)const{
    return {start};
}