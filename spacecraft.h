#include "point.h"

#include <unordered_map>
#include <vector>

#ifndef SPACECRAFT_H
#define SPACECRAFT_H

class Spacecraft{
    public:
        Spacecraft();
        Spacecraft(const Point&,int);

        void setPoint(const Point&);
        void setEnegy(int)  ; 

        const int&   getEnergy()const {return this->energy   ;}
        const Point& getPoint ()const {return this->location ;}
        const std::unordered_map<char,Point>& getMoveOptions()const;

        void moveTo(Point);

    private:
        int energy;
        Point location;
        const std::unordered_map<char,Point> moveOptions
        {{'a',{0,-1}} , {'d',{0,1}} , {'w',{-1,0}} , {'s',{1,0}}};

};

#endif //SPACECRAFT_H