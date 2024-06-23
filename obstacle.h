#include "point.h"

#include <vector>
#include <string>

#ifndef OBSTACLE_H
#define OBSTACLE_H

class Obstacle{
    public:
        Obstacle();
        virtual ~Obstacle();

        virtual std::string showCell(Point)=0;
        virtual const std::vector<Point> specialEffect()=0;
        virtual const std::vector<Point> creatFromMap (Point,std::vector<std::vector<int>>)=0;

    private:
};

#endif //OBSTACLE_H