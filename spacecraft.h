#include "point.h"

#include <unordered_map>
#include <vector>

#ifndef SPACECRAFT_H
#define SPACECRAFT_H

class Spacecraft{
    public:
        Spacecraft();

        Point getPoint();
        void setPoint(Point);
        void move(char);
        void moveTo(Point);

        const std::unordered_map<char,Point>& getMoveOptions();
    private:
        Point location;
        std::unordered_map<char,Point> moveOptions;

};

#endif //SPACECRAFT_H