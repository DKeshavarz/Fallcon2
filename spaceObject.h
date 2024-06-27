#include "obstacle.h"
#include "point.h"

#include <vector>
#include <string>

#ifndef SPACEOBJECT_H
#define SPACEOBJECT_H

class SpaceObject : public Obstacle{
    public:
        SpaceObject();
        virtual ~SpaceObject();

        virtual std::string showCell(Point)const;

        virtual bool canCollision(const Point&)const;
        virtual const std::vector<Point> creatFromMap (Point,const std::vector<std::vector<int>>&);
        virtual const std::vector<Point> specialEffect(Point)const;
    private:
        std::vector<Point> planet;
};


#endif // SPACEOBJECT_H