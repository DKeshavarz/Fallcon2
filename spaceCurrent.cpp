#include "spaceCurrent.h"

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