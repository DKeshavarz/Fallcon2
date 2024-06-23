#include "wormHole.h"

void WormHole::addEntry(Point input){
    //ckeck for duplicated
    this->entries.push_back(input);

}
bool WormHole::isEntry(Point input){
    for(const auto& point :  this->entries){
        if(point == input)
            return true;
    }
    return false;
}
std::string WormHole::showCell(Point){
    return "4";
}