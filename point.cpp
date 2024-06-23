#include "point.h"

#include <iostream>

using namespace std;

Point::Point(int x,int y){
    setX(x),setY(y);
}
int Point::getX()const{
    return this->x;
}
int Point::getY()const{
    return this->y;
}
void Point::setX(int input){
    this->x = input;
}
void Point::setY(int input){
    this->y = input;
}
Point Point::operator+(const Point& obj)const{
    int x = obj.x + this->x;
    int y = obj.y + this->y;  
    return Point(x,y);
}
Point Point::operator==(const Point& obj)const{
    return (obj.x == this->x) and (obj.y == this->y);
}