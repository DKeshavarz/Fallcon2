#include "point.h"

#include <iostream>

using namespace std;

Point::Point(int x,int y){
    setX(x),setY(y);
    cout << "niga1";
}
int Point::getX(){
    return this->x;
}
int Point::getY(){
    return this->y;
}
void Point::setX(int input){
    this->x = input;
}
void Point::setY(int input){
    this->y = input;
}