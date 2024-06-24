#include "point.h"

#include <vector>
#include <string>

#ifndef OBSTACLE_H
#define OBSTACLE_H

class Obstacle{
    public:
        Obstacle();
        virtual ~Obstacle();


        virtual std::string showCell(Point)const=0;
        virtual const std::vector<Point> specialEffect()=0;
        virtual const std::vector<Point> creatFromMap (Point,const std::vector<std::vector<int>>&)=0;

    protected:
        std::vector<Point>& getEntries();
        const std::vector<Point>& getEntries()const;

    private:
        std::vector<Point> entries;
};

#endif //OBSTACLE_H