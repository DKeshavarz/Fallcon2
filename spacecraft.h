#include "point.h"

#include <unordered_map>
#include <vector>

#ifndef SPACECRAFT_H
#define SPACECRAFT_H

class Spacecraft{
    public:
        Spacecraft();
        Spacecraft(Point,int);

        Point getPoint();
        void setPoint(Point);

        void move(char);
        void moveTo(Point);

        void setEnegy(int);
        int  getEnergy();

        const std::unordered_map<char,Point>& getMoveOptions();
    private:
        int energy;
        Point location;
        std::unordered_map<char,Point> moveOptions
        {{'a',{0,-1}} , {'d',{0,1}} , {'w',{-1,0}} , {'s',{1,0}}};

};

#endif //SPACECRAFT_H