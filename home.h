#include <vector>

#include "point.h"
#include "obstacle.h"

#ifndef HOME_H
#define HOME_H

class Home : public Obstacle {
    public:

        virtual std::string showCell(Point)const;

        virtual bool canCollision(const Point&)const;
        virtual const std::vector<Point> creatFromMap (Point,const std::vector<std::vector<int>>&);
        virtual const std::vector<Point> specialEffect(Point)const;

    private:
};
#endif